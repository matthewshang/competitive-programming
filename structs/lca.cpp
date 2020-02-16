struct LCA {
    vector<int> first;
    vector<vector<pair<int, int>>> st;

    LCA(int n, vector<int>* adj) { build(n, adj); }

    void build(int n, vector<int>* adj) {
        // Get Euler tour
        int N = 2 * n - 1;
        vector<int> tour(N), height(N);
        int idx = 0;
        function<void(int, int, int)> dfs = [&](int u, int h, int p) {
            int i = idx++;
            height[i] = h; tour[i] = u;
            for (int x: adj[u]) if (x != p) {
                dfs(x, h + 1, u);
                i = idx++;
                height[i] = h; tour[i] = u;
            }
        };
        dfs(0, 0, -1);

        first.resize(n, -1);
        for (int i = 0; i < 2 * n - 1; i++) {
            if (first[tour[i]] == -1) first[tour[i]] = i;
        }

        // Build RMQ
        int k = (int)floor(log2(N)) + 1;
        st.resize(N, vector<pair<int, int>>(k));
        for (int i = 0; i < N; i++)
            st[i][0] = { height[i], tour[i] };
        for (int j = 1; j <= k; j++)
            for (int i = 0; i + (1 << j) <= N; i++)
                st[i][j] = min(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]);
    }

    int query(int u, int v) {
        int a = first[u], b = first[v];
        if (a > b) swap(a, b);
        int j = (int)floor(log2(b - a + 1));
        return min(st[a][j], st[b - (1 << j) + 1][j]).second;
    }
};
