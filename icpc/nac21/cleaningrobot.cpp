#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<bool>> has_obs(n + 1, vector<bool>(m + 1));
    for (int o = 0; o < k; o++) {
        int i, j;
        cin >> i >> j;
        has_obs[i][j] = true;
    }

    // Grid out-of-bounds check.
    auto oob = [&](int r, int c) -> bool {
        return r < 1 || r > n || c < 1 || c > m;
    };

    // Build prefix sum over obstacles.
    vector<vector<int>> obs_count(n + 1, vector<int>(m + 1));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            obs_count[i][j] = obs_count[i - 1][j] + obs_count[i][j - 1] - obs_count[i - 1][j - 1];
            obs_count[i][j] += has_obs[i][j];
        }
    }

    // Returns true if the region from (lo_r, lo_c) to (hi_r, hi_c) (inclusive) 
    // does not contain any obstacles.
    auto open = [&](int lo_r, int lo_c, int hi_r, int hi_c) -> bool {
        int count = obs_count[hi_r][hi_c] - obs_count[hi_r][lo_c - 1] 
                  - obs_count[lo_r - 1][hi_c] + obs_count[lo_r - 1][lo_c - 1];
        return count == 0;
    };

    // Determines whether a robot with side `length` can clean the entire room.
    auto cleanable = [&](int length) -> bool {
        if (length == 0) {
            return true;
        }

        const int a = n - length + 1;
        const int b = m - length + 1;
        vector<vector<bool>> vis(a + 1, vector<bool>(b + 1));
        queue<array<int, 2>> q;

        // First, find an empty `length` by `length` square to start from.
        for (int i = 1; i <= a; i++) {
            for (int j = 1; j <= b; j++) {
                if (open(i, j, i + length - 1, j + length - 1)) {
                    q.push({i, j});
                    vis[i][j] = true;
                    break;
                }
            }
            if (!q.empty()) {
                break;
            }
        }

        // Now, simulate by BFSing the robot and marking the cells we've visited.
        // We use the prefix sum trick of adding one to the bottom left/upper right 
        // corners, and subtracting one from the bottom right/top left.
        vector<vector<int>> active(n + 2, vector<int>(m + 2));
        while (!q.empty()) {
            auto [lower_i, lower_j] = q.front();
            q.pop();

            int upper_i = lower_i + length - 1;
            int upper_j = lower_j + length - 1;
            active[lower_i][lower_j] += 1;
            active[upper_i + 1][upper_j + 1] += 1;
            active[lower_i][upper_j + 1] -= 1;
            active[upper_i + 1][lower_j] -= 1;

            const array<array<int, 2>, 4> Dir{{{1, 0}, {-1, 0}, {0, 1}, {0, -1}}};
            for (auto [di, dj] : Dir) {
                int next_i = lower_i + di;
                int next_j = lower_j + dj;
                if (oob(next_i, next_j) || oob(next_i + length - 1, next_j + length - 1)) {
                    continue;
                }
                if (vis[next_i][next_j]) {
                    continue;
                }
                if (!open(next_i, next_j, next_i + length - 1, next_j + length - 1)) {
                    continue;
                }
                q.push({next_i, next_j});
                vis[next_i][next_j] = true;
            }
        }

        // Finally, recover the amount of squares that covers every cell.
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                active[i][j] += active[i - 1][j] + active[i][j - 1] - active[i - 1][j - 1];
                if (active[i][j] == 0 && !has_obs[i][j]) {
                    return false;
                }
            }
        }
        return true;
    };

    // Binary search on the robot length.
    int lo = 0;
    int hi = min(n, m);
    while (lo < hi) {
        int mi = lo + (hi - lo + 1) / 2;
        if (cleanable(mi)) {
            lo = mi;
        } else {
            hi = mi - 1;
        }
    }
    cout << (lo == 0 ? -1 : lo) << '\n';

    return 0;
}