#include "bits/stdc++.h"

using namespace std;

using ll = long long;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    int h, w; cin >> h >> w;
    vector<string> g(h);
    for (auto& x : g) cin >> x;

    vector<vector<int>> x(h, vector<int>(w, 0)), y(h, vector<int>(w, 0));
    for (int i = 0; i < h; i++) {
        int j = 0;
        while (j < w) {
            if (g[i][j] == '#') {
                j++;
                continue;
            }
            
            int q = j;
            while (q < w && g[i][q] == '.') q++;
            int l = q - j;
            for (int k = j; k < q; k++) x[i][k] = l;
            j = q;
        }
    }

    for (int i = 0; i < w; i++) {
        int j = 0;
        while (j < h) {
            if (g[j][i] == '#') {
                j++;
                continue;
            }
            
            int q = j;
            while (q < h && g[q][i] == '.') q++;
            int l = q - j;
            for (int k = j; k < q; k++) y[k][i] = l;
            j = q;
        }
    }

    int ans = 0;
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            ans = max(ans, x[i][j] + y[i][j] - 1);
        }
    }
    cout << ans << endl;

    return 0;
}
