#include "bits/stdc++.h"

using namespace std;

using ll = long long;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int Q; cin >> Q;
    for (int qq = 0; qq < Q; qq++) {
        int n, m; cin >> n >> m;
        vector<string> grid(n);
        for (int i = 0; i < n; i++) cin >> grid[i];

        vector<int> x(m, 0), y(n, 0);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == '.') {
                    x[j]++; y[i]++;
                }
            }
        }
        int ans = 10000000;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                int here = y[i] + x[j];
                if (grid[i][j] == '.') here--;
                ans = min(ans, here);
            }
        }
        cout << ans << endl;
        // int mx = 100000, my = 100000;
        // int px = 0, py = 0;
        // for (int i = 0; i < n; i++) {
        //     if (y[i] < my) {
        //         py = i;
        //         my = y[i];
        //     }
        // }
        // for (int i = 0; i < m; i++) {
        //     if (x[i] < mx) {
        //         px = i;
        //         mx = x[i];
        //     }
        // }
        // for (int u : x) cout << u << " ";
        // cout << endl;
        // for (int u : y) cout << u << " ";
        // cout << endl;
        // int ans = mx + my;
        // if (grid[py][px] == '.') ans--;
        // cout << ans << endl;
    }

    return 0;
}
