#include "bits/stdc++.h"

using namespace std;

using ll = long long;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    int n, k; cin >> n >> k;
    vector<int> adj[n + 1];
    set<pair<int, int>> edges;
    for (int i = 0; i < n - 1; i++) {
        int a, b, c; cin >> a >> b >> c;
        adj[a].push_back(b);
        adj[b].push_back(a);
        if (c) {
            if (a > b) swap(a, b);
            edges.emplace(a, b);
        }
    }

    vector<int> sz(n + 1, 0);
    function<void(int)> dfs = [&](int node) -> void {
        sz[node] = 1;

        for (int x : adj[node]) {
            if (sz[x] != 0) continue;
            dfs(x);
            sz[node] += sz[x];
        }
    };

    dfs(1);

    queue<int> q({1});
    vector<int> cut;
    while (!q.empty()) {
        int node = q.front(); q.pop();

        for (int x : adj[node]) {
            if (sz[x] > sz[node]) continue;
            int u = x, v = node;
            if (u > v) swap(u, v);
            if (edges.find({u, v}) != edges.end()) {
                if (sz[u] > sz[v]) swap(u, v);
                cut.push_back(sz[u]);
            } else {
                q.push(x);
            }
        }
    }

    sort(cut.begin(), cut.end(), greater<int>());
    int i = 0;
    int virus = n;
    while (i < cut.size() && virus > k) {
        virus -= cut[i];
        i++;
    }
    
    if (virus > k) cout << "-1\n";
    else cout << i << endl;

    return 0;
}
