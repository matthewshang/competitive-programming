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

    // 3: 1 2 1
    // 7: 1 2 1 3 2 3 1
    // 4: 1 2 1 3 1 4 2 3 2 4 3 4 1
    // 6 + 4 + 2 + ... 2 * (n - 1) + ... + 2 * (n - m) <= l
    // (2 * n - 1 - m) * m <= l
    //    1 4 3 4 2 3 2 4 1 3 1 2 1
    //21: 1 2 1 3 2 3 1 4 2 4 3 4 1 5 2 5 3 5 4 5 1

    //
    // l(n) = 1 + n(n - 1)

    int t; cin >> t;
    while (t--) {
        ll n, l, r; cin >> n >> l >> r;
        ll m = 0;
        ll start = 0;
        while (m < n && start + 2 * (n - m - 1) < l) {
            start += 2 * (n - m - 1);
            m++;
        }
        ll cur = l;
        while (cur <= r) {
            if (cur == 1 + n * (n - 1)) {
                cout << "1";
                break;
            }
            if ((cur - start) % 2 == 1) {
                cout << (m + 1) << " ";
            } else {
                ll i = (cur - start) / 2 + m + 1;
                cout << i << " ";
                if (i == n) {
                    m++;
                    start = cur;
                }
            }
            cur++;
        }
        cout << endl;
    }

    return 0;
}