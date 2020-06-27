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
    int n, x; cin >> n >> x;
    vi a(n);
    F0R (i, n) cin >> a[i];

    vi pre(n + 1);
    pre[0] = 0;
    F0R (i, n) pre[i + 1] = (pre[i] + a[i]) % x;
    // 1 2 3 4 5 6 7 8 9
    // 1 3 1 0 0 1 3 1 0
    int first = 0, second = -1;
    int pos = -1;
    int ans = 0;
    F0R (i, n) {
        if (pre[i + 1] != first && second == -1) {
            second = pre[i + 1];
            pos = i + 1;
        }
        if (pre[i + 1] != first) ans = max(ans, i + 1);
        if (pre[i + 1] != second && second != -1) ans = max(ans, i + 1 - pos);
    }
    cout << (ans == 0 ? -1 : ans) << nl;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);

    int t; cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
