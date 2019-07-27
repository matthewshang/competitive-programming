#include "bits/stdc++.h"

using namespace std;

using ll = long long;

void solve() {
    int n, k; cin >> n >> k;
    string s; cin >> s;

    const string RGB = "RGB";

    int ans = k;
    bool mask[n][3];
    for (int i = 0; i < n; i++) for (int j = 0; j < 3; j++) mask[i][j] = false;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 3; j++) {
            mask[i][j] = s[i] != RGB[(i + j) % 3];
        }
    }

    int cmp[3];
    for (int i = 0; i < 3; i++) cmp[i] = 0;
    for (int i = 0; i < k; i++) for (int j = 0; j < 3; j++) cmp[j] += mask[i][j];
    for (int j = 0; j < 3; j++) ans = min(ans, cmp[j]);
    // cout << cmp[0] << " " << cmp[1] << " " << cmp[2] << endl;
    for (int i = k; i < n; i++) {
        for (int j = 0; j < 3; j++) {
            cmp[j] -= mask[i - k][j];
            cmp[j] += mask[i][j];
        }
        for (int j = 0; j < 3; j++) ans = min(ans, cmp[j]);
    }
    cout << ans << endl;

    // for (int i = 0; i < n - k + 1; i++) {
    //     vector<int> cmp(3, 0);
    //     for (int j = 0; j < k; j++) {
    //         for (int l = 0; l < 3; l++)
    //             cmp[l] += s[i + j] != RGB[(j + l) % 3];
    //     }
    //     for (int l = 0; l < 3; l++)
    //         ans = min(ans, cmp[l]);
    // }
    // cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    int q; cin >> q;
    while (q--) {
        solve();
    }

    return 0;
}
