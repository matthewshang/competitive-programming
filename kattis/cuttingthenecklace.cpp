#include "bits/stdc++.h"

using namespace std;

/* Date: 2021-04-07
 * Source: NENA 2019
 */

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int k, n; cin >> k >> n;
    vector<int> b(n);
    int64_t total = 0;
    for (int i = 0; i < n; i++) {
        cin >> b[i];
        total += b[i];
    }

    if (total % k != 0) {
        cout << "NO" << '\n';
        return 0;
    }

    int64_t per = total / k;
    int64_t sum = 0;
    unordered_map<int64_t, int> cmp;
    cmp[0] = 0;
    for (int z = 0; z < 2; z++) {
        for (int i = 0; i < n; i++) {
            sum += b[i];
            if (sum < per) {
                cmp[sum] = 0;
            } else if (auto it = cmp.find(sum - per); it != cmp.end()) {
                cmp[sum] = it->second + 1;
                if (cmp[sum] == k) {
                    cout << "YES" << '\n';
                    return 0;
                }
            }
        }
    }

    cout << "NO" << '\n';
    return 0;
}