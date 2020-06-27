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

    int n, k; cin >> n >> k;
    vi a(n);
    F0R (i, n) cin >> a[i];

    const auto Ok = [&](int ans, bool start) -> bool {
        int count = 0;
        F0R (i, n) {
            if (start) {
                count++;
                start = !start;
            } else if (a[i] <= ans) {
                count++;
                start = !start;
            }
        }
        return count >= k;
    };

    int lo = 1, hi = 1e9;
    while (lo < hi) {
        int mi = lo + (hi - lo) / 2;   
        bool res = Ok(mi, false) || Ok(mi, true);
        if (res) {
            hi = mi;
        } else {
            lo = mi + 1;
        }
    }
    cout << lo << nl;

    return 0;
}
