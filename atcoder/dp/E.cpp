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

    int N, W; cin >> N >> W;
    vi w(N), v(N);
    F0R (i, N) cin >> w[i] >> v[i];
    int V = 0;
    F0R (i, N) V += v[i];

    // least weight to get certain value (max val = 1e5)
    // dp[i][j] = least weight to get value j with first i items
    // dp[i][j] = dp[i - 1][j - val[i]] (if j - val[i] != INF)
    vector<vll> dp(N + 1, vll(V + 1, INF));
    F0R (i, N + 1) {
        dp[i][0] = 0;
    }
    F0R (i, N) {
        FOR (j, 1, V) {
            dp[i + 1][j] = dp[i][j];
            if (v[i] <= j) {
                ll val = w[i] + dp[i][j - v[i]];
                if (val <= W) {
                    dp[i + 1][j] = min(dp[i][j], val);
                }
            }
        }
    }
    RFOR (i, V, 0) {
        if (dp[N][i] != INF) {
            cout << i << endl;
            break;
        }
    }

    return 0;
}
