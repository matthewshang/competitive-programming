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

ll power(ll a, ll b) {
    ll x = 1, y = a;
    while (b) {
        if (b % 2) x = (x * y) % MOD;
        y = (y * y) % MOD;
        b /= 2;
    }
    return x % MOD;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);

    int t; cin >> t;
    while (t--) {
        int n, p; cin >> n >> p;
        vi k(n);
        F0R (i, n)
            cin >> k[i];
        
        if (p == 1) {
            cout << (n % 2 ? 1 : 0) << nl;
            continue;
        }
        sort(all(k), [&](int i, int j) { return i > j; });

        int max_d = 0;
        {
            ll q = 1;
            while (q < n) {
                q *= p;
                max_d++;
            }
        }

        ll s = 0;
        ll v = 1;
        bool too_big = false;
        F0R (i, n) {
            int add = 1;
            if (too_big || s > 0) {
                s = (s - power(p, k[i]) + MOD) % MOD;
                add = -1;
            } else {
                s = power(p, k[i]);
            }

            if (!too_big && i > 0) {
                if (v > 0 && k[i - 1] - k[i] >= max_d)
                    too_big = true;
                if (!too_big) {
                    v = v * power(p, k[i - 1] - k[i]) + add;
                    if (v > n)
                        too_big = true;
                }
            }
        }
        cout << s << nl;
    }
    return 0;
}
