#include "bits/stdc++.h"
using namespace std;

void solve(int test_case) {
    int M; cin >> M;
    vector<int> P(M);
    vector<int64_t> N(M);
    int64_t sum = 0;
    for (int i = 0; i < M; i++) {
        cin >> P[i] >> N[i];
        sum += P[i] * N[i];
    }

    auto factorize = [&](int64_t X, vector<int>& ret) -> bool {
        for (int i = 0; i < M && X > 1; i++) {
            while (X % P[i] == 0) {
                ret[i]++;
                if (ret[i] > N[i]) {
                    return false;
                }
                X /= P[i];
            }
        }
        return X == 1;
    };

    for (int64_t s = sum; s >= sum - 30000; s--) {
        vector<int> c(M);
        if (factorize(s, c)) {
            int64_t t = 0;
            for (int i = 0; i < M; i++) {
                t += (int64_t)P[i] * (N[i] - c[i]);
            }
            if (t == s) {
                cout << "Case #" << test_case << ": " << s << '\n';
                return;
            }
        }
    }

    cout << "Case #" << test_case << ": 0\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tests;
    cin >> tests;
    for (int test_case = 1; test_case <= tests; test_case++) {
        solve(test_case);
    }
    
    return 0;
}