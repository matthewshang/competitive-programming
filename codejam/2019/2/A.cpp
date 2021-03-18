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

    set<pii> s;
    F0R (i, n) {
        FOR (j, i + 1, n - 1) {
            if ((C[i] >= C[j] && J[i] >= J[j]) || (C[i] <= C[j] && J[i] <= J[j])) continue;
            int a = abs(C[i] - C[j]), b = abs(J[j] - J[i]);
            int g = __gcd(a, b);
            s.insert({a / g, b / g});
        }
    }
    cout << s.size() + 1 << endl;
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
