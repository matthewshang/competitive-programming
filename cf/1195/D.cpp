#include "bits/stdc++.h"

using namespace std;

using ll = long long;

const ll MOD = 998244353;

ll power(ll a, ll b) {
    ll x = 1, y = a;
    while (b > 0) {
        if (b % 2) x = (x * y) % MOD;
        y = (y * y) % MOD;
        b /= 2;
    }
    return x % MOD;
}

int len(ll n) {
    return (int)log10((double)n) + 1;
}

ll tenpow[11] = {
    1, 10, 100, 1000, 10000, 100000, 1000000, 10000000,
    100000000, 1000000000, 10000000000
};
int digit(ll n, int i) {
    return (n / tenpow[i]) % 10;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    int n; cin >> n;
    vector<ll> a(n); for (auto& x : a) cin >> x;
    vector<int> l(n); for (int i = 0; i < n; i++) l[i] = len(a[i]);

    vector<ll> cnt(11, 0);
    for (int i = 0; i < n; i++) {
        cnt[l[i]]++;
    }

    ll ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 1; j <= 10; j++) {
            if (cnt[j] == 0) continue;
            ll tmp = 0;
            int d = min(j, l[i]);
            for (int k = 0; k < d; k++) {
                tmp = (tmp + digit(a[i], k) * 11 * power(10, 2 * k)) % MOD;
            }
            tmp = (tmp * cnt[j]) % MOD;
            ans = (ans + tmp) % MOD;
            tmp = 0;
            for (int k = d; k < l[i]; k++) {
                tmp = (tmp + digit(a[i], k) * power(10, k + d)) % MOD;
            }
            tmp = (tmp * cnt[j] * 2) % MOD;
            ans = (ans + tmp) % MOD;
        }
    }
    cout << ans << endl;

    return 0;
}
