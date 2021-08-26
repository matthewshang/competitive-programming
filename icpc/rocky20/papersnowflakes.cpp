#include "bits/stdc++.h"

using namespace std;

/* Date: 2021-03-30
 * Source: Rocky Mountains 2020
 */

struct event {
    int64_t time;
    bool open;
    int id;

    bool operator<(const event& e) const {
        return time < e.time;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M; cin >> N >> M;
    int64_t L; cin >> L;
    vector<int64_t> f(N);
    for (int i = 0; i < N; i++) {
        cin >> f[i];
    }
    vector<int64_t> c(M + 1);
    for (int i = 0; i < M; i++) {
        cin >> c[i];
    }
    c[M] = L;

    vector<event> evs;
    auto add_seg = [&](int64_t start, int64_t end, int id) {
        if (start > end) {
            swap(start, end);
        }
        evs.push_back({ start, true, id });
        evs.push_back({ end, false, id });
    };

    int64_t start = 0;
    int64_t end = L;
    int64_t last_start = 0;
    for (int i = 0; i < N; i++) {
        last_start = start;
        if (i % 2 == 0) {
            start = end - f[i];
            end = start - f[i];
        } else {
            start = end + f[i];
            end = start + f[i];
        }
        add_seg(start, last_start, i);
    }
    add_seg(start, end, N);
    int S = 2 * N + 2;

    sort(evs.begin(), evs.end());
    vector<int64_t> piles(M + 1);
    int cur = 0;
    int active = 0;
    for (int i = 0; i < M + 1; i++) {
        map<int, int> open_refs;
        set<int> opened;
        set<int> closed;
        while (cur < S && evs[cur].time <= c[i]) {
            const auto& e = evs[cur];
            if (e.open) {
                opened.insert(cur);
                open_refs[e.id] = cur;
            } else {
                if (auto it = open_refs.find(e.id); it != open_refs.end()) {
                    // open - close: add close.time - open.time
                    piles[i] += e.time - evs[it->second].time;
                    opened.erase(it->second);
                    open_refs.erase(it);
                } else {
                    closed.insert(cur);
                }
            }
            cur++;
        }

        // close: add close.time - c[i - 1]
        for (int j : closed) {
            assert(i > 0);
            piles[i] += evs[j].time - c[i - 1];
            active--;
        }

        // active: add c[i] - c[i - 1]
        if (i > 0) {
            piles[i] += active * (c[i] - c[i - 1]);
        }

        // open: add c[i] - open.time
        for (int j : opened) {
            piles[i] += c[i] - evs[j].time;
            active++;
        }
    }

    for (int64_t len : piles) {
        cout << len << ' ';
    }
    cout << '\n';

    return 0;
}