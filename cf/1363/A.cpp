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

    int t; cin >> t;
    while (t--) {
        int n, x; cin >> n >> x;
        int ev = 0, od = 0;
        F0R (i, n) {
            int a; cin >> a;
            if (a % 2)
                od++;
            else
                ev++;
        }

        bool ok = false;
        F0R (i, x + 1) {
            if (i % 2 && i <= od && (x - i) <= ev) {
                ok = true;
                break;
            }
        }

        cout << (ok ? "Yes" : "No") << nl;
    }

    return 0;
}
