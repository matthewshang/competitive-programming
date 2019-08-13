#include "bits/stdc++.h"

using namespace std;

using ll = long long;

void solve() {
    int n, m, k; cin >> n >> m >> k;
    vector<int> h(n); for (int& x : h) cin >> x;

    int i = 1;
    while (i < n) {
        if (h[i - 1] + m < h[i] - k) {
            cout << "NO\n";
            return;
        }

        if (h[i - 1] < h[i] - k) {
            m -= h[i] - k - h[i - 1];
        } else {
            m += h[i - 1] - max(0, h[i] - k);
        }

        i++;
    }

    cout << "YES\n";
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    int T; cin >> T;
    while (T--) {
        solve();
    }

    return 0;
}
