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
        int n; cin >> n;
        vi a(n);
        F0R (i, n) cin >> a[i];

        ll ans = 0;
        int i = 0;
        bool pos = a[0] > 0;
        while (i < n) {
            int j = i;
            int mx = 0;
            if (pos) {
                while (j < n && a[j] > 0) {
                    mx = max(mx, a[j]);
                    j++;
                }
            } else {
                mx = -2e9;
                while (j < n && a[j] < 0) {
                    mx = max(mx, a[j]);
                    j++;
                }
            }
            ans += mx;
            i = j;
            pos = !pos;
        }
        cout << ans << endl;
    }

    return 0;
}