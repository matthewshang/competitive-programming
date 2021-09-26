#include <bits/stdc++.h>
using namespace std;

/* Date: 2021-09-25
 * Source: FB Hacker Cup 2021 R2
 * Summary: Observe that
 * - we might as well do all removals after shifts.
 * - either shift 0+ up or 0+ down, but we don't need to combine up/down shifts.
 * - every column acts independently.
 * From this, just try all possible shifts and precompute when/how many cells 
 * need to be removed.
 */

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    for (int tc = 1; tc <= T; tc++) {
        int R, C, K;
        cin >> R >> C >> K;
        vector<string> g(R);
        for (int r = 0; r < R; r++) {
            cin >> g[r];
        }

        vector<int> up(K);
        for (int c = 0; c < C; c++) {
            int spaces = 0;
            int r = 0;
            while (r < K - 1) {
                if (g[r][c] == '.') {
                    spaces++;
                }
                r++;
            }
            char cur = g[r][c];
            for (int u = 0; u < K; u++) {
                if (cur == 'X') {
                    up[u]++;
                }
                if (cur == '.') {
                    spaces++;
                }
                if (spaces > 0) {
                    r++;
                    spaces--;
                }
                if (r < R) {
                    cur = g[r][c];
                } else {
                    cur = '.';
                }
            }
        }

        vector<int> down(R - K + 1);
        for (int c = 0; c < C; c++) {
            int spaces = 0;
            int r = R - 1;
            while (r > K - 1) {
                if (g[r][c] == '.') {
                    spaces++;
                }
                r--;
            }
            char cur = g[r][c];
            for (int d = 0; d < R - K + 1; d++) {
                if (cur == 'X') {
                    down[d]++;
                }
                if (cur == '.') {
                    spaces++;
                }
                if (spaces > 0) {
                    r--;
                    spaces--;
                }
                if (r >= 0) {
                    cur = g[r][c];
                } else {
                    cur = '.';
                }
            }
        }

        int moves = C;
        for (int u = 0; u < K; u++) {
            moves = min(moves, up[u] + u);
        }
        for (int d = 0; d < R - K + 1; d++) {
            moves = min(moves, down[d] + d);
        }
        cout << "Case #" << tc << ": " << moves << '\n';
    }

    return 0;
}