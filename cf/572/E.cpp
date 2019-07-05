#include "bits/stdc++.h"

using namespace std;

using ll = long long;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    ll n, p, k; cin >> n >> p >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    map<ll, ll> mp;
    for (int i = 0; i < n; i++) {
        ll x = ((ll)a[i] * a[i]) % p;
        x = (x * a[i]) % p;
        x = (x - k + p) % p;
        x = (x * a[i]) % p;
        mp[x]++;
    }

    ll ans = 0;
    for (auto& x : mp) {
        ans += x.second * (x.second - 1) / 2;
    }
    cout << ans << endl;
    return 0;
}
