#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    auto solve = []() {
        int w, n;
        cin >> w >> n;
        vector<int> sensor_x(n);
        vector<int> sensor_y(n);
        vector<int> sensor_r(n);
        for (int i = 0; i < n; i++) {
            cin >> sensor_x[i] >> sensor_y[i] >> sensor_r[i];
        }

        // 0 = left, n+1 = right
        vector<int> par(n + 2);
        vector<int> sz(n + 2, 1);
        iota(par.begin(), par.end(), 0);
        function<int(int)> find = [&](int x) -> int {
            if (x == par[x]) return x;
            return par[x] = find(par[x]);
        };

        auto join = [&](int u, int v) {
            int a = find(u), b = find(v);
            if (a == b) return;
            if (sz[a] < sz[b]) swap(a, b);
            par[b] = a;
            sz[a] += sz[b];
        };

        struct event {
            double time;
            int u, v;
            bool operator<(const event& e) const {
                return time < e.time;
            }
        };
        vector<event> evs;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int64_t dx = sensor_x[i] - sensor_x[j];
                int64_t dy = sensor_y[i] - sensor_y[j];
                double dist = sqrt(dx * dx + dy * dy) - sensor_r[i] - sensor_r[j];
                evs.push_back({dist, i + 1, j + 1});
            }

            evs.push_back({double(sensor_x[i] - sensor_r[i]), 0, i + 1});
            evs.push_back({double(w - (sensor_x[i] + sensor_r[i])), i + 1, n + 1});
        }
        evs.push_back({double(w), 0, n + 1});
        sort(evs.begin(), evs.end());

        double last_joined = 0;
        for (const auto& e : evs) {
            if (find(0) == find(n + 1)) break;
            join(e.u, e.v);
            if (e.time >= 0) {
                last_joined = e.time;
            }
        }
        cout << fixed << setprecision(6) << last_joined * 0.5 << '\n';
    };

    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}