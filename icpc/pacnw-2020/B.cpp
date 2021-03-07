#include "bits/stdc++.h"

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k; cin >> n >> k;
    vector<string> ans(n);
    for (int i = 0; i < n; i++) {
        cin >> ans[i];
    }

    int best = 0;
    for (int mask = 0; mask < (1 << k); mask++) {
        int low = k;
        for (int i = 0; i < n; i++) {
            int score = 0;
            for (int j = 0; j < k; j++) {
                bool mask_on = mask & (1 << j);
                bool stud_on = ans[i][j] == 'T';
                if (mask_on == stud_on) {
                    score++;
                }
            }
            low = min(low, score);
        }
        best = max(best, low);
    }
    cout << best << '\n';

    return 0;
}
