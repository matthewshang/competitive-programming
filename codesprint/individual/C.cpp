#include <bits/stdc++.h>
using namespace std;

int64_t dp[21][21][61][61];
int64_t go(int g, int e, int d, int f) {
    if (dp[g][e][d][f] != -1) {
        return dp[g][e][d][f];
    }
    if (g == 0 && e == 0) {
        return 1;
    }
    if (d != 0) {
        g++;
    }

    dp[g][e][d][f] = 0;
    if (g == 0 && e == 0) {
        if (d == f) {
            dp[g][e][d][f] = 1;
        } else {
            dp[g][e][d][f] = 0;
        }
    } else if (e == 0) {
        dp[g][e][d][f] = go(max(0, g - 2), e, d + 1, f);
    } else if (g == 0) {
        dp[g][e][d][f] = go(g + 1, e - 1, d + 1, f);
    } else {
        dp[g][e][d][f] += go(max(0, g - 2), e, d + 1, f);
        dp[g][e][d][f] += go(g, e - 1, d + 1, f);
    }
    return dp[g][e][d][f];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    for (int i = 0; i <= 20; i++) {
        for (int j = 0; j <= 20; j++) {
            for (int k = 0; k <= 60; k++) {
                for (int l = 0; l <= 60; l++) {
                    dp[i][j][k][l] = -1;
                }
            }
        }
    }

    int t;
    cin >> t;
    while (t--) {
        int g, e;
        cin >> g >> e;
        cout << go(g, e, 0, e + g + e - 1) << '\n';
    }

    return 0;
}
