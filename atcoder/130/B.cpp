#include "bits/stdc++.h"

using namespace std;

using ll = long long;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    int n, x; cin >> n >> x;
    vector<int> l(n); for (int& y : l) cin >> y;
    int d = 0, i = 0;
    while (i < n && d <= x) {
        d += l[i];
        i++;
    }
    if (d <= x) i++;
    cout << i << endl;
    return 0;
}

