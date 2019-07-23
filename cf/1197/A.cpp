#include "bits/stdc++.h"

using namespace std;

using ll = long long;

void solve() {
    int n; cin >> n;
    vector<int> a(n); for (int& x : a) cin >> x;

    sort(a.begin(), a.end());

    for (int i = n - 1; i >= 2; i--) {
        int k = min(i - 1, min(a[i] - 1, a[i - 1] - 1));
        if (k + 2 > i + 1) continue;
        else {
            cout << k << endl;
            return;
        }
    }
    cout << 0 << endl;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    int T; cin >> T;
    while (T--) {
        solve();
    }

    return 0;
}
