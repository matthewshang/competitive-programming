#include <bits/stdc++.h>
using namespace std;

constexpr int MAXN = 1e6;
constexpr int64_t MOD = 1e9 + 7;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<int64_t> dp(MAXN + 1);  // dp[i] = towers of height i ending with a 2 wide block
    vector<int64_t> ans(MAXN + 1);  // ans[i] = towers of height i
    ans[0] = 1;
    dp[0] = 1;
    int64_t pre = ans[0];  // pre = sum ans[j] from 0 to i-1
    int64_t pre2 = dp[0];  // pre2 = dp2[i] + dp2[i-1] + 4dp2[i-2] + ... + 4^(i-1)dp2[0]

    for (int i = 1; i <= MAXN; i++) {
        // dp2[i] = sum ans[j] from 0 to i-1
        // ans[i] = sum dp2[j] * dp1[i-j]^2 from 0 to i
        //        = sum from 0 to i dp2[j] * 2^(2*max(0,i-j-1))
        //        = sum from 0 to i dp2[j] * 4^max(0,i-j-1)
        //        = dp2[i] + dp2[i-1] + 4dp2[i-2] + ... + 4^(i-1)dp2[0]
        dp[i] = pre;
        pre2 = (pre2 * 4 - 3 * dp[i - 1] + dp[i]) % MOD;
        pre2 = (pre2 + MOD) % MOD;
        ans[i] = pre2;
        pre = (pre + ans[i]) % MOD;
    }

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        cout << ans[n] << '\n';
    }

    return 0;
}
