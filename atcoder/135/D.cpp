#include "bits/stdc++.h"

using namespace std;

using ll = long long;

ll POWER[6] = {1, 10, 9, 12, 3, 4};

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    string s; cin >> s;
    int n = s.size();
    const ll MD = 1e9 + 7;
    ll dp[n + 1][13];
    for (int i = 0; i <= n; i++)
        for (int j = 0; j < 13; j++)
            dp[i][j] = 0;
    reverse(s.begin(), s.end());

    if (s[0] == '?') {
        for (int j = 0; j < 10; j++) dp[0][j] = 1;
    } else {
        ll d = s[0] - '0';
        dp[0][d] = 1;
    }

    for (int i = 1; i < n; i++) {
        if (s[i] == '?') {
            for (int d = 0; d < 10; d++) {
                ll m = (POWER[i % 6] * d) % 13;
                for (int j = 0; j < 13; j++) 
                    dp[i][j] = (dp[i][j] + dp[i - 1][(j - m + 13) % 13]) % MD;
            }
        } else {
            ll d = s[i] - '0';
            ll m = (POWER[i % 6] * d) % 13;
            for (int j = 0; j < 13; j++) 
                dp[i][j] = (dp[i][j] + dp[i - 1][(j - m + 13) % 13]) % MD;
        }
    }
    cout << dp[n - 1][5] << endl;
    return 0;
}
