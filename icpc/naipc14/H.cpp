#include <bits/stdc++.h>
using namespace std;

using Scalar = double;
constexpr Scalar INF = 1e9;

struct Point {
    int x, y, z;
};

Scalar dist(const Point& a, const Point& b) {
    int dx = a.x - b.x;
    int dy = a.y - b.y;
    int dz = a.z - b.z;
    return sqrt(dx * dx + dy * dy + dz * dz);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    Point s;
    cin >> s.x >> s.y >> s.z;

    vector<Point> w(n);
    vector<vector<Point>> c(n);
    for (int i = 0; i < n; i++) {
        int k;
        cin >> k;
        c[i].resize(k);
        cin >> w[i].x >> w[i].y >> w[i].z;
        for (int j = 0; j < k; j++) {
            cin >> c[i][j].x >> c[i][j].y >> c[i][j].z;
        }
    }

    // dists[i][v] = min starting from switch i and ending on coin v
    vector<vector<Scalar>> dists(n);
    for (int i = 0; i < n; i++) {
        int k = c[i].size();
        vector<vector<Scalar>> dp(1 << k, vector<Scalar>(k, INF));

        // switch i -> coin v
        for (int v = 0; v < k; v++) {
            dp[1 << v][v] = dist(w[i], c[i][v]);
        }

        for (int mask = 1; mask < (1 << k); mask++) {
            for (int last = 0; last < k; last++) {
                if ((mask & (1 << last)) == 0) continue;
                int prev = mask - (1 << last);

                for (int v = 0; v < k; v++) {
                    if ((prev & (1 << v)) == 0) continue;
                    // coin v -> coin last
                    Scalar cur = dp[prev][v] + dist(c[i][v], c[i][last]);
                    dp[mask][last] = min(dp[mask][last], cur);
                }
            }
        }

        dists[i].resize(k);
        for (int v = 0; v < k; v++) {
            dists[i][v] = dp[(1 << k) - 1][v];
        }
    }

    vector<vector<Scalar>> dp(1 << n, vector<Scalar>(n, INF));
    // start -> switch v
    for (int v = 0; v < n; v++) {
        dp[1 << v][v] = dist(s, w[v]);
    }

    for (int mask = 1; mask < (1 << n); mask++) {
        for (int last = 0; last < n; last++) {
            if ((mask & (1 << last)) == 0) continue;
            int prev = mask - (1 << last);

            for (int v = 0; v < n; v++) {
                if ((prev & (1 << v)) == 0) continue;

                // switch v -> visit ending at last_coin -> switch last
                Scalar cur = INF;
                for (int last_coin = 0, k = c[v].size(); last_coin < k; last_coin++) {
                    Scalar d = dists[v][last_coin] + dist(c[v][last_coin], w[last]);
                    cur = min(cur, d);
                }
                cur += dp[prev][v];
                dp[mask][last] = min(dp[mask][last], cur);
            }
        }
    }

    Scalar best = INF;
    for (int v = 0; v < n; v++) {
        Scalar total = INF;
        for (int last_coin = 0, k = c[v].size(); last_coin < k; last_coin++) {
            total = min(total, dists[v][last_coin]);
        }
        total += dp[(1 << n) - 1][v];
        best = min(best, total);
    }
    cout << fixed << setprecision(3) << best << '\n';

    return 0;
}