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

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);

    int n; cin >> n;
    vll a(n);
    F0R (i, n) cin >> a[i];

    if (n < 3) {
        ll ans = 0;
        F0R (i, n) {
            ans |= a[i];
        }
        cout << ans << nl;
        return 0;
    }

    ll best = 0;
    F0R (i, n) {
        FOR (j, i + 1, n - 1) {
            FOR (k, j + 1, n - 1) {
                ll val = a[i] | a[j] | a[k];
                best = max(best, val);
            }
        }
    }
    cout << best << nl;

    return 0;
}
