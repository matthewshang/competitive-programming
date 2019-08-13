#include "bits/stdc++.h"

using namespace std;

using ll = long long;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    int n; cin >> n;
    vector<int> a(n); for (int& x : a) cin >> x;
    vector<int> b(n, 0);
    vector<int> m;
    int q; cin >> q;
    while (q--) {
        int e; cin >> e;
        if (e == 1) {
            int p, x; cin >> p >> x;
            a[p - 1] = x;
            b[p - 1] = m.size();
        } else {
            int x; cin >> x;
            m.push_back(x);
        }
    }

    vector<int> pre(m.size() + 1);
    pre[m.size()] = 0;
    for (int i = m.size() - 1; i >= 0; i--) {
        pre[i] = max(pre[i + 1], m[i]);
    }

    for (int i = 0; i < n; i++) {
        int val = max(a[i], pre[b[i]]);
        cout << val << " ";
    }
    cout << endl;

    return 0;
}
