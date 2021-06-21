#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    auto pack = [](array<int, 9>& g) -> int64_t {
        int64_t res = 0;
        for (int i = 8; i >= 0; i--) {
            res = (res << 4) | g[i];
        }
        return res;
    };

    auto move = [](int64_t r, int k1, int k2) -> int64_t {
        constexpr int64_t mask = 0xF;
        int64_t r1 = (r & (mask << k1 * 4)) >> k1 * 4;
        int64_t r2 = (r & (mask << k2 * 4)) >> k2 * 4;
        r &= ~(mask << k2 * 4);
        r |= r1 << k2 * 4;
        r &= ~(mask << k1 * 4);
        r |= r2 << k1 * 4;
        return r;
    };

    array<int, 9> g;
    for (int i = 0; i < 9; i++) {
        cin >> g[i];
    }
    queue<int64_t> q({pack(g)});

    array<int, 9> goala;
    iota(goala.begin(), goala.end(), 1);
    int64_t goal = pack(goala);
    unordered_map<int64_t, int> dist;
    dist[pack(g)] = 0;

    while (!q.empty()) {
        auto r = q.front();
        q.pop();
        if (r == goal) {
            break;
        }
        int cur = dist[r];
        
        const array<array<int, 2>, 12> moves = {{
            {0, 1}, {1, 2}, {3, 4}, {4, 5}, {6, 7}, {7, 8},
            {0, 3}, {3, 6}, {1, 4}, {4, 7}, {2, 5}, {5, 8}
        }};

        for (auto [k1, k2] : moves) {
            int64_t next_r = move(r, k1, k2);
            if (dist.find(next_r) == dist.end()) {
                q.push(next_r);
                dist[next_r] = cur + 1;
            }
        }
    }

    cout << dist[goal] << '\n';

    return 0;
}
