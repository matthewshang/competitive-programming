#include <bits/stdc++.h>
using namespace std;

/* Date: 2021-08-19
 * Source: NAQ 2017
 * Summary: Binary search on the answer. To check if a starting velocity works, 
 * we can do a bitmask DP that looks like TSP, but the subproblem is the 
 * reachability of a subset of mice instead of minimum time.
 */

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> x(n);
    vector<int> y(n);
    vector<int> s(n);
    for (int i = 0; i < n; i++) {
        cin >> x[i] >> y[i] >> s[i];
    }
    double m;
    cin >> m;

    vector<vector<double>> dist(n, vector<double>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int dx = x[i] - x[j];
            int dy = y[i] - y[j];
            dist[i][j] = sqrt(dx * dx + dy * dy);
        }
    }

    double low = 0;
    double high = 1000000;
    for (int it = 0; it < 40; it++) {
        double v = (low + high) / 2;
        vector<double> speed(n);
        speed[0] = v;
        for (int i = 1; i < n; i++) {
            speed[i] = speed[i - 1] * m;
        }

        // dp[mask][i] = min time to eat mask ending on i
        vector<vector<double>> dp(1 << n, vector<double>(n, 1e15));
        vector<vector<pair<int, int>>> path(1 << n, vector<pair<int, int>>(n));
        for (int i = 0; i < n; i++) {
            dp[1 << i][i] = sqrt(x[i] * x[i] + y[i] * y[i]) / speed[0];
            path[1 << i][i] = { 0, -1 };
        }
        for (int mask = 1; mask < (1 << n); mask++) {
            for (int last = 0; last < n; last++) {
                if ((mask & (1 << last)) == 0) continue;
                int prev = mask - (1 << last);
                int eaten = __builtin_popcount(prev);

                for (int i = 0; i < n; i++) {
                    if ((prev & (1 << i)) == 0) continue;

                    double time = dp[prev][i] + dist[i][last] / speed[eaten];
                    if (time < dp[mask][last] && time <= s[last]) {
                        dp[mask][last] = time;
                        path[mask][last] = { prev, i };
                    }
                }
            }
        }

        bool ok = false;
        for (int last = 0; last < n; last++) {
            int mask = (1 << n) - 1;
            int mouse = last;
            bool path_ok = true;
            while (mask != 0) {
                if (dp[mask][mouse] > s[mouse]) {
                    path_ok = false;
                    break;
                }
                tie(mask, mouse) = path[mask][mouse];
            }
            if (path_ok) {
                ok = true;
                break;
            }
        }

        if (ok) {
            high = v;
        } else {
            low = v;
        }
    }

    cout << fixed << setprecision(3) << high << '\n';

    return 0;
}