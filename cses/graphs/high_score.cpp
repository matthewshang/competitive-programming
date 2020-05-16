#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using vi = vector<int>;
using vb = vector<bool>;
using vvi = vector<vector<int>>;
using vll = vector<long long>;
using pii = pair<int, int>;
using pll = pair<long long, long long>;
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

    int n, m; cin >> n >> m;
    vector<array<int, 3>> edges(m);
    vvi radj(n + 1);
    F0R (i, m) {
        int a, b, x; cin >> a >> b >> x;
        edges[i] = {a, b, -x};
        radj[b].pb(a);
    }

    vll dist(n + 1, INF);
    dist[1] = 0;
    F0R (i, n - 1) {
        for (auto [u, v, w] : edges) {
            if (dist[u] != INF && dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
            }
        }
    }

    vb reach(n + 1, false);
    vb vis(n + 1, false);
    function<void(int)> Dfs = [&](int u) {
        vis[u] = true;
        reach[u] = true;
        for (int x : radj[u]) {
            if (!vis[x]) Dfs(x);
        }
    };
    Dfs(n);

    for (auto [u, v, w] : edges) {
        if (dist[u] != INF && dist[u] + w < dist[v] && reach[u]) {
            cout << "-1\n";
            return 0;
        }
    }

    cout << (-dist[n]) << endl;

    return 0;
}
