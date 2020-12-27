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

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    
    int n, m; cin >> n >> m;
    vvi adj(n + 1);
    F0R (i, m) {
        int a, b; cin >> a >> b;
        adj[a].pb(b);
    }

    vi dist(n + 1, 0);
    vi vis(n + 1, -1);
    bool can_reach = y_combinator([&](auto self, int v) -> bool {
        if (vis[v] != -1) return vis[v];
        bool any_ok = (v == n);
        for (int to : adj[v]) {
            bool ok = self(to);
            if (ok) {
                dist[v] = max(dist[v], 1 + dist[to]);
                any_ok = ok;
            }
        }
        vis[v] = any_ok;
        return any_ok;
    })(1);

    if (!can_reach) {
        cout << "IMPOSSIBLE" << nl;
        return 0;
    }

    vi prev(n + 1, -1);
    fill(all(vis), 0);
    y_combinator([&](auto self, int v, int p, int d) -> void {
        if (vis[v]) return;
        vis[v] = 1;
        prev[v] = p;
        for (int to : adj[v]) if (dist[to] == d - 1) {
            self(to, v, d - 1);
        }
    })(1, -1, dist[1]); 

    vi route;
    int cur = n;
    while (cur != -1) {
        route.pb(cur);
        cur = prev[cur];
    }
    reverse(all(route));
    
    if (route[0] == 1) {
        cout << sz(route) << nl;
        for (int stop : route) cout << stop << " ";
        cout << nl;
    } else {
        cout << "IMPOSSIBLE" << nl;
    }

    return 0;
}

