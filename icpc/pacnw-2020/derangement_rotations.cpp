#include "bits/stdc++.h"

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);


    int n, p; cin >> n >> p;
    vector<int64_t> pow2(n + 1);
    pow2[0] = 1;
    for (int i = 1; i <= n; i++) {
        pow2[i] = (pow2[i - 1] * 2) % p;
    }

    int64_t ans = 0;
    vector<int64_t> cnt(n + 1);
    for (int ord = 2; ord <= n / 2; ord++) {
        if (n % ord == 0) {
            int64_t x = pow2[ord - 1] - 1;
            for (int d = 2; d <= ord / 2; d++) {
                if (ord % d == 0) {
                    x = (x - cnt[d] + p) % p;
                }
            }
            cnt[ord] = x;
            x = x * (n / ord - 1) % p;
            ans = (ans + x) % p;
        }
    }
    ans = ans * (n - 2) % p;
    cout << ans << '\n';

    return 0;
}