#include "bits/stdc++.h"

using namespace std;

using ll = long long;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    int T; cin >> T;
    while (T--) {
        string x, y; cin >> x >> y;
        reverse(x.begin(), x.end());
        reverse(y.begin(), y.end());
        int i = 0;
        while (y[i] == '0') i++;
        int j = i;
        while (x[j] == '0') j++;
        cout << (j - i) << endl;
    }

    return 0;
}
