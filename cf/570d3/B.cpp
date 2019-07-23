#include "bits/stdc++.h"

using namespace std;

using ll = long long;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    int q; cin >> q;
    while (q--) {
        int n, k; cin >> n >> k;
        int lo = 0, hi = 1 << 30;
        for (int i = 0; i < n; i++) {
            int a; cin >> a;
            lo = max(lo, a - k);
            if (lo > hi) {
                cout << -1 << endl;
                break;
            }
            hi = min(hi, a + k);
        }
        if (lo <= hi) cout << hi << endl;
    }
    return 0;
}
