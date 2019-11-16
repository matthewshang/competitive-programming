#include "bits/stdc++.h"

using namespace std;

using ll = long long;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    int n; cin >> n;
    int odd = 0;
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        odd += x % 2;
    }
    cout << min(odd, n - odd) << endl;

    return 0;
}
