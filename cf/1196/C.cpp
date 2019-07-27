#include "bits/stdc++.h"

using namespace std;

using ll = long long;

void solve() {
    int n; cin >> n;
    const int INF = 100000;
    pair<int, int> mx = {-INF, INF}, my = {-INF, INF};
    for (int i = 0; i < n; i++) {
        int x, y; cin >> x >> y;
        bool L, U, R, D; cin >> L >> U >> R >> D;
        if (!L) mx.first = max(mx.first, x);
        if (!R) mx.second = min(mx.second, x);
        if (!D) my.first = max(my.first, y);
        if (!U) my.second = min(my.second, y);
    }
    if (mx.first > mx.second || my.first > my.second) {
        cout << "0\n";
        return;
    }

    cout << 1 << " " << mx.first << " " << my.first << endl;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    int q; cin >> q;
    while (q--) {
        solve();
    }

    return 0;
}
