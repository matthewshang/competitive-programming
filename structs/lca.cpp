struct LCA {
    vector<int> first; RMQ<pii> Q;
    LCA(int n, vector<vector<int>>& adj) { build(n, adj); }
    void build(int n, vector<vector<int>>& adj) {
        int N = 2 * n - 1, idx = 0; vpi v(N);
        function<void(int, int, int)> dfs = [&](int u, int h, int p) {
            int i = idx++;
            v[i] = {h, u};
            for (int x : adj[u]) if (x != p) {
                dfs(x, h + 1, u);
                i = idx++;
                v[i] = {h, u};
            }
        };
        dfs(0, 0, -1);
        Q.build(v);
        first.resize(n, -1);
        for (int i = 0; i < 2 * n - 1; i++)
            if (first[v[i].s] == -1) first[v[i].s] = i;
    }
    int query(int u, int v) {
        int a = first[u], b = first[v];
        if (a > b) swap(a, b);
        return Q.query(a, b).s;
    }
};