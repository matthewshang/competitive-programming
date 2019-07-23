#include "bits/stdc++.h"

using namespace std;

using ll = long long;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    int T; cin >> T;
    for (int tt = 0; tt < T; tt++) {
        int n, k; cin >> n >> k;
        // vector<bool> dp(40, false);
        // dp[1] = true;
        // dp[2] = true;
        // dp[k] = true;
        // for (int i = 3; i < 40; i++) {
        //     if (i >= k) {
        //         if (dp[i - 1] && dp[i - 2] && dp[i - k]) {
        //             dp[i] = false;
        //         } else {
        //             dp[i] = true;
        //         }
        //     } else {
        //         if (dp[i - 1] && dp[i - 2]) {
        //             dp[i] = false;
        //         } else {
        //             dp[i] = true;
        //         }
        //     }
        // }
        // cout << "n: " << n << ", k: " << k << ": ";
        // for (bool x : dp) cout << x << " ";
        // cout << endl;

        if (k % 3 == 0) {
            int i = n % (k + 1);
            if (i == 0) cout << "Bob\n";
            else if (i == k) cout << "Alice\n";
            else if (i % 3 == 0) cout << "Bob\n";
            else cout << "Alice\n";
        } else {
            if (n % 3 == 0) cout << "Bob\n";
            else cout << "Alice\n";
        }
    }

    return 0;
}
