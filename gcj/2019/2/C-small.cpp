#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using vi = vector<int>;
using vvi = vector<vector<int>>;
using vll = vector<long long>;
using pii = pair<int, int>;
using pll = pair<long long, long long>;
using vpi = vector<pair<int, int>>;

#define F first
#define S second
#define pb push_back
#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()

#define FOR(i, a, b) for (int i=(a); i <=(b); i++)
#define F0R(i, a) for (int i=0; i < (a); i++)
#define RFOR(i, a, b) for (int i = (a); i >= b; i--)

const char nl = '\n';
const ll MOD = 1e9 + 7;
const ll INF = 1e18;

void solve() {
    int n; cin >> n;
    vi C(n), J(n);
    F0R (i, n) cin >> C[i] >> J[i];

    auto check = [&](int a, int b) -> bool {
        F0R (i, n - 1) {
            if (C[i] * a + J[i] * b >= C[i + 1] * a + J[i + 1] * b) return false;
        }
        return true;
    };

    FOR (i, 1, 200) {
        FOR (j, 1, 200) {
            if (check(j, i)) {
                int g = __gcd(j, i);
                i /= g; j /= g;
                cout << j << " " << i << endl;
                return;
            }
        }
    }
    cout << "IMPOSSIBLE\n";

}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);

    int t; cin >> t;
    FOR (i, 1, t) {
        cout << "Case #" << i << ": ";
        solve();
    }

    return 0;
}
