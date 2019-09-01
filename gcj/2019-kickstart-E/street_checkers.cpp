#include "bits/stdc++.h"

using namespace std;

using ll = long long;

random_device dev;
mt19937 rng(dev());
uniform_int_distribution<unsigned long long> dist(1, ULLONG_MAX);

ll power(ll a, ll b, ll p) {
    ll x = 1, y = a;
    while (b > 0) {
        if (b % 2) x = (x * y) % p;
        y = (y * y) % p;
        b /= 2;
    }
    return x % p;
}

bool miller_test(ll d, ll n) {
    ll a = 2 + dist(rng) % (n - 4);
    ll x = power(a, d, n);

    if (x == 1 || x == n - 1)
        return true;

    while (d != n - 1) {
        x = (x * x) % n;
        d *= 2;

        if (x == 1) return false;
        if (x == n - 1) return true;
    }

    return false;
}

bool is_prime(ll n, ll k) {
    if (n <= 1 || n == 4) return false;
    if (n <= 3) return true;

    ll d = n - 1;
    while (d % 2 == 0)
        d /= 2;

    for (int i = 0; i < k; i++)
        if (!miller_test(d, n))
            return false;

    return true;
}

void solve(int test_case) {
    int L, R; cin >> L >> R;
    int ans = 0;
    for (int i = L; i <= R; i++) {
        if (i == 1 || i == 4 || i == 8) {
            ans++;
        } else if (i % 4 == 2) {
            ans++;
        } else if (i != 2 && is_prime(i, 10)) {
            ans++;
        } else if (i % 4 == 0 && is_prime(i / 4, 10)) {
            ans++;
        }
    }
    
    cout << "Case #" << test_case << ": " << ans << endl;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    int T; cin >> T;
    for (int t = 1; t <= T; t++) {
        solve(t);
    }

    return 0;
}
