#include "bits/stdc++.h"

using namespace std;

using ll = long long;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    int n, m, k; cin >> n >> m >> k;
    vector<int> a(n); for (int& x : a) cin >> x;
    vector<ll> pre(n + 1); 
    pre[0] = 0;
    for (int i = 1; i <= n; i++) {
        pre[i] = pre[i - 1] + a[i - 1];
    }

    ll ans = 0;
    if (m == 1) {
        ll left = 0;
        for (int i = 1; i <= n; i++) pre[i] -= (ll)k * i;
        for (int i = 0; i < n; i++) {
            ans = max(ans, pre[i + 1] - left);
            left = min(left, pre[i + 1]);
        }
        cout << ans << endl;
        return 0;
    }

    vector<ll> best(n, 0);
    for (int i = 0; i < n; i++) {
        if (i >= m) {
            ll cur = best[i - m] - k + pre[i + 1] - pre[i - m + 1];
            ans = max(cur, ans);
            best[i] = max(best[i], cur);
        }

        ll left = pre[i];
        for (int j = 0; j < m && i + j < n; j++) {
            ll cur = pre[i + j + 1] - left - k;
            ans = max(ans, cur);
            best[i + j] = max(best[i + j], cur);
            left = min(left, pre[i + j + 1]);
        }
    }
    // for (auto x : best) cout << x << " ";
    // cout << endl;
    cout << ans << endl;
    return 0;
}
