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
    int r, s; cin >> r >> s;
    if (s == 2) {
        cout << (r - 1) << endl;
        int i = r;
        while (i >= 2) {
            cout << i << " " << (i - 1) << endl;
            i--;
        }
    } else if (s == 3) {
        if (r == 2) {
            cout << "2\n2 3\n2 2\n";
        } else if (r == 3) {
            cout << "4\n3 2\n6 2\n2 3\n2 2\n";
            // (1, 1) (2, 1) (3, 1) (1, 2) (2, 2) (3, 2) (1, 3) (2, 3) (3, 3)
            // 3 2
            // (1, 2) (2, 2) (1, 1) (2, 1) (3, 1) (3, 2) (1, 3) (2, 3) (3, 3)
            // 6 2
            // (1, 3) (2, 3) (1, 2) (2, 2) (1, 1) (2, 1) (3, 1) (3, 2) (3, 3)
            // 2 3
            // (1, 2) (2, 2) (1, 1) (1, 3) (2, 3) (2, 1) (3, 1) (3, 2) (3, 3)
            // 2 2
        } else {
            cout << "6\n8 3\n7 3\n3 2\n6 2\n2 3\n2 2\n";
            // (1, 1) (2, 1) (3, 1) (4, 1)(1, 2) (2, 2) (3, 2) (4, 2) (1, 3) (2, 3) (3, 3) (4, 3)
            // (1, 3) (2, 3) (3, 3) (1, 1) (2, 1) (3, 1) (4, 1)(1, 2) (2, 2) (3, 2) (4, 2) (4, 3)
            // (1, 2) (2, 2) (3, 2) (1, 3) (2, 3) (3, 3) (1, 1) (2, 1) (3, 1) (4, 1)(4, 2) (4, 3)
        }
    } else if (s == 4) {
        if (r == 2) {
            cout << "3\n6 1\n5 1\n4 1\n";
            // (1, 1) (2, 1) (1, 2) (2, 2) (1, 3) (2, 3) (1, 4) (2, 4)
            // (1, 4) (1, 1) (2, 1) (1, 2) (2, 2) (1, 3) (2, 3) (2, 4)
            // (1, 3) (1, 4) (1, 1) (2, 1) (1, 2) (2, 2) (2, 3) (2, 4)
        } else {
            cout << "7\n9 2\n8 2\n7 2\n6 1\n5 1\n4 1\n3 1\n";
            // (1, 1) (2, 1) (3, 1)(1, 2) (2, 2) (3, 2) (1, 3) (2, 3) (3, 3)(1, 4) (2, 4) (3, 4)
            // (1, 4) (2, 4)(1, 1) (2, 1) (3, 1)(1, 2) (2, 2) (3, 2) (1, 3) (2, 3) (3, 3) (3, 4)
            // (1, 3) (2, 3)(1, 4) (2, 4)(1, 1) (2, 1) (3, 1)(1, 2) (2, 2) (3, 2)  (3, 3) (3, 4)
            // (1, 2) (2, 2) (1, 3) (2, 3)(1, 4) (2, 4)(1, 1) (2, 1) (3, 1)(3, 2)  (3, 3) (3, 4)
        }
    } else if (s == 5) {
        cout << "4\n8 1\n7 1\n6 1\n5 1\n";
        // (1, 4) (1, 5)(1, 1) (2, 1) (1, 2) (2, 2) (1, 3) (2, 3)(2, 4)( 2, 5)
    } else if (s == 6) {
        cout << "5\n10 1\n9 1\n8 1\n7 1\n6 1\n";
        // (1, 1)(2, 1)(1,2)(2,2)
    } else {

        cout << "6\n12 1\n11 1\n10 1\n9 1\n8 1\n7 1\n";
    }

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
