#include "bits/stdc++.h"

using namespace std;

using ll = long long;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    int n, I; cin >> n >> I;
    map<int, int> mp;
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        mp[x]++;
    }

    int k = 8 * I / n;
    vector<int> vals;
    for (auto [e, m] : mp) {
        vals.push_back(m);
    }
    if (n * ceil(log2(vals.size())) <= 8 * I) {
        cout << 0 << endl;
        return 0;
    }
    int u = vals.size();

    vector<int> pre(u + 1, 0);
    for (int i = 1; i <= u; i++) {
        pre[i] = pre[i - 1] + vals[i - 1];
    }

    int p = 1, q = 1;
    while (q <= u && n * ceil(log2(q)) <= 8 * I) q++;
    q--;

    int ans = INT_MAX;
    while (q <= u) {
        int ch = pre[u] - pre[q] + pre[p - 1];
        ans = min(ans, ch);
        q++; p++;
    }
    cout << ans << endl;
    return 0;
}
