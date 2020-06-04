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

void solve() {
    int n, m; cin >> n >> m;
    vector<string> a(n);
    F0R (i, n)
        cin >> a[i];

    F0R (i, m) {
        string s = a[0];
        F0R (j, 26) {
            s[i] = (char)('a' + j);
            bool ok = true;
            FOR (k, 1, n - 1) {
                int diff = 0;
                F0R (l, m)
                    if (a[k][l] != s[l])
                        diff++;
                if (diff > 1) {
                    ok = false;
                    break;
                }
            }

            if (ok) {
                cout << s << nl;
                return;
            }
        }
    }
    cout << "-1\n";
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);

    int t; cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
