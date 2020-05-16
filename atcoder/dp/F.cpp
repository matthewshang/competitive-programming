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

    string s, t; cin >> s >> t;
    int n = sz(s), m = sz(t);
    vvi dp(n + 1, vi(m + 1, 0));
    vector<vpi> last(n + 1, vpi(m + 1, {-1, -1}));
    vector<vb> used(n + 1, vb(m + 1, false));
    // dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - 1] + 1)
    F0R (i, n) {
        F0R (j, m) {
            if (s[i] == t[j]) {
                if (dp[i][j + 1] > dp[i][j] + 1) {
                    last[i + 1][j + 1] = {i, j + 1};
                    dp[i + 1][j + 1] = dp[i][j + 1];
                } else {
                    last[i + 1][j + 1] = {i, j};
                    dp[i + 1][j + 1] = dp[i][j] + 1;
                    used[i + 1][j + 1] = true;
                }
            } else {
                dp[i + 1][j + 1] = max(dp[i][j + 1], dp[i + 1][j]);
                if (dp[i][j + 1] > dp[i + 1][j]) {
                    last[i + 1][j + 1] = {i, j + 1};
                    dp[i + 1][j + 1] = dp[i][j + 1];
                } else {
                    last[i + 1][j + 1] = {i + 1, j};
                    dp[i + 1][j + 1] = dp[i + 1][j];
                }
            }
        }
    }
    pii cur = {n, m};
    string ans = "";
    while (cur.F > 0 && cur.S > 0) {
        if (used[cur.F][cur.S]) {
            ans += s[cur.F - 1];
        }
        cur = last[cur.F][cur.S];
    }
    reverse(all(ans));
    cout << ans << endl;

    return 0;
}
