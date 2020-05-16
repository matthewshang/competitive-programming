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

    int t; cin >> t;
    while (t--) {
        int n, k; cin >> n >> k;
        string s; cin >> s;
        int count[26];
        F0R (i, 26) count[i] = 0;
        F0R (i, n) count[s[i] - 'a']++;

        vector<pair<char, int>> v;
        F0R (i, 26) if (count[i] > 0) v.pb({(char)('a' + i), count[i]});
        string ans = "";
        if (v[0].S < k) {
            int i = 0, j = 0;
            while (i < k) {
                i += v[j].S;
                j++;
            }
            ans += v[j - 1].F;
        } else {
            if (v[0].S == k && sz(v) == 2) {
                ans += v[0].F;
                F0R (i, (v[1].S + k - 1) / k) {
                    ans += v[1].F;
                }
            } else if (sz(v) == 1) {
                F0R (i, (v[0].S + k - 1) / k) {
                    ans += v[0].F;
                }
            } else {
                ans += v[0].F;
                v[0].S -= k;
                F0R (i, sz(v)) {
                    F0R (j, v[i].S) ans += v[i].F;
                }
            }
        }
        cout << ans << endl;
    }

    return 0;
}