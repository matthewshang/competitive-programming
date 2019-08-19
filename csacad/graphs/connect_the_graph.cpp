#include "bits/stdc++.h"

using namespace std;

using ll = long long;

const int MX = 100010;

int n, m;
vector<int> adj[MX];

vector<int> roots;
set<pair<int, int>> extra;
bool vis[MX];

void dfs(int u, int par) {
    vis[u] = true;

    for (int x : adj[u]) {
        if (x == par) continue;
        if (vis[x]) {
            int a = min(x, u), b = max(x, u);
            extra.emplace(a, b);
        } else {
            dfs(x, u);
        }
    }
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> n >> m;
    if (m < n - 1) {
        cout << "-1\n";
        return 0;
    }

    for (int i = 0; i < m; i++) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for (int i = 1; i <= n; i++) vis[i] = false;
    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
            roots.push_back(i);
            dfs(i, -1);
        }
    }

    int k = roots.size();
    auto it = extra.begin();
    cout << k - 1 << endl;
    for (int i = 1; i < k; i++) {
        auto& e = *it;
        cout << e.first << " " << e.second << " " << roots[0] << " " << roots[i] << endl;
        it++;
    }

    return 0;
}
