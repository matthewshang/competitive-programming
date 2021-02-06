#include "bits/stdc++.h"
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    constexpr long long MOD = 1e9 + 7;

    long long n; cin >> n;
    int d; cin >> d;

    if (d == 1) {
        int res = 1;
        int x = 2;
        while (n > 0) {
            if (n % 2) res = (long long)res * x % MOD;
            x = (long long)x * x % MOD;
            n /= 2;
        }
        cout << (res - 1) << '\n';
        return 0;
    }

    auto modmul = [&](vector<int>& a, vector<int>& b) -> vector<int> {
        vector<int> res(d);
        for (int i = 0; i < d; i++) {
            for (int j = 0; j < d; j++) {
                long long val = res[(i + j) % d] + (long long)a[i] * b[j] % MOD;
                res[(i + j) % d] = val % MOD;
            }
        }
        return res;
    };

    vector<int> x(d);
    x[0] = 1;
    x[1] = 1;
    vector<int> y(d);
    y[0] = 1;
    while (n > 0) {
        if (n % 2) y = modmul(x, y);
        x = modmul(x, x);
        n /= 2;
    }
    cout << (y[0] - 1) << '\n';

    return 0;
}