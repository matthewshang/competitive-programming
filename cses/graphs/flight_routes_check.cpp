#include "bits/stdc++.h"

using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);

    int n, m; cin >> n >> m;
    vector<vector<int>> adj(n + 1);
    vector<vector<int>> radj(n + 1);
    for (int e = 0; e < m; e++) {
        int a, b; cin >> a >> b;
        adj[a].push_back(b);
        radj[b].push_back(a);
    }

    vector<bool> vis(n + 1, false);
    function<void(vector<vector<int>>&, int)> dfs = [&](vector<vector<int>>& gr, int v) {
        vis[v] = true;
        for (int to : gr[v]) {
            if (!vis[to]) {
                dfs(gr, to);
            }
        }
    };

    dfs(adj, 1);
    for (int v = 1; v <= n; v++) {
        if (!vis[v]) {
            cout << "NO" << '\n';
            cout << 1 << " " << v << '\n';
            return 0;
        }
    }

    fill(vis.begin(), vis.end(), false);
    dfs(radj, 1);
    for (int v = 1; v <= n; v++) {
        if (!vis[v]) {
            cout << "NO" << '\n';
            cout << v << " " << 1 << '\n';
            return 0;
        }
    }
    cout << "YES" << '\n';
    return 0;
}