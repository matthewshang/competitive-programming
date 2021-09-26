#include <bits/stdc++.h>
using namespace std;

/* Date: 2021-09-25
 * Source: FB Hacker Cup 2021 R2
 * Summary: Go through every frequency and mark edges that can't be blockaded.
 * Let t_1, ..., t_m be the towers with frequency f. The bad region consists of
 * paths from LCA(t_1, ..., t_m) to t_i, so we just need to count paths going
 * through edges with the usual subtree sum trick. See CSES Counting Paths.
 */

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    for (int tc = 1; tc <= T; tc++) {
        int N;
        cin >> N;
        vector<vector<int>> g(N + 1);
        for (int i = 0; i < N - 1; i++) {
            int A, B;
            cin >> A >> B;
            g[A].push_back(B);
            g[B].push_back(A);
        }

        vector<int> F(N + 1);
        for (int v = 1; v <= N; v++) {
            cin >> F[v];
        }

        const int l = ceil(log2(N));
        vector<vector<int>> up(N + 1, vector<int>(l + 1));
        vector<int> tin(N + 1);
        vector<int> tout(N + 1);
        int timer = 0;
        function<void(int, int)> build_lca = [&](int v, int p) {
            tin[v] = ++timer;

            up[v][0] = p;
            for (int i = 1; i <= l; i++) {
                up[v][i] = up[up[v][i - 1]][i - 1];
            }
            for (int to : g[v]) {
                if (to != p) {
                    build_lca(to, v);
                }
            }

            tout[v] = ++timer;
        };
        build_lca(1, 1);

        auto is_ancestor = [&](int u, int v) -> bool {
            return tin[u] <= tin[v] && tout[v] <= tout[u];
        };

        auto lca = [&](int u, int v) -> int {
            if (is_ancestor(u, v)) {
                return u;
            }
            if (is_ancestor(v, u)) {
                return v;
            }
            for (int i = l; i >= 0; i--) {
                if (!is_ancestor(up[u][i], v)) {
                    u = up[u][i];
                }
            }
            return up[u][0];
        };

        vector<vector<int>> rf(N + 1);
        for (int v = 1; v <= N; v++) {
            rf[F[v]].push_back(v);
        }

        vector<int> bal(N + 1);
        for (int freq = 1; freq <= N; freq++) {
            if (rf[freq].size() <= 1) {
                continue;
            }

            const auto& towers = rf[freq];
            int L = lca(towers[0], towers[1]);
            for (int i = 2; i < (int)towers.size(); i++) {
                L = lca(L, towers[i]);
            }

            for (int v : towers) {
                bal[v]++;
                bal[L]--;
            }
        }

        int blockable = 0;
        function<void(int, int)> dfs = [&](int v, int p) {
            for (int to : g[v]) {
                if (to != p) {
                    dfs(to, v);
                    bal[v] += bal[to];
                }
            }
            if (bal[v] == 0) {
                blockable++;
            }
        };
        dfs(1, 0);

        cout << "Case #" << tc << ": " << blockable - 1 << '\n';
    }

    return 0;
}