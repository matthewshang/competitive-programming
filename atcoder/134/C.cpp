#include "bits/stdc++.h"

using namespace std;

using ll = long long;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    int n; cin >> n;
    vector<int> a(n); for (int& x : a) cin >> x;
    vector<int> b = a;
    sort(a.begin(), a.end());

    for (int i = 0; i < n; i++) {
        if (b[i] == a[n - 1]) cout << a[n - 2] << endl;
        else cout << a[n - 1] << endl;
    }

    return 0;
}
