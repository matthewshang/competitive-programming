#include "bits/stdc++.h"

using namespace std;

using ll = long long;

int idx(int u, map<int, int>& cmp) {
    if (auto it = cmp.find(u); it == cmp.end()) {
        cmp[u] = cmp.size() + 1;
        return cmp.size();
    } else {
        return it->second;
    }
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    int n, m, k; cin >> n >> m >> k;
    vector<tuple<int, int, int>> edges;
    for (int i = 0; i < m; i++) {
        int u, v, w; cin >> u >> v >> w;
        edges.emplace_back(w, u, v);
    }

    sort(edges.begin(), edges.end());

    ll dist[2 * k + 1][2 * k + 1];
    map<int, int> cmp;
    const ll INF = 1e15;
    for (int i = 1; i <= 2 * k; i++) for (int j = 1; j <= 2 * k; j++) dist[i][j] = INF;
    for (int i = 1; i <= min(k, m); i++) {
        auto [w, u, v] = edges[i - 1];
        dist[i][i] = 0;
        u = idx(u, cmp); v = idx(v, cmp);
        dist[u][v] = min(dist[u][v], (ll)w);
        dist[v][u] = min(dist[v][u], (ll)w);
    }

    int V = cmp.size();

    for (int l = 1; l <= V; l++)
        for (int i = 1; i <= V; i++)
            for (int j = 1; j <= V; j++)
                dist[i][j] = min(dist[i][j], dist[i][l] + dist[l][j]);

    vector<ll> d;
    for (int i = 2; i <= V; i++) 
        for (int j = 1; j < i; j++) 
            if (i != j) d.push_back(dist[i][j]);
    sort(d.begin(), d.end());

    cout << d[k - 1] << endl;

    return 0;
}
