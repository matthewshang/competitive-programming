#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using vi = vector<int>;
using vvi = vector<vector<int>>;
using vll = vector<long long>;
using pii = pair<int, int>;
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
    int target = n - (__lg(n) + 1);
    // if (target == 0) {
    //     F0R (i, n) cout << (i + 1) << " " << 1 << nl;
    //     return;
    // }

    int actual = target + (__lg(target) + 1) - __builtin_popcount(target);
    bool right = false;
    vpi ans;
    F0R (i, __lg(target) + 1) {
        ans.emplace_back(i + 1, right ? i + 1 : 1);
        if ((1 << i) & target) {
            F0R (j, i) ans.emplace_back(i + 1, right ? i - j : j + 2);
            right = !right;
        }
    }
    F0R (i, n - actual) {
        int j = __lg(target) + i + 2;
        ans.emplace_back(j, right ? j : 1);
    }

    F0R (i, sz(ans)) {
        cout << ans[i].F << " " << ans[i].S << endl;
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);

    int t; cin >> t;
    FOR (i, 1, t) {
        cout << "Case #" << i << ":" << endl;
        solve();
    }

    return 0;
}