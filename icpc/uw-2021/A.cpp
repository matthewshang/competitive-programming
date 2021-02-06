#include "bits/stdc++.h"
using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    long long A, MOD; cin >> A >> MOD;
    int N; cin >> N;

    auto get_cnt = [](long long x) -> array<long long, 10> {
        array<long long, 10> cnt{};
        while (x) {
            cnt[x % 10]++;
            x /= 10;
        }
        return cnt;
    };

    auto get_len = [](long long x) -> int {
        int len = 0;
        while (x) {
            len++;
            x /= 10;
        }
        return len;
    };

    using u128 = __uint128_t;
    auto modpow = [&](long long a, long long b) -> long long {
        long long x = 1, y = a;
        while (b) {
            if (b % 2) x = (u128)x * y % MOD;
            y = (u128)y * y % MOD;
            b /= 2;
        }
        return x;
    };

    auto modmul = [&](long long a, long long b) -> long long {
        return (u128)a * b % MOD;
    };

    auto append = [&](long long a, long long b) -> long long {
        return (modmul(a, modpow(10, get_len(b))) + b) % MOD;
    };

    long long res = A;
    auto state = get_cnt(A);
    for (int i = 0; i < N - 1; i++) {
        for (int j = 0; j < 10; j++) {
            if (state[j] > 0) {
                res = append(res, state[j]);
            }
        }
        auto next = state;
        array<long long, 10> cnt{};
        for (int j = 0; j < 10; j++) {
            if (next[j] > 0) {
                auto add = get_cnt(next[j]);
                for (int k = 0; k < 10; k++) {
                    cnt[k] += add[k];
                }
            }
        }
        for (int j = 0; j < 10; j++) {
            next[j] += cnt[j];
        }
        state = next;
    }
    cout << (res % MOD) << '\n';

    return 0;
}
