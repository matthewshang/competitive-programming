#include "bits/stdc++.h"

using namespace std;

using ll = long long;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    ll n, k; cin >> n >> k;
    vector<ll> a(n); for (ll& x : a) cin >> x;

    ll ans = 0, sum = 0;
    int l = 0, r = 0;
    while (l < n && r < n) {
        while (sum < k && r < n) {
            sum += a[r++];
        }
        if (r >= n && sum < k) break;
        ll cnt = n - r + 1;
        ans += cnt;
        while (sum >= k && l <= r) {
            sum -= a[l++]; 
            if (sum >= k) ans += cnt;
        }
    }
    cout << ans << endl;

    return 0;
}
