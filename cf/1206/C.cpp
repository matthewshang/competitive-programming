#include "bits/stdc++.h"

using namespace std;

using ll = long long;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    int n; cin >> n;
    if (n % 2 == 0) {
        cout << "NO\n";
        return 0;
    }

    vector<int> a(2 * n);
    a[0] = 1;
    a[n] = 2;
    int mx = 2;
    for (int i = 1; i < n; i++) {
        if (i % 2) {
            a[i] = mx + 2;
            a[i + n] = mx + 1;
        } else {
            a[i] = mx + 1;
            a[i + n] = mx + 2;
        }
        mx += 2;
    }

    cout << "YES\n";
    for (int x : a) cout << x << " ";
    cout << endl;

    return 0;
}
