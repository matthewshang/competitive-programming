#include "bits/stdc++.h"

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    constexpr int MOD = 1000000009;

    int k, b; 
    cin >> k >> b;

    vector<int> pows(b);
    pows[0] = 1;
    for (int i = 1; i < b; i++) {
        pows[i] = pows[i - 1] * 2 % k;
    }

    vector<vector<vector<int>>> dp(b, vector<vector<int>>(k, vector<int>(b + 1, -1)));
    auto go = [&](auto& self, int pos, int rem, int on) -> int {
        if (pos == b) {
            return rem == 0 ? on : 0;
        }
        if (dp[pos][rem][on] != -1) {
            return dp[pos][rem][on];
        }

        int res = 0;
        int ex = b - 1 - pos;
        res = (res + self(self, pos + 1, rem, on)) % MOD;
        res = (res + self(self, pos + 1, (rem + pows[ex]) % k, on + 1)) % MOD;
        dp[pos][rem][on] = res;
        return res;
    };
    int res = go(go, 0, 0, 0);
    cout << res << '\n';

    return 0;
}