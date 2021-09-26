#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int T;
    cin >> T;
    for (int tc = 1; tc <= T; tc++) {
        int n, m, a, b;
        cin >> n >> m >> a >> b;
        if (min(a, b) < n + m - 1) {
            cout << "Case #" << tc << ": Impossible\n";
            continue;
        }
        
        vector<vector<int>> g(n, vector<int>(m, 1000));
        g[0][0] = a - (n + m - 2);
        g[0][m - 1] = b - (n + m - 2);
        for (int i = 1; i < n - 1; i++) {
            g[i][0] = g[i][m - 1] = 1;
        }
        for (int j = 0; j < m; j++) {
            g[n - 1][j] = 1;
        }

        cout << "Case #" << tc << ": Possible\n";
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cout << g[i][j] << " ";
            }
            cout << '\n';
        }
    }

    return 0;
}