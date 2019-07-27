#include "bits/stdc++.h"

using namespace std;

using ll = long long;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    int q; cin >> q;
    while (q--) {
        ll a, b, c; cin >> a >> b >> c;
        if (a > c) swap(a, c);
        if (a > b) swap(a, b);
        if (b > c) swap(b, c);

        cout << (a + b + c) / 2 << endl;
    }

    return 0;
}
