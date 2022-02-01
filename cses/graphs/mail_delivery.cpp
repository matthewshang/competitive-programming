#include <bits/stdc++.h>
using namespace std;

/* Date: 2021-12-30
 * Source: CSES
 * Summary: Hierholzer's algorithm for Eulerian circuit in O(V + E). One detail
 * is how to erase edges while doing the DFS. Here, I keep adjacency sets and
 * iterators into each set that are shared between recursive calls.
 */

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    vector<set<int>> adj(n + 1);
    for (int e = 0; e < m; e++) {
        int u, v;
        cin >> u >> v;
        adj[u].insert(v);
        adj[v].insert(u);
    }

    // Eulerian circuit <=> all vertices have even degree
    for (int v = 1; v <= n; v++) {
        if (adj[v].size() % 2 != 0) {
            cout << "IMPOSSIBLE\n";
            return 0;
        }
    }

    // Build circuit
    vector<set<int>::iterator> its(n + 1);
    for (int v = 1; v <= n; v++) {
        its[v] = adj[v].begin();
    }

    stack<int> tour;
    function<void(int)> find_tour = [&](int u) {
        while (its[u] != adj[u].end()) {
            int to = *its[u];
            its[u] = adj[u].erase(its[u]);
            if (*its[to] == u) {
                its[to] = adj[to].erase(its[to]);
            } else {
                adj[to].erase(u);
            }
            find_tour(to);
        }
        tour.push(u);
    };
    find_tour(1);

    // Check connectedness
    for (int v = 1; v <= n; v++) {
        if (!adj[v].empty()) {
            cout << "IMPOSSIBLE\n";
            return 0;
        }
    }

    while (!tour.empty()) {
        cout << tour.top() << " ";
        tour.pop();
    }
    cout << '\n';

    return 0;
}