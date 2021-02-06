#include "bits/stdc++.h"
using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int N, S; cin >> N >> S;
    vector<int> s(N);
    for (int i = 0; i < N; i++) {
        cin >> s[i];
    }
    long long total = 0;
    // n^2 ok because N,S <= 1000
    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            total += s[i] * s[j];
        }
    }
    double res = (double)total / (N * (N - 1) / 2) * S;
    cout << fixed << setprecision(4) << res << '\n';

    return 0;
}
