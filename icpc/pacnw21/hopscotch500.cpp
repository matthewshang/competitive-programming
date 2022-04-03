#include <bits/stdc++.h>
using namespace std;

/* Date: 2022-03-25
 * Source: PACNW 2022
 * Notes: Dijkstra fails because there can be O(n^4) edges. Use the fact that
 * the weight function separates row and col to get best edges in O(n).
 */

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;

    vector<vector<int>> x(n, vector<int>(n));
    vector<vector<array<int, 2>>> rev(n * n + 1);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> x[i][j];
            rev[x[i][j]].push_back({i, j});
        }
    }

    const int64_t INF = 1e12;
    vector<vector<int64_t>> dist(n, vector<int64_t>(n, INF));
    for (auto [i, j] : rev[1]) {
        dist[i][j] = 0;
    }
    for (int cur = 1; cur < k; cur++) {
        unordered_map<int, int64_t> row_pos;
        unordered_map<int, int64_t> col_pos;
        for (auto [i, j] : rev[cur]) {
            if (row_pos.find(i) == row_pos.end()) {
                row_pos[i] = dist[i][j];
            } else if (dist[i][j] < row_pos[i]) {
                row_pos[i] = dist[i][j];
            }

            if (col_pos.find(j) == col_pos.end()) {
                col_pos[j] = dist[i][j];
            } else if (dist[i][j] < col_pos[j]) {
                col_pos[j] = dist[i][j];
            }
        }

        for (auto [i, j] : rev[cur + 1]) {
            for (auto [row, cost] : row_pos) {
                dist[i][j] = min(dist[i][j], cost + (row - i) * (row - i));
            }
            for (auto [col, cost] : col_pos) {
                dist[i][j] = min(dist[i][j], cost + (col - j) * (col - j));
            }
        }
    }

    int64_t best = INF;
    for (auto [i, j] : rev[k]) {
        best = min(best, dist[i][j]);
    }

    if (best == INF) {
        cout << -1 << "\n";
    } else {
        cout << best << "\n";
    }

    return 0;
}