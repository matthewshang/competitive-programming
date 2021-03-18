#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using vi = vector<int>;
using vb = vector<bool>;
using vvi = vector<vector<int>>;
using vll = vector<long long>;
using pii = pair<int, int>;
using pll = pair<long long, long long>;
using vpi = vector<pair<int, int>>;

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

void solve() {
    int N, K; cin >> N >> K;
    vector<double> p(N);
    F0R (i, N) cin >> p[i];
    sort(all(p));

    double best = 0;
    // Try m = 0 ... K
    F0R (m, K + 1) {
        vector<double> q, r;
        F0R (i, m) q.pb(p[i]);
        F0R (i, K - m) q.pb(p[N - 1 - i]);
        F0R (i, K) {
            r.pb(log2(1.0 - q[i]));
            q[i] = log2(q[i]);
        }

        vector<vector<double>> dp(K + 1, vector<double>(K / 2 + 1));
        dp[0][0] = 0;
        FOR (i, 1, K) {
            F0R (j, min(i, K / 2) + 1) {
                if (j == 0) {
                    dp[i][j] = dp[i - 1][j] + r[i - 1];
                } else if (j == i) {
                    dp[i][j] = dp[i - 1][j - 1] + q[i - 1];
                } else {
                    dp[i][j] = log2(pow(2.0, dp[i - 1][j] + r[i - 1]) + pow(2.0, dp[i - 1][j - 1] + q[i - 1]));
                }
            }
        }
        best = max(best, pow(2.0, dp[K][K / 2]));
    }
    cout << best << endl;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);

    int T; cin >> T;
    FOR (t, 1, T) {
        cout << "Case #" << t << ": ";
        solve();
    }

    return 0;
}
