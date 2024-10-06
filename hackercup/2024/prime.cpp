#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    constexpr int MAX = 1e7;
    vector<bool> is_prime(MAX + 1, true);
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i <= MAX; i++) {
        if (is_prime[i] && (int64_t)i * i <= MAX) {
            for (int j = i * i; j <= MAX; j += i) {
                is_prime[j] = false;
            }
        }
    }
    vector<int> primes;
    for (int i = 2; i <= MAX; i++) {
        if (is_prime[i]) {
            primes.push_back(i);
        }
    }

    int T;
    cin >> T;
    for (int tt = 1; tt <= T; tt++) {
        int N; cin >> N;

        int ans = 0;
        for (int i = 1; i < (int)primes.size() && primes[i] <= N; i++) {
            if (primes[i] - primes[i - 1] == 2) {
                ans += 1;
            }
        }
        if (ans > 0) {
            ans += 1;
        }

        cout << "Case #" << tt << ": " << ans << "\n";
    }
}