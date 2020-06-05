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

    ll n, t; cin >> n >> t;
    vi k(n);
    F0R (i, n)
        cin >> k[i];
    
    ll lo = 1, hi = 1e18 + 1;
    while (lo < hi) {
        ll mi = lo + (hi - lo) / 2;
        ll p = 0;
        F0R (i, n) {
            p += mi / k[i];
            if (p >= t)
                break;
        }
        if (p >= t) {
            hi = mi;
        } else {
            lo = mi + 1;
        }
    }
    cout << lo << endl;
    return 0;
}
