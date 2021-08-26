#include <bits/stdc++.h>
using namespace std;

/* Date: 2021-08-22
 * Source: NAQ 2020
 * Summary: Starting from the leaves, maintain how many paths are still open.
 * We want to keep as many open paths as possible while pairing up paths we
 * don't need anymore.
 */

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<vector<pair<int, int>>> g(n + 1);
    for (int e = 0; e < n - 1; e++) {
        int u, v, p;
        cin >> u >> v >> p;
        g[u].emplace_back(v, p);
        g[v].emplace_back(u, p);
    }
    g[n].emplace_back(0, 0);

    int64_t patrollers = 0;
    function<void(int, int, int64_t)> dfs = [&](int v, int p, int64_t required) {
        vector<int64_t> open;
        for (auto [to, child_required] : g[v]) {
            if (to == p) continue;
            dfs(to, v, child_required);
            open.push_back(child_required);
        }
        int64_t open_count = accumulate(open.begin(), open.end(), int64_t(0));

        if (open_count <= required) {
            patrollers += required - open_count;
        } else {
            int64_t surplus = open_count - required;
            sort(open.begin(), open.end(), greater<int>());
            int deg = open.size();
            open.push_back(0);

            int64_t max_open = open[0];
            for (int i = 0; i < deg; i++) {
                int64_t drop = open[i] - open[i + 1];
                if (drop * (i + 1) <= required) {
                    max_open = open[i + 1];
                    required -= drop * (i + 1);
                } else {
                    max_open = open[i] - required / (i + 1);
                    break;
                }
            }

            if (max_open <= surplus / 2) {
                patrollers -= surplus / 2;
            } else {
                patrollers -= surplus - max_open;
            }
        }
    };
    dfs(n, -1, 0);

    cout << patrollers << '\n';

    return 0;
}