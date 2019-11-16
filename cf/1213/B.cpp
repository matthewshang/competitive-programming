#include "bits/stdc++.h"

using namespace std;

using ll = long long;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        vector<int> a(n); for (int& x : a) cin >> x;

        int ans = 0;
        int mx = INT_MAX;
        for (int i = n - 1; i >= 0; i--) {
            if (a[i] > mx) {
                ans++;
            }
            mx = min(mx, a[i]);
        }
        cout << ans << endl;
    }

    return 0;
}
