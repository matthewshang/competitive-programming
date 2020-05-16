#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using vi = vector<int>;
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

#define FOR(i, a, b) for (int i=(a); i <=(b); i++)
#define F0R(i, a) for (int i=0; i < (a); i++)
#define RFOR(i, a, b) for (int i = (a); i >= b; i--)

const char nl = '\n';
const ll MOD = 1e9 + 7;
const ll INF = 1e18;

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);

    int n, k; cin >> n >> k;
    vector<string> dig(n);
    F0R (i, n) cin >> dig[i];
    const vector<string> D = { "1110111", "0010010", "1011101", "1011011", "0111010", "1101011", "1101111", "1010010", "1111111", "1111011"};

    vvi cost(n, vi(10, 0));
    F0R (i, n) {
        F0R (j, 10) {
            bool ok = true;
            F0R (l, 7) {
                if (dig[i][l] == '1' && D[j][l] == '0') {
                    ok = false;
                    break;
                } else if (dig[i][l] == '0' && D[j][l] == '1') {
                    cost[i][j]++;
                }
            }
            if (!ok) {
                cost[i][j] = -1;
            }
        }
    }

    vvi dp(n + 1, vi(k + 1, -1));
    F0R (i, k + 1) dp[n][i] = 10;
    F0R (i, k + 1) {
        F0R (j, 10) {
            if (cost[n - 1][j] == i) {
                dp[n - 1][i] = max(dp[n - 1][i], j);
            }
        }
    }
    RFOR (i, n - 2, 0) {
        F0R (j, k + 1) {
            F0R (d, 10) {
                if (cost[i][d] != -1 && cost[i][d] <= j && dp[i + 1][j - cost[i][d]] != -1) {
                    dp[i][j] = max(dp[i][j], d);
                }
            }
        }
    }
    if (dp[0][k] == -1) {
        cout << "-1\n";
        return 0;
    }
    string ans = "";
    F0R (i, n) {
        int d = dp[i][k];
        ans += '0' + d;
        k -= cost[i][d];
    }
    cout << ans << endl;





    // F0R (i, n) {
    //     cout << i << ": ";
    //     F0R (j, 10) cout << cost[i][j] << " ";
    //     cout << endl;
    // }
    // F0R (i, n) {
    //     cout << i << ": ";
    //     F0R (j, k + 1) cout << dp[i][j] << " ";
    //     cout << endl;
    // }

    return 0;
}