#include "bits/stdc++.h"

using namespace std;

using ll = long long;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin >> n;
    vector<int> w(n); for (int& x : w) cin >> x;
    vector<int> pre(n + 1);
    pre[0] = 0;
    for (int i = 1; i <= n; i++) {
        pre[i] = pre[i - 1] + w[i - 1];
    }
    int ans = INT_MAX;
    for (int i = 1; i < n; i++) {
        ans = min(ans, abs(pre[n] - 2 * pre[i]));
    }
    cout << ans << endl;

    return 0;
}
