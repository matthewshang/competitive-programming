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
        int n; cin >> n;
        vi a(2 * n);
        F0R (i, 2 * n) cin >> a[i];

        vb vis(2 * n, false);
        int need = n - 1;
        F0R (i, 2 * n) {
            FOR (j, i + 1, 2 * n - 1) {
                if ((a[i] % 2) == (a[j] % 2) && !vis[i] && !vis[j]) {
                    vis[i] = true;
                    vis[j] = true;
                    cout << (i + 1) << " " << (j + 1) << nl;
                    need--;
                }
                if (need == 0) break;
            }
            if (need == 0) break;
        }
    }

    return 0;
}