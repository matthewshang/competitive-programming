#include "bits/stdc++.h"

using namespace std;

using ll = long long;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    int T; cin >> T;
    while (T--) {
        int b, p, f; cin >> b >> p >> f;
        int h, c; cin >> h >> c;

        int ans = 0;
        if (h > c) {
            int n = min(b / 2, p);
            ans += n * h;
            b -= n * 2;
            n = min(b / 2, f);
            ans += n * c;
        } else {
            int n = min(b / 2, f);
            ans += n * c;
            b -= n * 2;
            n = min(b / 2, p);
            ans += n * h;
        }
        cout << ans << endl;
    }

    return 0;
}
