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

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    int w, h; cin >> w >> h;
    cout << power(2, w + h) << endl;

    return 0;
}
