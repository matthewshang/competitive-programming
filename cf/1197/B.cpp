#include "bits/stdc++.h"

using namespace std;

using ll = long long;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    int n; cin >> n;
    int mx = 0;
    vector<int> a(n); for (int& x : a) {
        cin >> x;
        mx = max(mx, x);
    }

    int i = 0;
    for (; i < n - 1; i++) {
        if (a[i] == mx) break;
        if (a[i] >= a[i + 1]) {
            cout << "NO\n";
            return 0;
        }
    }

    for (; i < n - 1; i++) {
        if (a[i] <= a[i + 1]) {
            cout << "NO\n";
            return 0;
        }
    }

    cout << "YES\n";

    return 0;
}
