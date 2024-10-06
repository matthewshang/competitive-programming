#include <iostream>
#include <vector>

const int MOD = 1e9 + 7;

int main() {
    int N;
    std::cin >> N;
    std::vector<int> dp(N + 1);
    dp[1] = 1;
    for (int i = 2; i <= N; i++) {
        if (i - 2 >= 0) {
            dp[i] = (dp[i] + dp[i - 2]) % MOD;
        }
        if (i - 3 >= 0) {
            dp[i] = (dp[i] + dp[i - 3]) % MOD;
        }
    }
    std::cout << (dp[N - 1] + dp[N - 2]) % MOD << "\n";

    return 0;
}