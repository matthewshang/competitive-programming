#include "bits/stdc++.h"

using namespace std;

using ll = long long;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    int p, q, r; cin >> p >> q >> r;
    cout << min(p + q, min(q + r, r + p)) << endl;

    return 0;
}
