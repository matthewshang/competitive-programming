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

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);

    int n, m; cin >> n >> m;
    int n1, n2, n3; cin >> n1 >> n2 >> n3;

    vvi adj(n);
    F0R (i, m) {
        int u, v; cin >> u >> v;
        u--; v--;
        adj[u].pb(v);
        adj[v].pb(u);
    }

    vi vis(n, 0);
    function<pii(int, int)> Dfs1 = [&](int u, int color) -> pii {
        vis[u] = color;
        pii count = { color == 1, color == 2 };
        for (int x : adj[u]) {
            if (vis[x] == color) {
                cout << "NO" << nl;
                exit(0);
            } else if (vis[x] == 0) {
                pii res = Dfs1(x, color == 1 ? 2 : 1);
                count.F += res.F;
                count.S += res.S;
            }
        }
        return count;
    };

    vpi comp;
    vi roots;
    F0R (i, n) {
        if (vis[i] == 0) {
            comp.pb(Dfs1(i, 1));
            roots.pb(i);
        }
    }

    int C = sz(comp);
    vector<vector<pair<bool, bool>>> dp(C, vector<pair<bool, bool>>(n2 + 1, { false, false }));
    if (comp[0].F <= n2)
        dp[0][comp[0].F].F = true;
    if (comp[0].S <= n2)
        dp[0][comp[0].S].S = true;
    FOR (i, 1, C - 1) {
        F0R (j, n2 + 1) {
            if (comp[i].F <= j) {
                auto p = dp[i - 1][j - comp[i].F];
                if (p.F || p.S)
                    dp[i][j].F = true;
            }
            if (comp[i].S <= j) {
                auto p = dp[i - 1][j - comp[i].S];
                if (p.F || p.S)
                    dp[i][j].S = true;
            }
        }
    }
    if (!dp[C - 1][n2].F && !dp[C - 1][n2].S) {
        cout << "NO" << nl;
        return 0;
    }

    vi ans(n);
    function<void(int, int)> Dfs2 = [&](int u, int c) {
        if (c == 1) {
            if (n1 > 0) {
                ans[u] = 1;
                n1--;
            } else {
                ans[u] = 3;
            }
        } else {
            ans[u] = 2;
        }
        for (int x : adj[u]) {
            if (ans[x] == 0) 
                Dfs2(x, c == 1 ? 2 : 1);
        }
    };

    int current = n2;
    RFOR (i, C - 1, 0) {
        int color;
        if (dp[i][current].F) {
            color = 2;
            current -= comp[i].F;
        } else {
            color = 1;
            current -= comp[i].S;
        }
        Dfs2(roots[i], color);
    }

    cout << "YES" << nl;
    F0R (i, n)
        cout << ans[i];
    cout << nl;

    return 0;
}
