#include <bits/stdc++.h>
using namespace std;

/* Date: 2022-02-19
 * Source: LATAM 2020
 */

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, X;
    cin >> n >> X;
    vector<int> s(n);
    vector<int> d(n);
    for (int i = 0; i < n; i++) {
        cin >> s[i] >> d[i];
    }

    int best_T = 0;
    int best_C = 1e9;
    for (int T = 0; T <= 8 * 60; T++) {
        int conflicts = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] + d[i] < T) {
                continue;
            }
            int low = ceil(double(max(s[i], T) - T) / X);
            int high = floor(double(max(s[i] + d[i], T) - T) / X);
            conflicts += high - low + 1;
        }
        if (conflicts < best_C || (conflicts == best_C && T < best_T)) {
            best_T = T;
            best_C = conflicts;
        }
    }

    cout << best_T << " " << best_C << "\n";

    return 0;
}