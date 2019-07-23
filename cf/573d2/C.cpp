#include "bits/stdc++.h"

using namespace std;

using ll = long long;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    // cout << "100000000000000000 100000 10000000000000000\n";
    // for (int i = 0; i < 100000; i++) {
    //     cout << 781 * (ll)i + 4 << " ";
    // }

    ll n, m, k; cin >> n >> m >> k;
    vector<ll> p(m);
    for (int i = 0; i < m; i++) cin >> p[i];

    int ans = 0;
    int s = 0;
    int e = 0;
    ll found = 0;
    ll page = k;
    while (found < m && s < m && e < m) {
        // while (p[s] - found > page) {
        //     page += k;
        // }
        if (p[s] - found > page) {
            if ((p[s] - found) % k == 0) page = p[s] - found;
            else page = p[s] - found - (p[s] - found) % k + k;
        }
        while (e < m && p[e] - found <= page) {
            e++;
        }
        found += e - s;
        ans++;
        s = e;
    }
    cout << ans << endl;
    return 0;
}
