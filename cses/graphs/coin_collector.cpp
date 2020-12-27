#include "bits/stdc++.h"

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m; cin >> n >> m;
    vector<int> k(n + 1);
    for (int r = 1; r <= n; r++) {
        cin >> k[r];
    }

    vector<vector<int>> adj(n + 1);
    vector<vector<int>> radj(n + 1);
    for (int e = 0; e < m; e++) {
        int a, b; cin >> a >> b;
        adj[a].push_back(b);
        radj[b].push_back(a);
    }

    vector<int> ord;
    vector<bool> vis(n + 1);
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

    vector<int> comp(n + 1);
    function<void(int, int)> dfs2 = [&](int v, int cc) {
        vis[v] = true;
        comp[v] = cc;
        for (int to : radj[v]) {
            if (!vis[to]) {
                dfs2(to, cc);
            }
        }
    };

    fill(vis.begin(), vis.end(), false);
    reverse(ord.begin(), ord.end());
    int C = 0;
    for (int i = 0; i < n; i++) {
        int v = ord[i];
        if (!vis[v]) {
            dfs2(v, C++);
        }
    }

    vector<long long> coins(C);
    for (int v = 1; v <= n; v++) {
        coins[comp[v]] += k[v];
    }

    vector<bool> vis_comp(C);
    vector<long long> dp(C);
    function<void(int)> dfs3 = [&](int v) -> void {
        vis[v] = true;
        int cc = comp[v];
        vis_comp[cc] = true;
        for (int to : adj[v]) {
            if (!vis[to] && ((comp[v] == comp[to]) || (!vis_comp[comp[to]]))) {
                dfs3(to);
            }

            if (comp[v] != comp[to]) {
                dp[cc] = max(dp[cc], coins[cc] + dp[comp[to]]);
            }
        }
        dp[cc] = max(dp[cc], coins[cc]);
    };

    fill(vis.begin(), vis.end(), false);
    long long max_coins = 0;
    for (int i = 0; i < n; i++) {
        int v = ord[i];
        if (!vis[v]) {
            dfs3(v);
            max_coins = max(max_coins, dp[comp[v]]);
        }
    }
    cout << max_coins << '\n';
    return 0;
}