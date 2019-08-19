#include "bits/stdc++.h"

using namespace std;

using ll = long long;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    int n; cin >> n;
    vector<int> a(n); for (int& x : a) cin >> x;

    ll ans = 0;
    int neg = 0;
    bool zero = false;
    for (int i = 0; i < n; i++) {
        if (a[i] == 0) zero = true;
        if (a[i] >= 0) {
            ans += abs(a[i] - 1);
        } else {
            ans += abs(a[i] + 1);
            neg++;
        }
    }

    if (neg % 2 != 0 && !zero) {
        ans += 2;
    }
    cout << ans << endl;

    return 0;
}
