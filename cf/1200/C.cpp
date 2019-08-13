#include "bits/stdc++.h"

using namespace std;

using ll = long long;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    ll n, m; cin >> n >> m;
    int q; cin >> q;

    ll g = __gcd(n, m);
    n /= g; m /= g;

    while (q--) {
        ll sx, sy, ex, ey; cin >> sx >> sy >> ex >> ey;
        bool ans;
        if (sx == 1 && ex == 1) {
            ans = ((sy - 1) / n) == ((ey - 1) / n);
        } else if (sx == 2 && ex == 2) {
            ans = ((sy - 1) / m) == ((ey - 1) / m);
        } else if (sx == 1 && ex == 2) {
            ans = ((sy - 1) / n) == ((ey - 1) / m);
        } else {
            ans = ((sy - 1) / m) == ((ey - 1) / n);
        }
        cout << (ans ? "YES\n" : "NO\n");
    }

    return 0;
}
