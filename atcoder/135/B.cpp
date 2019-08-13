#include "bits/stdc++.h"

using namespace std;

using ll = long long;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    int n; cin >> n;
    vector<int> p(n); for (int& x : p) cin >> x;
    vector<int> q = p;
    sort(q.begin(), q.end());

    int cnt = 0;
    for (int i = 0; i < n; i++) if (p[i] != q[i]) cnt++;
    cout << ((cnt > 2) ? "NO" : "YES") << endl;

    return 0;
}
