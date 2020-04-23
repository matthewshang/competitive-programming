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

    vector<ll> sub(n + 1, 0), down(n + 1, 0);
    function<ll(int, int)> dfs1 = [&](int u, int p) -> ll {
        ll res = 0;
        for (int x : adj[u]) if (x != p) {
            res += 1 + dfs1(x, u);
            sub[u] += 1 + sub[x];
        }
        return sub[u] + (down[u] = res);
    };
    dfs1(1, 0);

    vector<ll> up(n + 1, 0), ans(n + 1, 0);
    down[0] = down[1] + n;
    function<void(int, int)> dfs2 = [&](int u, int p) {
        // up_u + down_p not including u's subtree + move all not in subtree of u
        up[u] = up[p] + (down[p] - down[u] - (sub[u] + 1)) + (n - (sub[u] + 1));
        ans[u] = up[u] + down[u];
        for (int x : adj[u]) if (x != p) dfs2(x, u);
    };
    dfs2(1, 0);

    FOR (i, 1, n) cout << ans[i] << " ";
    cout << endl;

    return 0;
}


