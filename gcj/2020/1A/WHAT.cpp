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
    // int n; cin >> n;
    ll pas[100][100];
    F0R (i, 100) {
        pas[i][0] = 1;
        pas[i][i] = 1;
        if (i <= 1) continue;
        FOR (j, 1, i - 1) {
            pas[i][j] = pas[i - 1][j - 1] + pas[i - 1][j];
        }
    }
    // F0R (i, 20) {
    //     F0R (j, i+1) cout << pas[i][j] << " ";
    //     cout << endl;
    // }
    FOR (n, 2, 501) {
    int target = n - (__lg(n) + 1);
    int actual = target + (__lg(target) + 1) - __builtin_popcount(target);
    if (target < 0 || actual <= 0) {
        cout << "POPO " << n << endl;
    }

    if (n == 1) {
        cout << "1 1\n";
        return;
    }

    vpi ans;
    bool right = true;
    // cout << target << " " << actual << endl;
    F0R (i, __lg(target) + 1) {
        if (right) {
            ans.emplace_back(i + 1, i + 1);
        } else {
            ans.emplace_back(i + 1, 1);
        }

        if ((1 << i) & target) {
            if (right) {
                F0R (j, i) {
                    ans.emplace_back(i + 1, i - j);
                }
            } else {
                F0R (j, i) {
                    ans.emplace_back(i + 1, 2 + j);
                }
            }
            right = !right;
        }
    }
    F0R (i, n - actual) {
        int j = __lg(target) + i + 2;
        ans.emplace_back(j, right ? j : 1);
    }

    int asdf = 0;
    F0R (i, sz(ans)) {
        // cout << ans[i].F << " " << ans[i].S << nl;
        asdf += pas[ans[i].F - 1][ans[i].S - 1];
    }
    F0R (i, sz(ans) - 1) {
        int r1 = ans[i].F, r2 = ans[i+1].F, c1=ans[i].S,c2=ans[i+1].S;
        if ((r2 == r1 - 1 && c2 == c1 - 1) ||
            (r2 == r1 - 1 && c2 == c1) ||
            (r2 == r1 && c2 == c1 - 1) ||
            (r2 == r1 && c2 == c1 + 1) ||
            (r2 == r1 + 1 && c2 == c1) ||
            (r2 == r1 + 1 && c2 == c1 + 1)) {

            } else {
                cout << "HUH\n";
            }
    }
    if (asdf != n) {
        cout << "WERT " << n << " " << asdf << endl;
    }
    // cout << sz(ans) << endl;
    if (sz(ans) > 500) {
        cout << n << endl;
    }
    }
    // cout << sz(ans) << endl;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    solve();

    // int t; cin >> t;
    // FOR (i, 1, t) {
    //     cout << "Case #" << i << ":\n";
    //     solve();
    // }

    return 0;
}