#include <array>
#include <iostream>
#include <vector>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int N, M, K;
    std::cin >> N >> M >> K;
    std::vector<int> P(N);
    for (int i = 0; i < N; i++) {
        std::cin >> P[i];
    }

    std::vector<int> seg(4 * N);
    auto update = [&](int pos, int v, int l, int r, auto&& update) -> void {
        if (l == r) {
            seg[v] = 1;
        } else {
            int m = (l + r) / 2;
            if (pos <= m) {
                update(pos, v * 2, l, m, update);
            } else {
                update(pos, v * 2 + 1, m + 1, r, update);
            }
            seg[v] = seg[v * 2] + seg[v * 2 + 1];
        }
    };

    auto query = [&](int lo, int hi, int v, int l, int r, auto&& query) -> int {
        if (r < lo || hi < l) {
            return 0;
        }
        if (lo <= l && r <= hi) {
            return seg[v];
        } else {
            int m = (l + r) / 2;
            int lq = query(lo, hi, v * 2, l, m, query);
            int rq = query(lo, hi, v * 2 + 1, m + 1, r, query);
            return lq + rq;
        }
    };

    std::vector<int> l(M);
    std::vector<int> r(M);
    std::vector<int> t(M);
    for (int q = 0; q < M; q++) {
        std::cin >> l[q] >> r[q] >> t[q];
    }

    std::vector<std::array<int, 3>> events;
    for (int q = 0; q < M; q++) {
        events.push_back({-t[q], 1, q});
    }
    for (int i = K; i < N; i++) {
        events.push_back({-(P[i] - P[i - K]), 0, i});
    }
    std::sort(events.begin(), events.end());

    std::vector<int> ans(M);
    for (auto&& [time, typ, id] : events) {
        if (typ == 1) {
            ans[id] = query(l[id] - 1, r[id] - 1, 1, 0, N - 1, query);
        } else {
            update(id, 1, 0, N - 1, update);
        }
    }

    for (int q = 0; q < M; q++) {
        std::cout << ans[q] << "\n";
    }

    return 0;
}