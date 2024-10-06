#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    for (int tt = 1; tt <= T; tt++) {
        int N; cin >> N;
        vector<int> A(N);
        vector<int> B(N);
        for (int i = 0; i < N; i++) {
            cin >> A[i] >> B[i];
        }

        pair<int64_t, int64_t> min_slope = {B[0], 1};
        pair<int64_t, int64_t> max_slope = {A[0], 1};
        for (int i = 1; i < N; i++) {
            int64_t a = A[i];
            int64_t b = B[i];
            int x = i + 1;
            if (b * min_slope.second < min_slope.first * x) {
                min_slope = {b, x};
            }
            if (a * max_slope.second > max_slope.first * x) {
                max_slope = {a, x};
            }
        }

        if (min_slope.first * max_slope.second >= max_slope.first * min_slope.second) {
            cout << "Case #" << tt << ": " << double(min_slope.second) / double(min_slope.first) << "\n";
        } else {
            cout << "Case #" << tt << ": " << "-1\n";
        }
    }
}