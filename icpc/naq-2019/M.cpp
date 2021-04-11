#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tests; cin >> tests;
    while (tests--) {
        int64_t w, g, h, r; cin >> w >> g >> h >> r;
        g -= r;
        h -= r;

        auto eval = [&](long double x) -> long double {
            return sqrtl(g * g + x * x) + sqrtl(h * h + (w - x) * (w - x));
        };

        int64_t diff = max(g, h) - min(g, h);
        long double min_len = sqrtl(diff * diff + w * w);
        long double max_len;
        if (g + h == 0) {
            max_len = min_len;
        } else {
            long double x = (long double)(g * w) / (g + h);
            max_len = eval(x);
        }

        cout << fixed << setprecision(10);
        cout << min_len << ' ' << max_len << '\n';
    }

    return 0;
}