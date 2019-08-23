#include "bits/stdc++.h"

using namespace std;

using ll = long long;

void solve() {
    ll n, a, b; cin >> n >> a >> b;
    string s; cin >> s;

    ll dp[n + 1][2];
    for (int i = 0; i <= n; i++)
        dp[i][0] = dp[i][1] = 1LL << 45;

    dp[0][0] = 0;
    for (int i = 1; i < n; i++) {
        if (s[i - 1] == '0' && s[i] == '0') 
            dp[i][0] = min(dp[i - 1][0], dp[i - 1][1] + a);
        dp[i][1] = min(dp[i - 1][0] + a + b, dp[i - 1][1] + b);
    }
    dp[n][0] = min(dp[n - 1][0], dp[n - 1][1] + a);
    cout << (dp[n][0] + n * a + (n + 1) * b) << endl;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    int T; cin >> T;
    while (T--) {
        solve();
    }

    return 0;
}
