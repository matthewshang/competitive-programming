#include <bits/stdc++.h>
using namespace std;

/* Date: 2022-03-20
 * Source: PACNW 2022
 * Notes: Bitmask DP. 
 * E[mask] = 1 + sum_{next} P[next] * E[next] + (1 - sum_{next} P[next]) E[mask]
 * so E[mask] = (1 + sum_{next} P[next] * E[next]) / (sum_{next} P[next]).
 */

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<double> p(n);
    for (int i = 0; i < n; i++) {
        cin >> p[i];
    }

    vector<double> E(1 << n);
    for (int mask = 0; mask < (1 << n); mask++) {
        if (__builtin_popcount(mask) <= 2) continue;

        double prod = 1;
        double minus_prod = 1;
        for (int i = 0; i < n; i++) {
            if (mask & (1 << i)) {
                prod *= p[i];
                minus_prod *= 1 - p[i];
            }
        }

        double sum_p = 0;
        double acc = 1;
        for (int i = 0; i < n; i++) {
            if ((mask & (1 << i)) == 0) continue;

            double move_p = (1 - p[i]) * prod / p[i] + p[i] * minus_prod / (1 - p[i]);
            sum_p += move_p;
            acc += move_p * E[mask ^ (1 << i)];
        }
        E[mask] = acc / sum_p;
    }

    cout << setprecision(6) << fixed << E[(1 << n) - 1] << "\n";
    return 0;
}