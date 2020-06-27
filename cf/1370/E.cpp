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

    int n; cin >> n;
    string s, t; cin >> s >> t;

    int count = 0;
    F0R (i, n) if (s[i] == '1') count++;
    F0R (i, n) if (t[i] == '1') count--;
    if (count != 0) {
        cout << -1 << nl;
        return 0;
    }

    string a = "";
    F0R (i, n) {
        if (s[i] != t[i]) {
            a += s[i];
        }
    }
    
    n = sz(a);
    s = a;
    int o = 0, z = 0;
    F0R (i, n) {
        if (s[i] == '0') {
            if (z == 0) {
                o++;
            } else {
                z--;
                o++;
            }
        } else {
            if (o == 0) {
                z++;
            } else {
                o--;
                z++;
            }
        }
    }
    cout << (o + z) << nl;

    return 0;
}
