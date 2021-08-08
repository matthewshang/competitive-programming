#include <bits/stdc++.h>
using namespace std;

const pair<int, int> nets[11][6] = {
    {{0, 0}, {1, 0}, {2, 0}, {1, 1}, {1, 2}, {1, 3}},
    {{0, 0}, {1, 0}, {1, 1}, {2, 1}, {1, 2}, {1, 3}},
    {{0, 0}, {1, 0}, {1, 1}, {1, 2}, {2, 2}, {1, 3}},
    {{0, 0}, {1, 0}, {1, 1}, {1, 2}, {1, 3}, {2, 3}},
    {{1, 0}, {1, 1}, {0, 1}, {2, 1}, {1, 2}, {1, 3}},
    {{1, 0}, {0, 1}, {1, 1}, {1, 2}, {1, 3}, {2, 2}},
    {{0, 0}, {1, 0}, {1, 1}, {1, 2}, {2, 2}, {2, 3}},
    {{0, 1}, {1, 1}, {2, 1}, {2, 0}, {1, 2}, {1, 3}},
    {{0, 0}, {0, 1}, {0, 2}, {1, 2}, {1, 3}, {1, 4}},
    {{0, 0}, {0, 1}, {1, 1}, {1, 2}, {1, 3}, {2, 2}},
    {{0, 0}, {0, 1}, {1, 1}, {1, 2}, {2, 2}, {2, 3}}
};

using Grid = array<string, 6>;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    array<string, 6> G;
    for (int i = 0; i < 6; i++) {
        cin >> G[i];
    }

    auto check_pos = [&](const Grid& g, int net, int r, int c) -> bool {
        int match = 0;
        for (int i = 0; i < 6; i++) {
            int rr = r + nets[net][i].first;
            int cc = c + nets[net][i].second;
            if (rr >= 6 || cc >= 6) {
                return false;
            }
            match +=  g[rr][cc] == '#';
        }
        return match == 6;
    };

    auto check_net = [&](const Grid& g, int net) -> bool {
        for (int r = 0; r < 6; r++) {
            for (int c = 0; c < 6; c++) {
                if (check_pos(g, net, r, c)) return true;
            }
        }
        return false;
    };

    auto check_grid = [&](Grid g) -> bool {
        for (int net = 0; net < 11; net++) {
            if (check_net(g, net)) return true;
        }
        return false;
    };

    auto rotated = [&](Grid g) -> Grid {
        Grid h;
        fill(h.begin(), h.end(), string(6, '.'));
        for (int i = 0; i < 6; i++) {
            for (int j = 0; j < 6; j++) {
                h[5 - j][i] = g[i][j];
            }
        }
        return h;
    };

    auto check_rotations = [&](Grid g) -> bool {
        for (int i = 0; i < 4; i++) {
            if (check_grid(g)) return true;
            g = rotated(g);
        }
        return false;
    };

    auto h_flipped = [&](Grid g) -> Grid {
        Grid h;
        fill(h.begin(), h.end(), string(6, '.'));
        for (int i = 0; i < 6; i++) {
            for (int j = 0; j < 6; j++) {
                h[i][5 - j] = g[i][j];
            }
        }
        return h;
    };

    auto v_flipped = [&](Grid g) -> Grid {
        Grid h;
        fill(h.begin(), h.end(), string(6, '.'));
        for (int i = 0; i < 6; i++) {
            for (int j = 0; j < 6; j++) {
                h[5 - i][j] = g[i][j];
            }
        }
        return h;
    };

    bool ok = false;
    ok |= check_rotations(G);
    ok |= check_rotations(h_flipped(G));
    ok |= check_rotations(v_flipped(G));
    ok |= check_rotations(h_flipped(v_flipped(G)));
    cout << (ok ? "can fold" : "cannot fold") << '\n';

    return 0;
}