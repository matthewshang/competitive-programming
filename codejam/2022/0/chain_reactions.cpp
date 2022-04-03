#include <bits/stdc++.h>
using namespace std;

/* Date: 2022-04-02
 * Source: Code Jam 2022 Qualification
 * Notes: Contract trees so they have height at most log n. Then do tree DP
 * where the state is the node and maximum fun so far. There's at most n log n
 * states. The DP is to let one path continue up the tree; the other paths
 * restart in their own subtrees.
 */

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tests;
    cin >> tests;

    for (int test = 1; test <= tests; test++) {
        int n;
        cin >> n;
        vector<int> f(n);
        for (int i = 0; i < n; i++) {
            cin >> f[i];
        }

        vector<int> roots;
        vector<vector<int>> adj(n);
        for (int i = 0; i < n; i++) {
            int p;
            cin >> p;
            if (p != 0) {
                adj[p - 1].push_back(i);
            } else {
                roots.push_back(i);
            }
        }

        // Contract nodes with only one child
        for (int v = 0; v < n; v++) {
            while (adj[v].size() == 1) {
                int to = adj[v][0];
                adj[v] = move(adj[to]);
                f[v] = max(f[v], f[to]);
                adj[to].clear();
            }
        }

        vector<unordered_map<int, int64_t>> memo(n);
        auto dfs = [&](int v, int max_fun, auto& dfs) -> int64_t {
            if (auto it = memo[v].find(max_fun); it != memo[v].end()) {
                return it->second;
            }

            int64_t val = 0;
            if (adj[v].empty()) {
                val = max(max_fun, f[v]);
            } else if (adj[v].size() == 1) {
                val = dfs(adj[v][0], max(max_fun, f[v]), dfs);
            } else {
                vector<int64_t> save;
                vector<int64_t> cut;
                for (int to : adj[v]) {
                    cut.push_back(dfs(to, 0, dfs));
                    save.push_back(dfs(to, max(max_fun, f[v]), dfs));
                }

                int64_t total = accumulate(cut.begin(), cut.end(), int64_t(0));
                for (int i = 0; i < int(save.size()); i++) {
                    val = max(val, total - cut[i] + save[i]);
                }
            }

            memo[v][max_fun] = val;
            return val;
        };

        int64_t fun = 0;
        for (int v : roots) {
            fun += dfs(v, 0, dfs);
        }

        cout << "Case #" << test << ": " << fun << "\n";
    }

    return 0;
}