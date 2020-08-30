#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using vi = vector<int>;
using vb = vector<bool>;
using vvi = vector<vector<int>>;
using vll = vector<long long>;
using vpi = vector<pair<int, int>>;
using pii = pair<int, int>;
using pll = pair<long long, long long>;

#define F first
#define S second
#define pb push_back
#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()

#define FOR(i, a, b) for (int i = (a); i <= (b); ++i)
#define F0R(i, a) for (int i = 0; i < (a); ++i)
#define RFOR(i, a, b) for (int i = (a); i >= (b); --i)

const char nl = '\n';
const ll MOD = 1e9 + 7;

const ll INF = 1e17;

template<class Fun>
class y_combinator_result {
    Fun fun_;
public:
    template<class T>
    explicit y_combinator_result(T &&fun): fun_(std::forward<T>(fun)) {}

    template<class ...Args>
    decltype(auto) operator()(Args &&...args) {
        return fun_(std::ref(*this), std::forward<Args>(args)...);
    }
};

template<class Fun>
decltype(auto) y_combinator(Fun &&fun) {
    return y_combinator_result<std::decay_t<Fun>>(std::forward<Fun>(fun));
}

// Source: Based on KACTL and bqi343
struct Seg {
    const ll ID = INF;
    ll f(ll a, ll b) { return min(a, b); } // f should be associative
    vector<ll> seg; int n;
    Seg(int _n) { n = _n; seg.assign(2 * n, ID); }
    void update(int pos, ll val) {
        seg[pos += n] = val;
        for (pos /= 2; pos; pos /= 2) 
            seg[pos] = f(seg[2 * pos], seg[2 * pos + 1]);
    }
    ll query(int l, int r) { // interval [l, r]
        ll ra = ID, rb = ID;
        for (l += n, r += n + 1; l < r; l /= 2, r /= 2) {
            if (l & 1) ra = f(ra, seg[l++]);
            if (r & 1) rb = f(seg[--r], rb);
        }
        return f(ra, rb);
    }
};

void solve(int tt) {
    int n, m, a, b; cin >> n >> m >> a >> b;
    a--; b--;

    vvi adj(n);
    vll c(n);
    F0R (i, n) {
        int p; cin >> p >> c[i];
        if (i != 0) {
            adj[i].pb(p - 1);
            adj[p - 1].pb(i);
        }
    }

    vi depth(n);
    vi prev(n);
    prev[a] = -1;
    depth[a] = 0;
    {
        queue<int> q({ a });
        while (sz(q)) {
            int node = q.front(); q.pop();
            for (int to : adj[node]) {
                if (to == prev[node]) continue;
                prev[to] = node;
                depth[to] = depth[node] + 1;
                q.push(to);
            }
        }
    }

    vi path(n + 1, -1);
    {
        int node = b;
        while (node != -1) {
            int d = depth[node];
            path[d] = node;
            node = prev[node];
        }
    }

    vi real_depth(n);
    {
        real_depth[a] = 0;
        queue<int> q({ a });
        while (sz(q)) {
            int node = q.front(); q.pop();
            if (node == b) continue;
            int d = depth[node];
            int next = path[d + 1];
            for (int to : adj[node]) {
                if (to == prev[node]) continue;
                if (to == next) {
                    real_depth[to] = real_depth[node] + 1;
                } else {
                    real_depth[to] = real_depth[node] - 1;
                }
                q.push(to);
            }
        }
    }

    c[a] = 0;
    Seg seg(n + 1);
    seg.update(depth[b], 0);
    auto dfs = y_combinator([&](auto self, int node, int min_depth) -> void {
        int cur_real = real_depth[node];
        int cur_depth = depth[node];
        int lo = max(cur_real + 1, min_depth);
        int hi = min(cur_real + m, n);
        ll cost_next = seg.query(lo, hi);
        ll cost_cur = c[node] == 0 ? INF : c[node];
        ll cost = cost_cur + cost_next;

        if (seg.query(cur_depth, cur_depth) > cost) {
            seg.update(cur_depth, cost);
        }

        for (int to : adj[node]) {
            if (to == prev[node]) continue;
            self(to, min_depth);
        }
    });

    auto path_dfs = y_combinator([&](auto self, int node) -> void {
        if (node == b) return;

        int cur_depth = depth[node];
        int next_in = path[cur_depth + 1];
        self(next_in);

        int lo = cur_depth + 1;
        int hi = min(cur_depth + m, n);
        ll cost_next = seg.query(lo, hi);
        ll cost_cur = INF;
        if (node == a) {
            cost_cur = 0;
        } else if (c[node] != 0) {
            cost_cur = c[node];
        }
        seg.update(cur_depth, cost_cur + cost_next);

        for (int to : adj[node]) {
            if (to == prev[node] || to == next_in) continue;
            dfs(to, cur_depth);
        }
    });
    path_dfs(a);

    ll ans = seg.query(0, min(m, n));
    cout << "Case #" << tt << ": ";
    cout << (ans == INF ? -1 : ans) << nl;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);

    int T; cin >> T;
    FOR (tt, 1, T) {
        solve(tt);
    }
    return 0;
}
