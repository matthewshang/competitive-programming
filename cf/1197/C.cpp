#include "bits/stdc++.h"

using namespace std;

using ll = long long;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    int n, k; cin >> n >> k;
    vector<int> a(n); for (int& x : a) cin >> x;

    vector<int> gap(n - 1);
    for (int i = 0; i < n - 1; i++) {
        gap[i] = a[i + 1] - a[i];
    }
    sort(gap.begin(), gap.end());
    int ans = 0;
    for (int i = 0; i < n - k; i++) {
        ans += gap[i];
    }
    cout << ans << endl;

    return 0;
}
