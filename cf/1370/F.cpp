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

void solve() {
    const auto query = [&](vi& q) -> pii {
        cout << "? " << sz(q);
        for (int x : q)
            cout << " " << x;
        cout << endl;
        pii res;
        cin >> res.F >> res.S;
        if (res.F == -1)
            exit(0);
        return res;
    };

    const auto answer = [&](int a, int b) -> void {
        cout << "! " << a << " " << b << endl;
        string res;
        cin >> res;
        if (res == "Incorrect")
            exit(0);
    };

    int n; cin >> n;
    vvi adj(n + 1);
    F0R (i, n - 1) {
        int u, v; cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }

    if (n == 2) {
        answer(1, 2);
        return;
    }

    vi al(n);
    iota(begin(al), end(al), 1);
    auto [root, L] = query(al);

    vi depth(n + 1);
    vi par(n + 1);
    int max_depth = 0;
    depth[0] = -1;
    y_combinator([&](auto self, int u, int p) -> void {
        par[u] = p;
        depth[u] = depth[p] + 1; 
        max_depth = max(max_depth, depth[u]);
        for (int to : adj[u]) if (to != p) self(to, u);
    })(root, 0);    

    int lo = (L + 1) / 2 - 1;
    int hi = min(L, max_depth);
    int A = -1;
    if (lo == hi) {
        al.clear();
        FOR (i, 1, n) {
            if (depth[i] == lo)
                al.pb(i);
        }
        auto [x, d] = query(al);
        A = x;
    }

    while (lo < hi) {
        int mid = lo + (hi - lo + 1) / 2;
        al.clear();
        FOR (i, 1, n) {
            if (depth[i] == mid)
                al.pb(i);
        }
        auto [x, d] = query(al);
        if (d == L) {
            A = x;
            lo = mid;
        } else {
            hi = mid - 1;
        }
    }

    if (lo == L) {
        answer(A, root);
    } else {
        int ex = A;
        while (ex != 0 && depth[ex] != L - lo) {
            ex = par[ex];
        }

        al.clear();
        FOR (i, 1, n) {
            if (i != A && i != ex && depth[i] == L - lo)
                al.pb(i);
        }
        auto [B, _] = query(al);
        answer(A, B);
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);

    int t; cin >> t;
    while (t--) solve();
    return 0;
}
