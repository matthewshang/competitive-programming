#include "bits/stdc++.h"

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T; cin >> T;
    for (int tc = 1; tc <= T; tc++) {
        int N; cin >> N;
        vector<int> X(N);
        vector<int> Y(N);
        for (int i = 0; i < N; i++) {
            cin >> X[i] >> Y[i];
        }

        if (N == 1) {
            cout << "Case #" << tc << ": 1\n";
            continue;
        }

        set<pair<int, int>> dirs;
        auto get_dir = [&](int dx, int dy) -> pair<int, int> {
            int g = gcd(dx, dy);
            dx /= g;
            dy /= g;
            if (dx < 0 || (dx == 0 && dy < 0)) {
                dx = -dx;
                dy = -dy;
            }
            return { dy, dx };
        };

        for (int i = 0; i < N; i++) {
            for (int j = i + 1; j < N; j++) {
                dirs.insert(get_dir(X[j] - X[i], Y[j] - Y[i]));
            }
        }

        int max_holes = 0;
        for (auto d : dirs) {
            map<pair<int64_t, int64_t>, int> intercepts;
            for (int i = 0; i < N; i++) {
                if (d.second == 0) {
                    intercepts[{ X[i], 1 }]++;
                } else {
                    int64_t num = (int64_t)X[i] * d.first;
                    int64_t den = d.second;
                    num = Y[i] * den - num;
                    int64_t g = gcd(num, den);
                    num /= g;
                    den /= g;
                    intercepts[{ num, den }]++;
                }
            }

            int odd_lines = 0;
            int odd_total = 0;
            int even_total = 0;
            int alone = 0;
            for (const auto& it : intercepts) {
                int count = it.second;
                if (count == 1) {
                    alone++;
                } else if (count % 2 == 0) {
                    even_total += count;
                } else {
                    odd_total += count;
                    odd_lines++;
                }
            }

            int reached;
            if (odd_lines % 2 == 0) {
                reached = even_total + odd_total + min(2, alone);
            } else {
                reached = even_total + odd_total + min(1, alone);
            }
            max_holes = max(max_holes, reached);
        }
        cout << "Case #" << tc << ": " << max_holes << '\n';
    }

    return 0;
}