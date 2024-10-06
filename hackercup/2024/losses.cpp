#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    constexpr int64_t MOD = 998244353;

    int T;
    cin >> T;
    for (int tt = 1; tt <= T; tt++) {
        int64_t W, G, L; 
        cin >> W >> G >> L;

        if (L == 0) {
            cout << "Case #" << tt << ": " << (W - G) % MOD << "\n";
        } else {
            int64_t ans = (2 * L) % MOD;
            ans = (ans + 1) % MOD;
            ans = (ans * ((W - G) % MOD)) % MOD;
            cout << "Case #" << tt << ": " << ans << "\n";
        }
    }
}