#include "bits/stdc++.h"

using namespace std;

bool solve() {
    int n; cin >> n;
    vector<array<int, 3>> p(n);
    vector<array<int, 3>> q(n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 3; j++)
            cin >> p[i][j];
        for (int j = 0; j < 3; j++)
            cin >> q[i][j];
    }

    // At least one of these is nonzero.
    int size = max(abs(p[0][0] - q[0][0]), abs(p[0][1] - q[0][1]));
    
    const auto check = [&](int x, int y, int z) -> bool {
        constexpr int BIG = 2e9;
        array<int, 3> low = { -BIG, -BIG, -BIG };
        array<int, 3> high = { BIG, BIG, BIG };

        int boxes = 0;
        for (int i = 0; i < n; i++) {
            if (p[i][x] == q[i][x]) {
                array<int, 3> cur_low = { p[i][x], min(p[i][y], q[i][y]), min(p[i][z], q[i][z]) };
                for (int j = 0; j < 3; j++) {
                    low[j] = max(low[j], cur_low[j]);
                }
                array<int, 3> cur_high = { p[i][x] + size, max(p[i][y], q[i][y]), max(p[i][z], q[i][z]) };
                for (int j = 0; j < 3; j++) {
                    high[j] = min(high[j], cur_high[j]);
                }
                boxes++;
            }
        }
        if (boxes == 0 || boxes == n)
            return false;

        for (int j = 0; j < 3; j++) {
            if (low[j] >= high[j])
                return false;
        }

        const auto inside_bounds = [&](array<int, 3> pos) -> bool {
            for (int j = 0; j < 3; j++) {
                if (pos[j] <= low[j] || high[j] <= pos[j])
                    return false;
            }
            return true;
        };

        for (int i = 0; i < n; i++) {
            if (p[i][y] == q[i][y]) {
                if (!inside_bounds({ max(p[i][x], q[i][x]), p[i][y], p[i][z] }) &&
                    !inside_bounds({ max(p[i][x], q[i][x]), p[i][y], q[i][z] }))
                    return false;
            } else if (p[i][z] == q[i][z]) {
                if (!inside_bounds({ max(p[i][x], q[i][x]), p[i][y], p[i][z] }) &&
                    !inside_bounds({ max(p[i][x], q[i][x]), q[i][y], p[i][z] }))
                    return false;
            }
        }
        return true;
    };

    if (check(0, 1, 2))
        return true;
    if (check(1, 0, 2))
        return true;
    if (check(2, 0, 1))
        return true;

    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T; cin >> T;
    while (T--) {
        bool res = solve();
        cout << (res ? "YES" : "NO") << '\n';
    }

    return 0;
}