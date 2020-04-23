#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using vi = vector<int>;
using vvi = vector<vector<int>>;
using pii = pair<int, int>;
using vpi = vector<pair<int, int>>;

#define f first
#define s second
#define pb push_back
#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()

#define FOR(i, a, b) for (int i=(a); i <=(b); i++)
#define F0R(i, a) for (int i=0; i < (a); i++)
#define RFOR(i, a, b) for (int i = (a); i >= b; i--)

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    int n; cin >> n;
    vvi adj(n + 1);
    F0R (i, n - 1) {
        int a, b; cin >> a >> b;
        adj[a].pb(b); adj[b].pb(a);
    }

    vector<bool> vis(n + 1, false);
    function<pii(int)> dfs = [&](int u) -> pii {
        pii res = {0, u};
        vis[u] = true;
        for (int x : adj[u]) if (!vis[x]) {
            pii nxt = dfs(x);
            if (nxt.f + 1 > res.f) {
                res.f = nxt.f + 1;
                res.s = nxt.s;
            }
        }
        return res;
    };

    int x = dfs(1).s;
    F0R (i, n) vis[i + 1] = false;
    int dia = dfs(x).f;
    cout << dia << endl;

    return 0;
}

