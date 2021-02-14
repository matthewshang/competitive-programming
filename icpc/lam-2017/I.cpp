#include "bits/stdc++.h"

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    struct edge {
        int A, B, C;
        bool operator<(const edge& e) const {
            return C < e.C;
        }
    };

    int N, R; cin >> N >> R;
    vector<edge> edges;
    map<pair<int, int>, int> edge_weights;
    for (int i = 0; i < R; i++) {
        int A, B, C; cin >> A >> B >> C;
        edges.push_back(edge{ A, B, C });
        if (A > B) swap(A, B);
        edge_weights[{ A, B }] = C;
    }

    // Step 1: Get MST
    sort(edges.begin(), edges.end());
    int min_cost = 0;
    vector<vector<pair<int, int>>> adj(N + 1);
    {
        vector<int> par(N + 1);
        iota(par.begin(), par.end(), 0);
        vector<int> sz(N + 1, 1);
        function<int(int)> find = [&](int x) -> int {
            if (par[x] != x) par[x] = find(par[x]);
            return par[x];
        };

        function<bool(int, int)> join = [&](int a, int b) -> bool {
            int x = find(a);
            int y = find(b);
            if (x == y) {
                return false;
            } else {
                if (sz[x] < sz[y]) swap(x, y);
                par[y] = x;
                sz[x] += sz[y];
                return true;
            }
        };

        for (const auto& e : edges) {
            if (join(e.A, e.B)) {
                min_cost += e.C;
                adj[e.A].emplace_back(e.B, e.C);
                adj[e.B].emplace_back(e.A, e.C);
            }
        }
    }

    // Step 2: Build LCA/max
    const int L = ceil(log2(N + 1));
    int timer = 0;
    vector<int> tin(N + 1);
    vector<int> tout(N + 1);
    vector<vector<int>> up(N + 1, vector<int>(L + 1));
    vector<vector<int>> cost(N + 1, vector<int>(L + 1));
    function<void(int, int, int)> dfs = [&](int v, int p, int w) {
        tin[v] = ++timer;
        up[v][0] = p;
        for (int i = 1; i <= L; i++)
            up[v][i] = up[up[v][i - 1]][i - 1];
        cost[v][0] = w;
        for (int i = 1; i <= L; i++)
            cost[v][i] = max(cost[v][i - 1], cost[up[v][i - 1]][i - 1]);
        for (const auto& e : adj[v]) {
            if (e.first != p) {
                dfs(e.first, v, e.second);
            }
        }
        tout[v] = ++timer;
    };
    dfs(1, 1, 0);

    auto is_ancestor = [&](int u, int v) -> bool {
        return tin[u] <= tin[v] && tout[v] <= tout[u];
    };

    auto lca = [&](int u, int v) -> int {
        if (is_ancestor(u, v))
            return u;
        if (is_ancestor(v, u))
            return v;
        for (int i = L; i >= 0; i--) {
            if (!is_ancestor(up[u][i], v))
                u = up[u][i];
        }
        return up[u][0];
    };

    auto max_cost = [&](int u, int anc) -> int {
        int max_edge = 0;
        for (int i = L; i >= 0; i--) {
            if (up[u][i] == anc || !is_ancestor(up[u][i], anc)) {
                max_edge = max(max_edge, cost[u][i]);
                u = up[u][i];
            }
        }
        return max_edge;
    };

    // Step 3: Queries
    int Q; cin >> Q;
    while (Q--) {
        int U, V; cin >> U >> V;
        if (up[U][0] == V || up[V][0] == U) {
            cout << min_cost << '\n';
        } else {
            int W = lca(U, V);
            int max_edge = max(max_cost(U, W), max_cost(V, W));
            if (U > V) swap(U, V);
            cout << (min_cost - max_edge + edge_weights[{ U, V }]) << '\n';
        }
    }

    return 0;
}