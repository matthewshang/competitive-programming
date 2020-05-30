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
// const ll MOD = 1e9 + 7;
const ll MOD = 998244353;
const ll INF = 1e18;

ll power(ll a, ll b) {
    ll x = 1, y = a;
    while (b > 0) {
        if (b % 2) x = (x * y) % MOD;
        y = (y * y) % MOD;
        b /= 2;
    }
    return x % MOD;
}

ll inv(ll n) {
    return power(n, MOD - 2);
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);

    int n, k; cin >> n >> k;

    vll fac(n + 1);
    fac[0] = 1;
    F0R (i, n)
        fac[i + 1] = (fac[i] * (i + 1)) % MOD;

    auto binom = [&](int n_, int k_) -> ll {
        return fac[n_] * inv(fac[k_]) % MOD * inv(fac[n_ - k_]) % MOD;
    };

    ll ans = 0;
    int base = 1;
    while (n / base >= k) {
        ans = (ans + binom(n / base - 1, k - 1)) % MOD;
        base++;
    }
    cout << ans << endl;

    return 0;
}
