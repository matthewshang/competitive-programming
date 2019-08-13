#include "bits/stdc++.h"

using namespace std;

using ll = long long;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    int n, d; cin >> n >> d;
    cout << n / (2 * d + 1) + (n % (2 * d + 1) > 0) << endl;

    return 0;
}
