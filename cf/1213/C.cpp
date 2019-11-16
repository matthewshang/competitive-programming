#include "bits/stdc++.h"

using namespace std;

using ll = long long;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    int Q; cin >> Q;
    while (Q--) {
        ll n, m; cin >> n >> m;

        ll d = m % 10;
        ll sum = d;
        ll sz = 1;
        while (((sz + 1) * d) % 10 != d) {
            sum += ((sz + 1) * d) % 10;
            sz++;
        }
        
        ll ans = (n / (sz * m)) * sum;
        ll i = (n / (sz * m)) * (sz * m) + m;
        while (i <= n) {
            ans += i % 10;
            i += m;
        }

        cout << ans << endl;
    }

    return 0;
}
