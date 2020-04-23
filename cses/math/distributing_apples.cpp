#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using vi = vector<int>;
using vvi = vector<vector<int>>;
using vll = vector<long long>;
using pii = pair<int, int>;
using vpi = vector<pair<int, int>>;

#define f first
#define s second
#define pb push_back
#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()

#define FOR(i, a, b) for (int i=(a); i <=(b); i++)
#define F0R(i, a) for (int i=0; i < (a); i++)
#define RFOR(i, a, b) for (int i = (a); i >= b; i--)

const ll MOD = 1e9 + 7;

ll power(ll a, ll b) {
    ll x = 1, y = a;
    while (b > 0) {
        if (b % 2) x = (x * y) % MOD;
        y = (y * y) % MOD;
        b /= 2;
    }
    return x % MOD;
}

ll inv(ll a) {
    return power(a, MOD - 2);
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    vll fac(2e6 + 1);
    fac[0] = 1;
    FOR (i, 1, 2e6) fac[i] = (fac[i - 1] * (ll)i) % MOD;

    int n, m; cin >> n >> m;
    ll ans = (fac[n + m - 1] * inv(fac[n - 1])) % MOD;
    ans = (ans * inv(fac[m])) % MOD;
    cout << ans << '\n';

    return 0;
}
