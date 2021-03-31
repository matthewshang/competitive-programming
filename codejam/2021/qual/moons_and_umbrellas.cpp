#include "bits/stdc++.h"
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T; cin >> T;
    for (int tc = 1; tc <= T; tc++) {
        int X, Y; cin >> X >> Y;
        string S; cin >> S;

        int n = S.size();
        vector<array<int, 2>> dp(n + 1, { 1000000, 1000000 });
        if (S[0] == '?' || S[0] == 'C') {
            dp[1][0] = 0;
        }
        if (S[0] == '?' || S[0] == 'J') {
            dp[1][1] = 0;
        }
        for (int i = 2; i <= n; i++) {
            char cur = S[i - 1];
            if (cur == '?' || cur == 'C') {
                dp[i][0] = min(dp[i - 1][0], dp[i - 1][1] + Y);
            }
            if (cur == '?' || cur == 'J') {
                dp[i][1] = min(dp[i - 1][1], dp[i - 1][0] + X);
            }
        }
        cout << "Case #" << tc << ": " << min(dp[n][0], dp[n][1]) << '\n';
    }
    
    return 0;
}