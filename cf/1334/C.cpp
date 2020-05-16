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
        vll a(n), b(n);
        F0R (i, n) cin >> a[i] >> b[i];
        a.pb(a[0]); b.pb(b[0]);

        ll start = 0;
        F0R (i, n) {
            if (b[i] < a[i + 1])
                start += a[i + 1] - b[i];
        }

        ll ans = INF;
        FOR (i, 1, n) {
            ll val = a[i] + start;
            if (b[i - 1] < a[i])
                val -= a[i] - b[i - 1];
            ans = min(ans, val);
        }
        cout << ans << endl;
    }

    return 0;
}