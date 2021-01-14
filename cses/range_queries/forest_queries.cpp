#include "bits/stdc++.h"

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q; cin >> n >> q;
    vector<vector<int>> pre(n + 1, vector<int>(n + 1));
    for (int i = 0; i < n; i++) {
        string l; cin >> l;
        for (int j = 0; j < n; j++) {
            pre[i + 1][j + 1] = (l[j] == '*') + pre[i + 1][j] + pre[i][j + 1] - pre[i][j];
        }
    }

    while (q--) {
        int y1, x1, y2, x2;
        cin >> y1 >> x1 >> y2 >> x2;
        cout << (pre[y2][x2] - pre[y2][x1 - 1] - pre[y1 - 1][x2] + pre[y1 - 1][x1 - 1]) << '\n';
    }
}