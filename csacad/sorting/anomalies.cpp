#include "bits/stdc++.h"

using namespace std;

using ll = long long;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    int n, k; cin >> n >> k;
    vector<int> a(n); for (int& x : a) cin >> x;
    sort(a.begin(), a.end());

    int ans = 0;
    for (int i = 0; i < n; i++) {
        bool ano = true;
        if (i > 0 && a[i] - a[i - 1] <= k) ano = false;
        if (i < n - 1 && a[i + 1] - a[i] <= k) ano = false;
        if (ano) ans++;
    }
    cout << ans << endl;

    return 0;
}
