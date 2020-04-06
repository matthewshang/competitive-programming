#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using vi = vector<int>;
using pii = pair<int, int>;
using vpi = vector<pair<int, int>>;

#define f first
#define s second
#define pb push_back
#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()

#define FOR(i, a, b) for (int i=(a); i <=(b); i++)
#define F0R(i, a) for (int i=0; i < (a); i++)
#define RFOR(i, a, b) for (int i = (a); i >= b; i--)

void solve() {
    int n; cin >> n;
    int m[n][n];
    F0R (i, n) F0R (j, n) cin >> m[i][j];
    int k = 0, r = 0, c = 0;
    F0R (i, n) k += m[i][i];
    F0R (i, n) {
        set<int> rs, cs;
        F0R (j, n) {
            rs.insert(m[i][j]);
            cs.insert(m[j][i]);
        }
        r += rs.size() != n;
        c += cs.size() != n;
    }
    cout << k << " " << r << " " << c << endl;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    int t; cin >> t;
    FOR (i, 1, t) {
        cout << "Case #" << i << ": ";
        solve();
    }

    return 0;
}
