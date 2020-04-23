#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using vi = vector<int>;
using vvi = vector<vector<int>>;
using vll = vector<long long>;
using pii = pair<int, int>;
using vpi = vector<pair<int, int>>;

#define F first
#define S second
#define pb push_back
#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()

#define FOR(i, a, b) for (int i=(a); i <=(b); i++)
#define F0R(i, a) for (int i=0; i < (a); i++)
#define RFOR(i, a, b) for (int i = (a); i >= b; i--)

const char nl = '\n';
const ll MOD = 1e9 + 7;
const ll INF = 1e18;

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);

    int n, k; cin >> n >> k;
    vvi adj(n);
    F0R (i, n - 1) {
        int a, b; cin >> a >> b;
        a--; b--;
        adj[a].pb(b); adj[b].pb(a);
    }

    vi dist(n), sub(n, 0), dist2(n);
    dist[0] = 0;
    function<int(int, int)> dfs1 = [&](int u, int p) -> int {
        for (int x : adj[u]) if (x != p) {
            dist[x] = dist[u] + 1;
            sub[u] += dfs1(x, u);
        }
        return sub[u] + 1;
    };
    function<void(int, int)> dfs2 = [&](int u, int p) {
        dist2[u] = dist[u] - sub[u];
        for (int x : adj[u]) if (x != p) {
            dfs2(x, u);
        }
    };
    dfs1(0, -1);
    dfs2(0, -1);
    sort(all(dist2));
    ll ans = 0;
    F0R (i, k) ans += dist2[n - 1 - i];
    cout << ans << nl;

    return 0;
}