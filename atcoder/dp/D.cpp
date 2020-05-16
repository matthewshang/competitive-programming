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

    int n, w; cin >> n >> w;
    vi a(n), b(n);
    F0R (i, n) cin >> a[i] >> b[i];

    vector<vll> dp(n + 1, vll(w + 1, 0));
    FOR (i, 1, n) {
        FOR (j, 1, w) {
            if (a[i - 1] <= j) {
                dp[i][j] = max(dp[i - 1][j], b[i - 1] + dp[i - 1][j - a[i - 1]]);
            } else {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }
    cout << dp[n][w] << endl;
    return 0;
}
