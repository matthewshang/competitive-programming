#include "bits/stdc++.h"

using namespace std;

using ll = long long;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    int n, x, y; cin >> n >> x >> y;
    vector<int> a(n); for (int& x : a) cin >> x;

    for (int i = 0; i < n; i++) {
        bool good = true;
        for (int j = i - 1; j >= i - x && j >= 0; j--) {
            if (a[i] > a[j]) {
                good = false;
                break;
            }
        }
        for (int j = i + 1; j <= i + y && j < n; j++) {
            if (a[i] > a[j]) {
                good = false;
                break;
            }
        }
        if (good) {
            cout << i + 1 << endl;
            break;
        }
    }

    return 0;
}
