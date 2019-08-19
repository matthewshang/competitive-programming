#include "bits/stdc++.h"

using namespace std;

using ll = long long;

const int MX = 100010;
const int INF = 1<<20;

int n, m, s, a, b;
vector<int> adj[MX];

void shortest(int* dist, int start) {
    for (int i = 1; i <= n; i++) dist[i] = INF;
    dist[start] = 0;
    queue<int> q({start});
    while (!q.empty()) {
        int u = q.front(); q.pop();

        for (int x : adj[u]) {
            if (dist[x] != INF) continue;
            dist[x] = dist[u] + 1;
            q.emplace(x);
        }
    }
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> n >> m >> s >> a >> b;
    for (int i = 0; i < m; i++) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int ds[n], da[n], db[n];
    shortest(ds, s);
    shortest(da, a);
    shortest(db, b);

    int A = ds[a], B = ds[b];
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        int x = ds[i] + da[i], y = ds[i] + db[i];
        if (x == A && y == B) {
            ans = max(ans, ds[i]);
        }
    }
    cout << ans << endl;

    return 0;
}
