#include "bits/stdc++.h"

using namespace std;

using ll = long long;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    int n, m, a = 0, b = 0;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        a = max(a, x);
    }
    cin >> m;
    for (int i = 0; i < m; i++) {
        int x; cin >> x;
        b = max(b, x);
    }

    cout << a << " " << b << endl;

    return 0;
}
