#include "bits/stdc++.h"

using namespace std;

using ll = long long;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    int n; cin >> n;
    int h[n][2];    
    for (int i = 0; i < n; i++) cin >> h[i][0];
    for (int i = 0; i < n; i++) cin >> h[i][1];

    ll m0 = h[0][0], m1 = h[0][1];
    for (int i = 1; i < n; i++) {
        ll a = h[i][0] + m1;
        ll b = h[i][1] + m0;
        m0 = max(m0, a);
        m1 = max(m1, b);
    }
    cout << max(m0, m1) << endl;
    return 0;
}
