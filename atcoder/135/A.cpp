#include "bits/stdc++.h"

using namespace std;

using ll = long long;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    ll a, b; cin >> a >> b;
    if (a % 2 != b % 2) {
        cout << "IMPOSSIBLE\n";
    } else {
        cout << (a + b) / 2 << endl;
    }

    return 0;
}
