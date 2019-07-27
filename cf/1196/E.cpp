#include "bits/stdc++.h"

using namespace std;

using ll = long long;

const int MX = 1000000000;

void pr(int x, int y) {
    cout << x << " " << y << endl;
}

void solve() {
    int b, w; cin >> b >> w;
    int ord = b > w;
    if (b > w) swap(b, w);
    if (w > 1 + 3 * b) {
        cout << "NO\n";
        return;
    }

    cout << "YES\n";
    for (int i = 0; i < b; i++) {
        pr(3 + 2 * i, 2 + ord);
    }

    int rem = w;
    for (int i = 0; i < b; i++) {
        pr(2 + 2 * i, 2 + ord);
        rem--;
    }

    if (rem > 0) {
        pr(2 + 2 * b, 2 + ord);
        rem--;
    }

    if (rem > 0) {
        int l = min(b, rem);
        for (int i = 0; i < l; i++) {
            pr(3 + 2 * i, 1 + ord);
            rem--;
        }
    }

    if (rem > 0) {
        int l = min(b, rem);
        for (int i = 0; i < l; i++) {
            pr(3 + 2 * i, 3 + ord);
            rem--;
        }
    }
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    int q; cin >> q;
    while (q--) {
        solve();
    }

    return 0;
}
