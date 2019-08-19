#include "bits/stdc++.h"

using namespace std;

using ll = long long;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    int n, m; cin >> n >> m;
    vector<int> perm(n); for (int& x : perm) cin >> x;
    vector<int> adj[n + 1];
    for (int i = 0; i < m; i++) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> rev(n + 1);
    for (int i = 0; i < n; i++) {
        rev[perm[i]] = i + 1;
    }

    vector<pair<int, int>> limit(n + 1);
    limit[1] = {1, n + 1};
    vector<bool> vis(n + 1, false);

    function<void(int)> dfs = [&](int node) -> void {
        if (vis[node]) return;

        vis[node] = true;
        int j = rev[node];
        if (j < limit[node].first || j >= limit[node].second) {
            cout << "0\n";
            exit(0);
        }

        vector<pair<int, int>> pos = {{n + 1, -1}};
        for (int x : adj[node]) {
            if (vis[x]) continue;
            pos.emplace_back(rev[x], x);
        }

        sort(pos.begin(), pos.end());
        for (int i = 0; i < pos.size() - 1; i++) {
            int u = pos[i].second;
            limit[u].first = rev[node];
            limit[u].second = pos[i + 1].first;
            dfs(u);
        }
    };

    dfs(perm[0]);
    cout << "1\n";

    return 0;
}
