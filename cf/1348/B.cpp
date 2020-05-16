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
        int n, k; cin >> n >> k;
        vi a(n);
        F0R (i, n) cin >> a[i];

        set<int> uni;
        F0R (i, n) uni.insert(a[i]);
        if (uni.size() > k) {
            cout << "-1\n";
            continue;
        }
        vi u;
        for (int x : uni) u.pb(x);
        while (sz(u) < k) u.pb(a[0]);

        vi b;
        int i = 0, j = 0;
        while (i < n) {
            if (a[i] == u[j]) {
                b.pb(a[i]);
                i++;
            } else {
                b.pb(u[j]);
            }
            j = (j + 1) % k;
        }

        cout << sz(b) << endl;
        F0R (i, sz(b)) cout << b[i] << " ";
        cout << endl;
    }

    return 0;
}