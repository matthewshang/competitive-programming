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

void solve() {
    int n, k; cin >> n >> k;
    vi a(n);
    F0R (i, n) cin >> a[i];

    vector<array<int, 3>> ev;
    F0R (i, n / 2) {
        int x = a[i], y = a[n - 1 - i];
        ev.pb({min(1 + x, 1 + y), 1, i});
        ev.pb({x + y, 2, i});
        ev.pb({x + y, 3, i});
        ev.pb({max(x + k, y + k), 4, i});
    }
    sort(all(ev));

    int cost = n;
    int ans = n - 2;
    for (auto [t, y, i] : ev) {
        cost += (y <= 2) ? -1 : 1;
        ans = min(ans, cost);
    }
    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);

    int t; cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}