#include "bits/stdc++.h"

using namespace std;

int main() {
    ios::sync_with_stdio(false); 
    cin.tie(nullptr);

    #ifndef LOCAL
    freopen("maxflow.in", "r", stdin);
    freopen("maxflow.out", "w", stdout);
    #endif

    int n, k; cin >> n >> k;
    vector<vector<int>> adj(n + 1);
    for (int e = 1; e <= n - 1; e++) {
        int a, b; cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    adj[0].push_back(1);

    int l = ceil(log2(n));
    vector<vector<int>> up(n + 1, vector<int>(l + 1));
    vector<int> tin(n + 1);
    vector<int> tout(n + 1);
    int timer = 0;
    function<void(int, int)> build_lca = [&](int v, int p) {
        tin[v] = ++timer;

        up[v][0] = p;
        for (int i = 1; i <= l; i++) {
            up[v][i] = up[up[v][i - 1]][i - 1];
        }
        for (int to : adj[v]) {
            if (to != p) {
                build_lca(to, v);
            }
        }

        tout[v] = ++timer;
    };
    build_lca(0, 0);

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

    vector<int> bal(n + 1);
    for (int p = 0; p < k; p++) {
        int a, b; cin >> a >> b;
        int c = lca(a, b);
        bal[a] += 1;
        bal[b] += 1;
        bal[c] -= 1;
        bal[up[c][0]] -= 1;
    }

    int max_milk = 0;
    function<void(int, int)> dfs = [&](int v, int p) {
        for (int to : adj[v]) {
            if (to != p) {
                dfs(to, v);
                bal[v] += bal[to];
            }
        }
        max_milk = max(bal[v], max_milk);
    };
    dfs(0, -1);

    cout << max_milk << '\n';

    return 0;
}