#include "bits/stdc++.h"

using namespace std;

using ll = long long;

void solve() {
    int n, k; cin >> n >> k;
    vector<ll> a(n); for (ll& x : a) cin >> x;

    vector<ll> odd;
    for (int i = 0; i < n; i++) {
        if (a[i] % 2 == 1) {
            odd.push_back(i + 1);
        }
    }
    if (odd.size() % 2 != k % 2 || k > odd.size()) {
        cout << "NO\n";
        return;
    }

    cout << "YES\n";
    int st = 1;
    for (int i = 0; i < k - 1; i++) {
        if (i == 0) {
            if (odd[0] == 1) cout << 1 << " ";
            else cout << odd[0] << " ";
        } else {
            cout << odd[i] << " ";
        }
    }
    cout << n;
    cout << endl;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    int q; cin >> q;
    while (q--) {
        solve();
    }

    return 0;
}
