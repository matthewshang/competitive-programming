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
        int n, m; cin >> n >> m;
        vvi a(n, vi(m));
        F0R (i, n) {
            F0R (j, m)
                cin >> a[i][j];
        }

        int row = 0;
        int col = 0;
        F0R (i, n) {
            bool ok = true;
            F0R (j, m) {
                if (a[i][j] == 1)
                    ok = false;
            }

            if (ok)
                row++;
        }

        F0R (j, m) {
            bool ok = true;
            F0R (i, n) {
                if (a[i][j] == 1)
                    ok = false;
            }

            if (ok)
                col++;
        }

        int par = min(row, col);
        cout << (par % 2 ? "Ashish" : "Vivek") << nl;
    }

    return 0;
}
