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

    ll k; cin >> k;

    ll m = floor(pow(k, 0.1));
    ll cur = 1;
    F0R (i, 10) cur *= m;
    ll add = 0;
    while (cur < k) {
        cur /= m;
        cur *= m + 1;
        add++;
    }

    const string CF = "codeforces";
    string ans = "";
    F0R (i, 10 - add) {
        F0R (j, m) {
            ans += CF[i];
        }
    }
    F0R (i, add) {
        F0R (j, m + 1) {
            ans += CF[10 - add + i];
        }
    }
    cout << ans << nl;

    return 0;
}
