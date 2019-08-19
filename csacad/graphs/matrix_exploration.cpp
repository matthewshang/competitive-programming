#include "bits/stdc++.h"

using namespace std;

using ll = long long;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    int n, m, k; cin >> n >> m >> k;
    vector<string> mat(n);
    for (auto& x : mat) cin >> x;
    vector<pair<int, int>> spec(k);
    for (auto& x : spec) cin >> x.first >> x.second;

    const int INF = 1 << 20;
    int dist[n][m];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            dist[i][j] = INF;

    queue<pair<int, int>> q;
    for (auto& x : spec) {
        dist[x.first - 1][x.second - 1] = 0;
        q.emplace(x.first - 1, x.second - 1);
    }

    const int DR[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    while (!q.empty()) {
        auto [x, y] = q.front(); q.pop();

        for (int k = 0; k < 4; k++) {
            int u = x + DR[k][0], v = y + DR[k][1];
            if (u < 0 || u >= n || v < 0 || v >= m) continue;
            if (mat[u][v] == '#') continue;
            if (dist[u][v] != INF) continue;

            dist[u][v] = dist[x][y] + 1;
            q.emplace(u, v);
        }
    }

    int ans = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (dist[i][j] != INF) ans += dist[i][j];
    cout << ans << endl;

    return 0;
}
