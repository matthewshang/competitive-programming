#include "bits/stdc++.h"

using namespace std;

using ll = long long;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    int n, k; cin >> n >> k;
    
    bool cell[n][n];
    for (int i = 0; i < n; i++) {
        string line; cin >> line;
        for (int j = 0; j < n; j++) {
            cell[i][j] = (line[j] == 'B');
        }
    }

    bool row[n][n - k + 1], col[n - k + 1][n];
    for (int i = 0; i < n; i++) {
        int tx = 0, ty = 0;
        for (int j = 0; j < n; j++) tx += cell[i][j], ty += cell[j][i];
        bool gx = tx != 0, gy = ty != 0;
        int vx = 0, vy = 0;
        for (int j = 0; j < k; j++) vx += cell[i][j], vy += cell[j][i];
        for (int j = 0; j < n - k + 1; j++) {
            row[i][j] = ((tx - vx) == 0) & gx;
            col[j][i] = ((ty - vy) == 0) & gy;
            if (j != n - k) {
                vx += cell[i][j + k] - cell[i][j];
                vy += cell[j + k][i] - cell[j][i];
            }
        }
    }

    int sumx[n - k + 1][n - k + 1], sumy[n - k + 1][n - k + 1];
    for (int i = 0; i < n - k + 1; i++) {
        int vx = 0, vy = 0;
        for (int j = 0; j < k; j++) vx += row[j][i], vy += col[i][j];
        for (int j = 0; j < n - k + 1; j++) {
            sumx[j][i] = vx; sumy[i][j] = vy;
            if (j != n - k) {
                vx += row[j + k][i] - row[j][i];
                vy += col[i][j + k] - col[i][j];
            }
        }
    }

    pair<int, int> pos = {0, 0};
    int ans = 0;
    for (int i = 0; i < n - k + 1; i++) {
        for (int j = 0; j < n - k + 1; j++) {
            int val = sumx[i][j] + sumy[i][j];
            if (val > ans) {
                ans = val;
                pos = {i, j};
            }
        }
    }

    for (int i = pos.first; i < pos.first + k; i++) {
        for (int j = pos.second; j < pos.second + k; j++) {
            cell[i][j] = false;
        }
    }

    int answer = 0;
    for (int i = 0; i < n; i++) {
        int vx = 0, vy = 0;
        for (int j = 0; j < n; j++) {
            vx += cell[i][j];
            vy += cell[j][i];
        }
        answer += (vx == 0) + (vy == 0);
    }
    cout << answer << endl;

    // for (int i = 0; i < n; i++) {
    //     for (int j = 0; j < n; j++) cout << cell[i][j];
    //     cout << endl;
    // }

    // for (int i = 0; i < n - k + 1; i++) {
    //     for (int j = 0; j < n - k + 1; j++) cout << sumx[i][j] << " ";
    //     cout << endl;
    // }

    // for (int i = 0; i < n - k + 1; i++) {
    //     for (int j = 0; j < n - k + 1; j++) cout << sumy[i][j] << " ";
    //     cout << endl;
    // }


    return 0;
}
