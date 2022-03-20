#include <bits/stdc++.h>
using namespace std;

/* Date: 2022-03-19
 * Source: Kick Start Round A 2022
 * Notes: Enough to prevent palindromes of length 5 and 6. Do DP keeping track 
 * of last 6 positions. Handle n<5 and n=5 as special cases.
 */

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    auto gen = [](int n) -> vector<bool> {
        vector<bool> legal((1 << n));
        for (int i = 0; i < (1 << n); i++) {
            legal[i] = false;
            for (int j = 0; j < n / 2; j++) {
                bool l = i & (1 << j);
                bool r = i & (1 << (n - 1 - j));
                legal[i] = legal[i] | (l != r);
            }
        }
        return legal;
    };

    const auto legal5 = gen(5);
    auto legal = gen(6);
    for (int mask = 0; mask < 64; mask++) {
        if (!legal5[mask >> 1] || !legal5[mask & (0b11111)]) {
            legal[mask] = false;
        }
    }

    int cases;
    cin >> cases;
    for (int test = 1; test <= cases; test++) {
        int n;
        cin >> n;
        string s;
        cin >> s;

        auto answer = [&](bool ok) {
            cout << "Case #" << test << ": " << (ok ? "POSSIBLE" : "IMPOSSIBLE") << "\n";
        };

        auto match = [&](int start, int mask, int len) {
            for (int i = 0; i < len; i++) {
                bool on = mask & (1 << i);
                if ((s[start + len - 1 - i] == '0' && on) || (s[start + len - 1 - i] == '1' && !on)) {
                    return false;
                }
            }
            return true;
        };

        if (n < 5) {
            answer(true);
            continue;
        }
        if (n == 5) {
            bool ok = false;
            for (int mask = 0; mask < 32; mask++) {
                if (legal5[mask] && match(0, mask, 5)) {
                    ok = true;
                    break;
                }
            }
            answer(ok);
            continue;
        }

        array<bool, 64> dp;
        for (int mask = 0; mask < 64; mask++) {
            dp[mask] = legal[mask] && match(0, mask, 6);
        }
        for (int i = 6; i < n; i++) {
            array<bool, 64> next_dp{};
            for (int mask = 0; mask < 64; mask++) {
                if (!legal[mask]) continue;
                if (match(i - 5, mask, 6) && (dp[mask >> 1] || 
                                              dp[0b100000 ^ (mask >> 1)])) {
                    next_dp[mask] = true;
                } 
            }
            swap(dp, next_dp);
        }

        answer(find(dp.begin(), dp.end(), true) != dp.end());
    }

    return 0;
}