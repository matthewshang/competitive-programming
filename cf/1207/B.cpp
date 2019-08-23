#include "bits/stdc++.h"

using namespace std;

using ll = long long;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    int n, m; cin >> n >> m;
    bool mat[n][m];
    bool cover[n][m];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> mat[i][j];

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cover[i][j] = false;

    vector<pair<int, int>> ans;
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < m - 1; j++) {
            if (mat[i][j] && mat[i + 1][j] && mat[i][j + 1] && mat[i + 1][j + 1]) {
                ans.emplace_back(i + 1, j + 1);
                cover[i][j] = cover[i + 1][j] = cover[i][j + 1] = cover[i + 1][j + 1] = true;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (mat[i][j] && !cover[i][j]) {
                cout << "-1\n";
                return 0;
            }
        }
    }

    cout << ans.size() << endl;
    for (auto [x, y] : ans) cout << x << " " << y << endl;

    return 0;
}
