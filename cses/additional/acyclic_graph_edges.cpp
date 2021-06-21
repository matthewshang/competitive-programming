#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    vector<vector<int>> g(n + 1);
    vector<array<int, 2>> edges(m);
    map<array<int, 2>, array<int, 2>> dir;
    for (int e = 0; e < m; e++) {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
        edges[e] = {a, b};
    }

    auto update = [&](int a, int b, int da, int db) {
        if (a > b) swap(a, b);
        dir[{a, b}] = {da, db};
    };

    vector<int> vis(n + 1);
    function<void(int)> dfs = [&](int v) {
        vis[v] = 1;
        for (int to : g[v]) {
            if (vis[to] == 0) {
                update(v, to, v, to);
                dfs(to);
            } else if (vis[to] == 1) {
                update(v, to, to, v);
            }
        }
        vis[v] = 2;
    };
    for (int v = 1; v <= n; v++) {
        if (vis[v] == 0) dfs(v);
    }

    for (auto [a, b] : edges) {
        if (a > b) swap(a, b);
        auto [u, v] = dir[{a, b}];
        cout << u << " " << v << '\n';
    }

    return 0;
}