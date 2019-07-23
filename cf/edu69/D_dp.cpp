#include "bits/stdc++.h"

using namespace std;

using ll = long long;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    int n, m, k; cin >> n >> m >> k;
    vector<int> a(n); for (int& x : a) cin >> x;
    vector<ll> dp(n, 0);

    ll ans = 0;
    for (int i = 0; i < n; i++) {
        dp[i] = a[i] - k;
        ll sum = 0;
        for (int j = 0; j < m && i - j > 0; j++) {
            sum += a[i - j];
            dp[i] = max(dp[i], dp[i - j - 1] + sum - k);
        }
        if (i < m) dp[i] = max(dp[i], sum + a[0] - k);
        dp[i] = max(dp[i], 0LL);
        ans = max(ans, dp[i]);
        cout << dp[i] << " ";
    }
    cout << endl;
    cout << ans << endl;

    return 0;
}
