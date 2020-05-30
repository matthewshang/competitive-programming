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

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);

    int n, q; cin >> n >> q;
    vi a(n);
    F0R (i, n) cin >> a[i];
    vi k(q);
    F0R (i, q) cin >> k[i];

    vi pre(n + 1, 0);
    F0R (i, n)
        pre[a[i]]++;
    F0R (i, n)
        pre[i + 1] += pre[i];

    int lo = 1, hi = n + 1;
    bool non = false;
    while (lo < hi) {
        int m = lo + (hi - lo) / 2;
        int count = pre[m];
        F0R (i, q) {
            if (k[i] < 0) {
                if (-k[i] <= count) {
                    count--;
                }
            } else {
                if (k[i] <= m) {
                    count++;
                }
            }
        }
        
        if (count == 0) {
            lo = m + 1;
        } else {
            non = true;
            hi = m;
        }
    }
    cout << (non ? lo : 0) << endl;
    return 0;
}
