#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using vi = vector<int>;
using vb = vector<bool>;
using vvi = vector<vector<int>>;
using vll = vector<long long>;
using vpi = vector<pair<int, int>>;
using pii = pair<int, int>;
using pll = pair<long long, long long>;

#define F first
#define S second
#define pb push_back
#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()

#define FOR(i, a, b) for (int i = (a); i <= (b); ++i)
#define F0R(i, a) for (int i = 0; i < (a); ++i)
#define RFOR(i, a, b) for (int i = (a); i >= (b); --i)

const char nl = '\n';
const ll MOD = 1e9 + 7;

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);

    const int N = 2000002;

    vll dp(N);
    dp[1] = 0;
    dp[2] = 0;
    dp[3] = 4;
    dp[4] = 4;
    FOR (i, 5, N) {
        if (i % 3 == 0) {
            dp[i] = (dp[i - 2] + 4) % MOD;
            dp[i] = (dp[i] + (4 * dp[i - 3]) % MOD) % MOD;
            dp[i] = (dp[i] + (4 * dp[i - 4]) % MOD) % MOD;
        } else {
            dp[i] = dp[i - 1];
            dp[i] = (dp[i] + (2 * dp[i - 2]) % MOD) % MOD;
        }
    }
    
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        cout << dp[n] << nl;
    }

    return 0;
}