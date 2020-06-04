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

    int t; cin >> t;
    while (t--) {
        int n, m; cin >> n >> m;
        vll a(n, 0);
        F0R (i, n) {
            string s; cin >> s;
            F0R (j, m) {
                if (s[m - j - 1] == '1')
                    a[i] += (1LL << j);
            } 
        }
        sort(all(a));
        
        ll x = ((1LL << m) - n - 1) / 2;
        F0R (i, n) {
            if (a[i] <= x)
                x++;
        }
        
        F0R (i, m) {
            ll mask = (1LL << (m - i - 1));
            cout << (x & mask ? '1' : '0');
        }
        cout << nl;
    }

    return 0;
}
