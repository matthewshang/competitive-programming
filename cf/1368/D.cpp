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
    vi a(n);
    F0R (i, n) cin >> a[i];

    vi bc(20, 0);
    F0R (i, n) {
        F0R (j, 20) {
            if (a[i] & (1 << j))
                bc[j]++;
        }
    }

    vi b(n, 0);
    F0R (j, 20) {
        F0R (i, bc[j]) {
            b[i] |= (1 << j);
        }
    }
    ll ans = 0;
    F0R (i, n)
        ans += (ll)b[i] * b[i];
    cout << ans << nl;

    return 0;
}
