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

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);

    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vi p(n), c(n);
        F0R (i, n) cin >> p[i] >> c[i];
        bool ok = true;
        F0R (i, n - 1) {
            if (!(p[i + 1] >= p[i] && c[i + 1] >= c[i])) ok = false;
            else if (p[i + 1] - p[i] < c[i + 1] - c[i]) ok = false;

        }
        F0R (i, n) if (c[i] > p[i]) ok = false;
        cout << (ok ? "YES" : "NO") << endl;
    }

    return 0;
}