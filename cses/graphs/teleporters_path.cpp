#include <bits/stdc++.h>
using namespace std;

/* Date: 2021-12-31
 * Source: CSES
 * Summary: Hierholzer's algorithm for Eulerian circuit in a directed graph. 
 * We just need to check that
 * 1) the starting node has one more out edge than in
 * 2) the ending node has one more in edge than out
 * 3) all other nodes have the same number of edges leaving and coming in
 * 4) all nodes are in a single connected component
 */

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n + 1);
    vector<int> indeg(n + 1);
    vector<int> outdeg(n + 1);
    for (int e = 0; e < m; e++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        indeg[b]++;
        outdeg[a]++;
    }

    if (outdeg[1] - indeg[1] != 1 || indeg[n] - outdeg[n] != 1) {
        cout << "IMPOSSIBLE\n";
        return 0;
    }

    for (int v = 2; v < n; v++) {
        if (indeg[v] != outdeg[v]) {
            cout << "IMPOSSIBLE\n";
            return 0;
        }
    }

    stack<int> tour;
    function<void(int)> find_tour = [&](int u) {
        while (!adj[u].empty()) {
            int to = adj[u].back();
            adj[u].pop_back();
            find_tour(to);
        }
        tour.push(u);
    };
    find_tour(1);

    if ((int)tour.size() != m + 1) {
        cout << "IMPOSSIBLE\n";
        return 0;
    }

    while (!tour.empty()) {
        cout << tour.top() << " ";
        tour.pop();
    }
    cout << '\n';

    return 0;
}