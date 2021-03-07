#include "bits/stdc++.h"

using namespace std;

constexpr long long MOD = 998244353;

// pos, cur digit, bound
long long dp[100010][11][2];

void reset() {
    for (int i = 0; i <= 100000; i++) {
        for (int j = 0; j <= 10; j++) {
            dp[i][j][0] = dp[i][j][1] = -1;
        }
    }
}

long long go(string& s, int pos, int last, bool force) {
    if (pos == int(s.size()) && last == 10) return 0;
    if (pos == int(s.size())) return 1;
    if (dp[pos][last][force] != -1) {
        return dp[pos][last][force];
    }

    long long res = 0;
    if (last == 10) {
        res = (res + go(s, pos + 1, 10, false)) % MOD;
    }

    int cur = s[pos] - '0';
    for (int d = 0; d <= 9; d++) {
        if (d == last) {
            continue;
        }
        if (last == 10 && d == 0) {
            continue;
        }

        if (force) {
            if (d < cur) {
                res = (res + go(s, pos + 1, d, false)) % MOD;
            } else if (d == cur) {
                if ((last == 10 && pos == 0) || last != 10) {
                    res = (res + go(s, pos + 1, d, true)) % MOD;
                }
            } else {
                break;
            }
        } else {
            res = (res + go(s, pos + 1, d, false)) % MOD;
        }
    }

    dp[pos][last][force] = res;
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string L, U; cin >> L >> U;

    reset();
    long long u_ways = go(U, 0, 10, true);

    reset();
    long long l_ways = go(L, 0, 10, true);

    // subtract 1 if L is a rainbow number
    bool l_rainbow = true;
    for (int i = 0; i < int(L.size()) - 1; i++) {
        if (L[i] == L[i + 1]) {
            l_rainbow = false;
            break;
        }
    }
    l_ways -= l_rainbow;

    long long ways = (u_ways - l_ways) % MOD;
    if (ways < 0) {
        ways += MOD;
    }
    cout << ways << '\n';

    return 0;
}
