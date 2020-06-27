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

void solve() {
    int n, k; cin >> n >> k;
    vi a(n);
    F0R (i, n) cin >> a[i];
    vi w(k);
    F0R (i, k) cin >> w[i];

    ll ans = 0;
    sort(all(w));
    sort(all(a));
    int cur = n - 1;
    int i = 0;
    while (i < k && w[i] == 1) {
        ans += 2LL * a[cur];
        cur--;
        i++;
    }

    int accum = 0;
    F0R (j, k - i) {
        ans += a[accum] + a[cur - j];
        accum += w[k - 1 - j] - 1;
    }

    cout << ans << nl;
}
int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);

    int t; cin >> t;
    while (t--) solve();

    return 0;
}