#include <bits/stdc++.h>
using namespace std;

const array<int, 2> Piece[4][2] = {
    {{1, 0}, {0, 1}}, {{1, 0}, {0, -1}}, {{-1, 0}, {0, 1}}, {{-1, 0}, {0, -1}}
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    auto answer = [&](int x) {
        cout << x << '\n';
        exit(0);
    };

    int n;
    cin >> n;
    const int m = 1 << n;
    const int T = ((1 << (2 * n)) - 1) / 3;

    vector<vector<int>> g(m, vector<int>(m));
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < m; j++) {
            cin >> g[i][j];
        }
    }

    vector<vector<bool>> vis(m, vector<bool>(m, false));
    auto out = [&](int r, int c) -> bool {
        return r < 0 || r >= m || c < 0 || c >= m;
    };
    function<int(int, int, int)> fill = [&](int r, int c, int col) -> int {
        if (out(r, c) || vis[r][c] || g[r][c] != col) return 0;
        vis[r][c] = true;
        return 1 + fill(r + 1, c, col) + fill(r - 1, c, col) + fill(r, c + 1, col) + fill(r, c - 1, col);
    };
    auto can_place = [&](int r, int c, int col) -> bool {
        if (out(r, c)) return false;
        if (g[r][c] != col) return false;
        for (int k = 0; k < 4; k++) {
            bool ok = true;
            for (int d = 0; d < 2; d++) {
                int rr = r + Piece[k][d][0];
                int cc = c + Piece[k][d][1];
                if (out(rr, cc)) {
                    ok = false;
                    break;
                }
                if (g[rr][cc] != col) ok = false;
            }
            if (ok) return true;
        }
        return false;
    };

    vector<bool> seen(T + 1);
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < m; j++) {
            if (seen[g[i][j]]) {
                if (!vis[i][j]) {
                    answer(0);
                } else {
                    continue;
                }
            }
            seen[g[i][j]] = true;
            if (g[i][j] == 0) {
                vis[i][j] = true;
                continue;
            }

            int count = fill(i, j, g[i][j]);
            if (count != 3) answer(0);
            bool ok = false;
            for (int dx = -1; dx <= 1; dx++) {
                for (int dy = -1; dy <= 1; dy++) {
                    if (!out(i + dx, j + dy) && can_place(i + dx, j + dy, g[i][j])) {
                        ok = true;
                        break;
                    }
                }
            }

            if (!ok) answer(0);
        }
    }

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < m; j++) {
            if (!vis[i][j]) answer(0);
        }
    }

    for (int t = 0; t <= T; t++) {
        if (!seen[t]) answer(0);
    }
    answer(1);

    return 0;
}