#include <bits/stdc++.h>
using namespace std;

/* Date: 2022-03-05
 * Source: PACNW 2022
 * Notes: Find the segment to split on and compute the exact division point
 * using area ratios.
 */

using ld = long double;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int64_t> x(n);
    vector<int64_t> y(n);
    for (int i = 0; i < n; i++) {
        cin >> x[i] >> y[i];
    }

    vector<int64_t> area(n);
    for (int i = 2; i < n; i++) {
        area[i] = abs(x[0] * y[i - 1] + x[i - 1] * y[i] + x[i] * y[0]
                    - y[0] * x[i - 1] - y[i - 1] * x[i] - y[i] * x[0]);
    }
    int64_t total_area = accumulate(area.begin(), area.end(), int64_t(0));

    int cut = 2;
    int64_t half = area[2];
    while (half * 2 < total_area && cut < n) {
        cut++;
        half += area[cut];
    }
    if (half * 2 == total_area) {
        cout << x[cut] << " " << y[cut] << "\n";
        return 0;
    }

    // Solve A + tC = B + (1 - t)C
    int64_t A = half - area[cut];
    int64_t B = total_area - half;
    int64_t C = area[cut];
    ld t = ld(B + C - A) / ld(2 * C);

    ld x0 = x[cut - 1];
    ld y0 = y[cut - 1];
    ld x1 = x[cut];
    ld y1 = y[cut];
    ld xm = x0 + t * (x1 - x0);
    ld ym = y0 + t * (y1 - y0);
    // Forgetting fixed here costed us AC and 4th place in contest
    cout << fixed << setprecision(6) << xm << " " << ym << "\n";

    return 0;
}