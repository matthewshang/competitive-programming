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
const ll INF = 1e18;

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);

    int n; cin >> n;
    vector<double> p(n);
    F0R (i, n) cin >> p[i];

    vector<vector<double>> dp(n + 1, vector<double>(n + 1, 0));
    // dp[i][j] = P(i coins, j heads)
    // dp[i][j] = p[i] * dp[i - 1][j - 1] + (1 - p[i]) * dp[i - 1][j]
    dp[0][0] = 1;
    FOR (i, 1, n) {
        F0R (j, i + 1) {
            dp[i][j] = (1 - p[i - 1]) * dp[i - 1][j];
            if (j > 0) {
                dp[i][j] += p[i - 1] * dp[i - 1][j - 1];
            }
        }
    }
    double ans = 0;
    F0R (i, n / 2 + 1) {
        ans += dp[n][n - i];
    }
    cout << setprecision(9) << ans << endl;

    return 0;
}
