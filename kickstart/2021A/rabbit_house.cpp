#include "bits/stdc++.h"

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T; cin >> T;
    for (int tc = 1; tc <= T; tc++) {
        int R, C; cin >> R >> C;
        vector<vector<int>> G(R, vector<int>(C));
        priority_queue<array<int, 3>> q;
        for (int i = 0; i < R; i++) {
            for (int j = 0; j < C; j++) {
                cin >> G[i][j];
                q.push({ G[i][j], i, j });
            }
        }

        vector<vector<int>> vis(R, vector<int>(C));
        long long ans = 0;
        while (!q.empty()) {
            auto [h, i, j] = q.top();
            q.pop();
            if (i < 0 || i >= R || j < 0 || j >= C || h <= vis[i][j]) {
                continue;
            }
            vis[i][j] = h;
            if (h > G[i][j]) {
                ans += h - G[i][j];
                G[i][j] = h;
            }
            q.push({ h - 1, i - 1, j });
            q.push({ h - 1, i + 1, j });
            q.push({ h - 1, i, j - 1 });
            q.push({ h - 1, i, j + 1 });
        }

        cout << "Case #" << tc << ": " << ans << '\n';
    }

    return 0;
}