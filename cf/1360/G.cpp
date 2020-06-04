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
        int n, m, a, b; cin >> n >> m >> a >> b;
        if (a * n == b * m) {
            cout << "YES\n";
            vvi g(n, vi(m, 0));
            F0R (i, n) {
                int start = (i * a) % m;
                F0R (j, a) {
                    g[i][(start + j) % m] = 1;
                }
            }
            F0R (i, n) {
                F0R (j, m)
                    cout << g[i][j];
                cout << nl;
            }
        } else {
            cout << "NO\n";
        }
    }

    return 0;
}
