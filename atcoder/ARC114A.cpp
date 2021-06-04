#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<int> primes;
    for (int i = 2; i <= 50; i++) {
        bool prime = true;
        for (int j = 2; j * j <= i; j++) {
            if (i % j == 0) {
                prime = false;
            }
        }
        if (prime) {
            primes.push_back(i);
        }
    }
    int M = primes.size();

    int N; cin >> N;
    vector<int> X(N);
    for (int i = 0; i < N; i++) {
        cin >> X[i];
    }

    int64_t best = 1e18;
    for (int mask = 0; mask < (1 << M); mask++) {
        int64_t Y = 1;
        for (int i = 0; i < M; i++) {
            if (mask & (1 << i)) {
                Y *= primes[i];
            }
        }
        bool good = true;
        for (int i = 0; i < N; i++) {
            if (gcd(X[i], Y) == 1) {
                good = false;
            }
        }

        if (good) {
            best = min(best, Y);
        }
    }
    cout << best << '\n';

    return 0;
}
