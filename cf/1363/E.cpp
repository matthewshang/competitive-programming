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

    int n; cin >> n;
    vector<array<int, 3>> node(n);
    F0R (i, n)
        cin >> node[i][0] >> node[i][1] >> node[i][2];
    vvi adj(n);
    F0R (i, n - 1) {
        int u, v; cin >> u >> v;
        adj[u - 1].pb(v - 1);
        adj[v - 1].pb(u - 1);
    }

    int want0 = 0, want1 = 0;
    F0R (i, n) {
        if (node[i][1] == 0 && node[i][2] == 1)
            want1++;
        else if (node[i][1] == 1 && node[i][2] == 0)
            want0++;
    }
    if (want0 != want1) {
        cout << "-1\n";
        return 0;
    }

    vpi sub(n);
    function<pii(int, int)> Dfs0 = [&](int u, int p) -> pii {
        pii res = { node[u][1] == 1 && node[u][2] == 0, node[u][1] == 0 && node[u][2] == 1 };
        for (int x : adj[u]) if (x != p) {
            pii tmp = Dfs0(x, u);
            res.F += tmp.F;
            res.S += tmp.S;
        }
        sub[u] = res;
        return res;
    };
    Dfs0(0, -1);

    ll best = (ll)node[0][0] * (want0 + want1);
    function<void(int, int, int)> Dfs = [&](int u, int p, int last) {
        if (sub[u].F == 0 || sub[u].S == 0) 
            return;
        int can = min(sub[u].F, sub[u].S);
        if (node[u][0] < node[last][0]) {
            best = best + 2 * can * ((ll)(node[u][0] - node[last][0]));
            for (int x : adj[u]) if (x != p)
                Dfs(x, u, u);
        } else {
            for (int x : adj[u]) if (x != p)
                Dfs(x, u, last);
        }
    };
    for (int x : adj[0])
        Dfs(x, 0, 0);
    cout << best << endl;

    return 0;
}
