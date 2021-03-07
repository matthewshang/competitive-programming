#include "bits/stdc++.h"

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, c; cin >> n >> c;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
	
    vector<vector<int>> dp(n + 1, vector<int>(c + 1, false));
    dp[n][0] = 1;
    for (int i = n - 1; i >= 0; i--) {
        for (int j = 0; j <= c; j++) {
            // don't take
            dp[i][j] |= dp[i + 1][j];
            // take
            if (j - a[i] >= 0) {
                dp[i][j] |= dp[i + 1][j - a[i]];
            }
        }
    }
	
    long long sum = 0;
    long long ans = accumulate(a.begin(), a.end(), 0LL);
    for (int i = 0; i < n; i++) {
        int j = max(0LL, c - sum - a[i] + 1);
        for (; j <= c - sum; j++) {
            if (dp[i + 1][j]) {
                ans = min(ans, sum + j);
                break;
            }
        }
        sum += a[i];
        if (sum > c) break;
    }
    cout << ans << '\n';

    return 0;
}
