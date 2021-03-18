#include "bits/stdc++.h"

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T; cin >> T;
    for (int tc = 1; tc <= T; tc++) {
        int C, D; cin >> C >> D;
        vector<int> X(C - 1);
        for (int i = 0; i < C - 1; i++) {
            cin >> X[i];
        }
        vector<vector<bool>> adj(C + 1, vector<bool>(C + 1, false));
        vector<pair<int, int>> edges(D);
        for (int e = 0; e < D; e++) {
            int u, v; cin >> u >> v;
            adj[u][v] = adj[v][u] = true;
            edges[e] = { u, v };
        }

        vector<vector<int>> net(C + 1, vector<int>(C + 1, 1e6));
        vector<pair<int, int>> timed, ordered;
        for (int v = 2; v <= C; v++) {
            if (X[v - 2] < 0) {
                ordered.push_back({ -X[v - 2], v });
            } else {
                timed.push_back({ X[v - 2], v });
            }
        }
        sort(timed.begin(), timed.end());
        sort(ordered.begin(), ordered.end());
        reverse(timed.begin(), timed.end());
        reverse(ordered.begin(), ordered.end());

        vector<int> known{1};
        vector<int> dist(C + 1);
        auto find_parent = [&](int v) -> int {
            for (int cand : known) {
                if (adj[cand][v]) {
                    return cand;
                }
            }
            return -1;
        };

        auto update = [&](int v, int target_time) {
            int u = find_parent(v);
            assert(u != -1);
            int w = target_time - dist[u];
            net[u][v] = net[v][u] = w;

            known.push_back(v);
            dist[v] = target_time;
        };

        int cur_time = 1;
        while (int(known.size()) < C) {
            if (ordered.empty() || ordered.back().first > int(known.size())) {
                auto [time, v] = timed.back();
                timed.pop_back();
                update(v, time);
                cur_time = time + 1;
            } else {
                int cur_size = known.size();
                while (!ordered.empty() && ordered.back().first == cur_size) {
                    int v = ordered.back().second;
                    ordered.pop_back();
                    update(v, cur_time);
                }
                cur_time++;
            }
        }

        cout << "Case #" << tc << ":";
        for (int e = 0; e < D; e++) {
            auto [u, v] = edges[e];
            cout << ' ' << net[u][v];
        }
        cout << '\n';
    }
    
    return 0;
}