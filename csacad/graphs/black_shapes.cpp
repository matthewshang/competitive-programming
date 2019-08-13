#include "bits/stdc++.h"

using namespace std;

using ll = long long;

const int MX = 1000;
const int DR[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

int n, m;
bool cell[MX][MX];
int sz[MX][MX];
int col[MX][MX];

int count(int i, int j) {
    if (i < 0 || i >= n || j < 0 || j >= m) return 0;
    if (!cell[i][j] || sz[i][j] == -1) return 0;

    sz[i][j] = -1;
    int val = 1;
    for (int k = 0; k < 4; k++) val += count(i + DR[k][0], j + DR[k][1]);
    return val;
}

void fill(int i, int j, int c, int idx) {
    if (i < 0 || i >= n || j < 0 || j >= m) return;
    if (sz[i][j] != -1) return;

    sz[i][j] = c;
    col[i][j] = idx;
    for (int k = 0; k < 4; k++)
        fill(i + DR[k][0], j + DR[k][1], c, idx);
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> n >> m;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> cell[i][j];

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            sz[i][j] = col[i][j] = 0;

    int idx = 1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (sz[i][j] != 0) continue;
            int c = count(i, j);
            fill(i, j, c, idx);
            idx++;
        }
    }

    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (cell[i][j]) continue;
            set<int> used;
            int val = 0;
            for (int k = 0; k < 4; k++) {
                int x = i + DR[k][0], y = j + DR[k][1];
                if (x < 0 || x >= n || y < 0 || y >= m) continue;
                int color = col[x][y];
                if (used.find(color) != used.end()) continue;
                used.insert(color);
                val += sz[x][y];
            }
            ans = max(ans, val + 1);
        }
    }
    cout << ans << endl;

    return 0;
}
