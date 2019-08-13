#include "bits/stdc++.h"

using namespace std;

using ll = long long;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    int n; cin >> n;
    vector<string> g(n);
    for (auto& x : g) cin >> x;

    int dp[n + 1][n + 1][n + 1][n + 1];
    const int INF = 1<<20;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                for (int l = 0; l < n; l++) dp[i][j][k][l] = INF;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            dp[i][j][i + 1][j + 1] = (g[i][j] == '#' ? 1 : 0);
        }
    }

    for (int s = 2; s <= n; s++) {
        for (int i = 0; i <= n - s; i++) {
            for (int j = 0; j <= n - s; j++) {
                int cost = 0;
                
            }
        }
    }

    return 0;
}
