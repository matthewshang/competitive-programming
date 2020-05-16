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
const ll INF = 1e18;

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);

    int n, m; cin >> n >> m;
    vvi adj(n);
    vi indeg(n, 0);
    F0R (i, m) {
        int x, y; cin >> x >> y;
        adj[x - 1].pb(y - 1);
        indeg[y - 1]++;
    }

    vi dist(n, 0);
    queue<int> q;
    vb vis(n, false);
    F0R (i, n) if (indeg[i] == 0) {
        q.push(i);
    }

    while (!q.empty()) {
        int node = q.front(); q.pop();
        if (vis[node]) continue;
        vis[node] = true;
        for (int next : adj[node]) {
            indeg[next]--;
            if (indeg[next] == 0) {
                dist[next] = dist[node] + 1;
                q.push(next);
            }
        }
    }

    int ans = 0;
    F0R (i, n) {
        ans = max(ans, dist[i]);
    }
    cout << ans << endl;

    return 0;
}
