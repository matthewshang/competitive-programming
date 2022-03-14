#include <bits/stdc++.h>
using namespace std;

/* Date: 2022-03-04
 * Source: ECNA 2021
 * Notes: Reduces to finding smallest subset containing both sources nodes and a
 * single destination. Try using every node as a common point between paths from
 * source 1, source 2, and dest.
 */

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int h, w;
    cin >> h >> w;
    vector<vector<int>> g(h, vector<int>(w));
    int n = 0;
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            cin >> g[i][j];
            n = max(n, g[i][j]);
        }
    }

    vector<set<int>> adj(n + 1);
    vector<set<int>> radj(n + 1);
    for (int i = 0; i < h - 1; i++) {
        for (int j = 0; j < w; j++) {
            if (g[i][j] != g[i + 1][j]) {
                adj[g[i][j]].insert(g[i + 1][j]);
                radj[g[i + 1][j]].insert(g[i][j]);
            }
        }
    }
    for (int j = 0; j < w; j++) {
        adj[g[h - 1][j]].insert(0);
        radj[0].insert(g[h - 1][j]);
    }

    set<int> roots;
    for (int j = 0; j < w; j++) {
        roots.insert(g[0][j]);
    }

    vector<int> dist(n + 1, 1e9);
    dist[0] = 0;
    queue<int> q({0});
    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        for (int next : radj[cur]) {
            if (dist[next] > dist[cur] + 1) {
                dist[next] = dist[cur] + 1;
                q.push(next);
            }
        }
    }

    if (roots.size() == 1) {
        cout << dist[*roots.begin()] << "\n";
        return 0;
    }

    vector<int> count(n + 1);
    vector<int> reach(n + 1);
    for (int root : roots) {
        vector<int> down(n + 1, 1e9);
        down[root] = 0;
        queue<int> q({root});
        while (!q.empty()) {
            int cur = q.front();
            q.pop();
            reach[cur]++;
            for (int next : adj[cur]) {
                if (down[next] > down[cur] + 1) {
                    down[next] = down[cur] + 1;
                    q.push(next);
                }
            }
        }

        for (int v = 0; v <= n; v++) {
            count[v] += down[v];
        }
    }

    int best = 1e9;
    for (int v = 0; v <= n; v++) {
        if (reach[v] == 2) {
            int cost = count[v] + dist[v];
            best = min(best, cost);
        }
    }
    cout << best << "\n";
    
    return 0;
}