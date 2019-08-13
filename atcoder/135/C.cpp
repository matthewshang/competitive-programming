#include "bits/stdc++.h"

using namespace std;

using ll = long long;

ll defeat(int& l, int& h) {
    if (l > h) {
        l -= h;
        int val = h;
        h = 0;
        return val;
    } else {
        h -= l;
        int val = l;
        l = 0;
        return val;
    }
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    int n; cin >> n;
    vector<int> a(n + 1); for (int& x : a) cin >> x;
    vector<int> b(n); for (int& x : b) cin >> x;

    ll ans = 0;
    for (int i = 0; i < n; i++) {
        ans += defeat(a[i], b[i]);
        ans += defeat(a[i + 1], b[i]);
    }
    cout << ans << endl;
    return 0;
}
