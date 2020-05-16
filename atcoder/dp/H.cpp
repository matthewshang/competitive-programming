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

    int h, w; cin >> h >> w;
    vector<string> g(h);
    F0R (i, h) cin >> g[i];

    ll dp[h][w];
    F0R (i, h) F0R (j, w) dp[i][j] = 0;
    dp[0][0] = 1;
    FOR (i, 1, w - 1) if (g[0][i - 1] != '#') dp[0][i] = dp[0][i - 1];
    FOR (i, 1, h - 1) if (g[i - 1][0] != '#') dp[i][0] = dp[i - 1][0];
    FOR (i, 1, h - 1) {
        FOR (j, 1, w - 1) {
            if (g[i - 1][j] != '#') dp[i][j] = (dp[i][j] + dp[i - 1][j]) % MOD;
            if (g[i][j - 1] != '#') dp[i][j] = (dp[i][j] + dp[i][j - 1]) % MOD;
        }
    }
    cout << dp[h - 1][w - 1] << endl;

    return 0;
}
