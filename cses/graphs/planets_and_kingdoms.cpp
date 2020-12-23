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

    vector<int> ord;
    vector<bool> vis(n + 1, false);
    function<void(int)> dfs1 = [&](int v) {
        vis[v] = true;
        for (int to : adj[v]) {
            if (!vis[to]) {
                dfs1(to);
            }
        }
        ord.push_back(v);
    };

    for (int v = 1; v <= n; v++) {
        if (!vis[v]) {
            dfs1(v);
        }
    }

    vector<int> label(n + 1);
    function<void(int, int)> dfs2 = [&](int v, int kingdom) {
        label[v] = kingdom;
        vis[v] = true;
        for (int to : radj[v]) {
            if (!vis[to]) {
                dfs2(to, kingdom);
            }
        }
    };

    int timer = 0;
    fill(vis.begin(), vis.end(), false);
    for (int i = int(ord.size()) - 1; i >= 0; i--) {
        int v = ord[i];
        if (!vis[v]) {
            dfs2(v, ++timer);
        }
    }

    cout << timer << '\n';
    for (int v = 1; v <= n; v++) {
        cout << label[v] << " ";
    }
    cout << '\n';
}