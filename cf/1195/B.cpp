#include "bits/stdc++.h"

using namespace std;

using ll = long long;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    int n, k; cin >> n >> k;
    int lo = 1, hi = n;
    while (lo <= hi) {
        ll m = (lo + hi) / 2;
        ll val = m * (m + 1) / 2 - (n - m);
        if (val > k) {
            hi = m - 1;
        } else if (val < k) {
            lo = m + 1;
        } else {
            lo = hi = m;
            break;
        }
    }
    cout << n - lo << endl;

    return 0;
}
