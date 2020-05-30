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

bool solve() {
    int n, k; cin >> n >> k;
    vi a(n);
    F0R (i, n) cin >> a[i];

    bool ok = false;
    F0R (i, n) {
        if (a[i] == k)
            ok = true;
    }
    if (!ok)
        return false;

    if (n == 1)
        return true;

    F0R (i, n - 1) {
        if (a[i] >= k && a[i + 1] >= k) {
            return true;
        }
    }
    F0R (i, n - 2) {
        if (a[i] >= k && a[i + 2] >= k) {
            return true;
        }
    }
    return false;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);

    int t; cin >> t;
    while (t--) {
        cout << (solve() ? "yes" : "no") << nl;
    }

    return 0;
}
