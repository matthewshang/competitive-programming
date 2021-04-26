#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // H = h*10^9*3600 + m*10^9*60    + s*10^9     + n + X
    // M =               m*10^9*60*12 + s*10^9*12  + n*12 + X
    // S =                              s*10^9*720 + n*720 + X
    const int64_t bil = int64_t(1000000000);
    const int64_t tph = bil * 3600;
    const int64_t tpm = bil * 60;
    const int64_t tps = bil;
    const int64_t MOD = bil * 360 * 12 * 10;

    int T; cin >> T;
    for (int tc = 1; tc <= T; tc++) {
        [&]() {
            array<int64_t, 3> A;
            for (int i = 0; i < 3; i++) {
                cin >> A[i];
            }
            sort(A.begin(), A.end());

            do {
                for (int mask = 0; mask < 8; mask++) {
                    for (int i = 0; i < 3; i++) {
                        if (mask & (1 << i)) {
                            A[i] += MOD;
                        }
                    }
                    for (int64_t h = 0; h < 12; h++) {
                        for (int64_t m = 0; m < 60; m++) {
                            for (int64_t s = 0; s < 60; s++) {
                                // n + X = H
                                int64_t H = A[0] - h * tph - m * tpm - s * tps;
                                // 12n + X = M
                                int64_t M = A[1] - m * tpm * 12 - s * tps * 12;
                                // 720n + X = S
                                int64_t S = A[2] - s * tps * 720;

                                if ((M - H) % 11 == 0 && (S - H) % 719 == 0 && (S - M) % 708 == 0) {
                                    int64_t n = (M - H) / 11;
                                    if (n == (S - H) / 719 && n == (S - M) / 708 && 0 <= n && n < 1000000000) {
                                        cout << "Case #" << tc << ": " << h << ' ' << m << ' ' << s << ' ' << n << '\n';
                                        return;
                                    }
                                }
                            }
                        }
                    }
                    for (int i = 0; i < 3; i++) {
                        if (mask & (1 << i)) {
                            A[i] -= MOD;
                        }
                    }
                }
            } while (next_permutation(A.begin(), A.end()));
            assert(false);
        }();
    }

    return 0;
}
