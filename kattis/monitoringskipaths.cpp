#include "bits/stdc++.h"

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k, m; cin >> n >> k >> m;
    vector<vector<int>> g(n + 1);
    vector<int> indeg(n + 1);
    for (int e = 0; e < k; e++) {
        int u, v; cin >> u >> v;
        g[u].push_back(v);
        indeg[v]++;
    }

    vector<vector<int>> starts(n + 1);
    for (int r = 0; r < m; r++) {
        int s, t; cin >> s >> t;
        starts[s].push_back(t);
    }

    vector<bool> marked(n + 1);
    function<void(int)> mark = [&](int v) {
        if (!marked[v]) {
            marked[v] = true;
            for (int to : g[v]) {
                mark(to);
            }
        }
    };

    int num_juncs = 0;
    function<void(int)> dfs = [&](int v) -> void {
        for (int to : g[v]) {
            dfs(to);
        }

        bool monitor = false;
        for (int end : starts[v]) {
            if (!marked[end]) {
                monitor = true;
            }
        }
        if (monitor) {
            mark(v);
            num_juncs++;
        }
    };

    for (int v = 1; v <= n; v++) {
        if (indeg[v] == 0) {
            dfs(v);
        }
    }
    cout << num_juncs << '\n';
    
    return 0;
}
