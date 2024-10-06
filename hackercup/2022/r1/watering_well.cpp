#include <bits/stdc++.h>
using namespace std;

constexpr int64_t MOD = 1e9 + 7;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    for (int tc = 1; tc <= T; tc++) {
        int N;
        cin >> N;
        vector<int64_t> A(N), B(N);
        for (int i = 0; i < N; i++) {
            cin >> A[i] >> B[i];
        }

        int Q;
        cin >> Q;
        vector<int64_t> X(Q), Y(Q);
        for (int i = 0; i < Q; i++) {
            cin >> X[i] >> Y[i];
        }

        int64_t sum = 0;
        for (int i = 0; i < Q; i++) {
            int64_t term = (X[i] * X[i] % MOD + Y[i] * Y[i] % MOD) % MOD;
            sum = (sum + term * N % MOD) % MOD;
        }

        for (int i = 0; i < N; i++) {
            int64_t term = (A[i] * A[i] % MOD + B[i] * B[i] % MOD) % MOD; 
            sum = (sum + term * Q % MOD) % MOD;
        }

        int64_t sum_X = 0;
        for (int i = 0; i < Q; i++) {
            sum_X = (sum_X + X[i]) % MOD;
        }
        int64_t sum_Y = 0;
        for (int i = 0; i < Q; i++) {
            sum_Y = (sum_Y + Y[i]) % MOD;
        }
        int64_t sum_A = 0;
        for (int i = 0; i < N; i++) {
            sum_A = (sum_A + A[i]) % MOD;
        }
        int64_t sum_B = 0;
        for (int i = 0; i < N; i++) {
            sum_B = (sum_B + B[i]) % MOD;
        }

        int64_t sub = (sum_X * sum_A % MOD + sum_Y * sum_B % MOD) % MOD;
        sum = (sum - 2 * sub % MOD) % MOD;
        if (sum < 0) sum += MOD;

        cout << "Case #" << tc << ": " << sum << "\n";
    }

    return 0;
}