#include "bits/stdc++.h"

using namespace std;

using ll = long long;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    int w, h, x, y; cin >> w >> h >> x >> y;
    cout << ((double)w * h / 2.0) << " ";
    if (2 * x == w && 2 * y == h) cout << "1\n";
    else cout << "0\n";
    return 0;
}
