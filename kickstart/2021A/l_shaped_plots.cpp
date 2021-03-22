#include "bits/stdc++.h"

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T; cin >> T;
    for (int tc = 1; tc <= T; tc++) {
        int N, M; cin >> N >> M;
        vector<vector<int>> g(N, vector<int>(M));
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                cin >> g[i][j];
            }
        }

        vector<vector<int>> U(N, vector<int>(M));
        vector<vector<int>> D(N, vector<int>(M));
        vector<vector<int>> R(N, vector<int>(M));
        vector<vector<int>> L(N, vector<int>(M));
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                D[i][j] = g[i][j];
                if (i != 0 && g[i][j] != 0) {
                    D[i][j] += D[i - 1][j];
                }
                L[i][j] = g[i][j];
                if (j != 0 && g[i][j] != 0) {
                    L[i][j] += L[i][j - 1];
                }
            }
        }

        for (int i = N - 1; i >= 0; i--) {
            for (int j = M - 1; j >= 0; j--) {
                U[i][j] = g[i][j];
                if (i != N - 1 && g[i][j] != 0) {
                    U[i][j] += U[i + 1][j];
                }
                R[i][j] = g[i][j];
                if (j != M - 1 && g[i][j] != 0) {
                    R[i][j] += R[i][j + 1];
                }
            }
        }

        int ans = 0;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                if (g[i][j]) {
                    if (U[i][j] > 1 && R[i][j] > 1)
                        ans += min(U[i][j] / 2, R[i][j]) + min(U[i][j], R[i][j] / 2) - 2;
                    if (U[i][j] > 1 && L[i][j] > 1)
                        ans += min(U[i][j] / 2, L[i][j]) + min(U[i][j], L[i][j] / 2) - 2;
                    if (D[i][j] > 1 && R[i][j] > 1)
                        ans += min(D[i][j] / 2, R[i][j]) + min(D[i][j], R[i][j] / 2) - 2;
                    if (D[i][j] > 1 && L[i][j] > 1)
                        ans += min(D[i][j] / 2, L[i][j]) + min(D[i][j], L[i][j] / 2) - 2;
                }
            }
        }
        cout << "Case #" << tc << ": " << ans << '\n';
    }

    return 0;
}