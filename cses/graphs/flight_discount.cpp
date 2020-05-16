#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using vi = vector<int>;
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

using pli = pair<long long, int>;

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);

    int n, m; cin >> n >> m;
    vector<vpi> adj(2 * n + 10);
    // +0 = 0 used, +n = 1 used
    F0R (i, m) {
        int a, b, c; cin >> a >> b >> c;
        adj[a].pb({b, c});
        adj[a].pb({b + n, c / 2});
        adj[a + n].pb({b + n, c});
    }

    vll dist(2 * n + 10, INF);
    priority_queue<pli, vector<pli>, greater<pli>> pq;
    dist[1] = 0;
    pq.push({0, 1});
    while (!pq.empty()) {
        auto [d, u] = pq.top(); pq.pop();
        if (dist[u] < d) continue;
        for (auto [x, w] : adj[u]) {
            if (dist[u] + w < dist[x]) {
                dist[x] = dist[u] + w;
                pq.push({dist[x], x});
            }
        }
    }
    cout << min(dist[n], dist[2 * n]) << endl;

    return 0;
}