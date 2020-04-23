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
    function<pii(int)> dfs1 = [&](int u) -> pii {
        pii res = {0, u};
        vis[u] = true;
        for (int x : adj[u]) if (!vis[x]) {
            pii nxt = dfs1(x);
            if (nxt.f + 1 > res.f) {
                res.f = nxt.f + 1;
                res.s = nxt.s;
            }
        }
        return res;
    };
    int a = dfs1(1).s;
    F0R (i, n) vis[i + 1] = false;
    int b = dfs1(a).s;

    vpi dst(n + 1);
    dst[a] = {0, 0}; dst[b] = {0, 0};
    bool do_a = true;
    function<void(int, int)> dfs2 = [&](int u, int p) {
        for (int x : adj[u]) if (x != p) {
            if (do_a) dst[x].f = dst[u].f + 1;
            else dst[x].s = dst[u].s + 1;
            dfs2(x, u);
        }
    };
    dfs2(a, 0);
    do_a = false;
    dfs2(b, 0);

    FOR (i, 1, n) cout << max(dst[i].f, dst[i].s) << " ";
    cout << endl;

    return 0;
}


