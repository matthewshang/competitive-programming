#include "bits/stdc++.h"

using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);

    struct edge {
        int a, b, cost;

        bool operator<(const edge& e) const {
            return cost < e.cost;
        }
    };

    int n, m; cin >> n >> m;
    vector<edge> edges(m);
    for (int e = 0; e < m; e++) {
        cin >> edges[e].a >> edges[e].b >> edges[e].cost;
    }
    sort(edges.begin(), edges.end());

    vector<int> par(n + 1);
    iota(par.begin(), par.end(), 0);
    vector<int> sz(n + 1, 1);

    function<int(int)> find = [&](int x) -> int {
        if (par[x] == x) {
            return x;
        }
        return (par[x] = find(par[x]));
    };

    auto join = [&](int a, int b) -> bool {
        int u = find(a);
        int v = find(b);
        if (u == v) {
            return false;
        }
        if (sz[u] < sz[v]) {
            swap(u, v);
        }
        par[v] = u;
        sz[u] += sz[v];
        return true;
    };

    long long cost = 0;
    for (int e = 0; e < m; e++) {
        if (join(edges[e].a, edges[e].b)) {
            cost += edges[e].cost;
        }
    }

    if (sz[find(1)] == n) {
        cout << cost << '\n';
    } else {
        cout << "IMPOSSIBLE\n";
    }

    return 0;
}