#include "bits/stdc++.h"

using namespace std;

using ll = long long;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    const ll MD = 1e9 + 7;
    int n, m; cin >> n >> m;
    set<int> a;
    for (int i = 0; i < m; i++) {
        int x; cin >> x;
        a.insert(x);
    }

    vector<ll> dp(n + 2, 0);
    dp[0] = 0;
    dp[1] = 1;
    for (int i = 1; i <= n; i++) {
        if (a.find(i) != a.end()) {
            dp[i + 1] = 0;
        } else {
            dp[i + 1] = (dp[i] + dp[i - 1]) % MD;
        }
    }
    cout << dp[n + 1] << endl;

    return 0;
}
