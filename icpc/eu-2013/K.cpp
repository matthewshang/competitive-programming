#include "bits/stdc++.h"
using namespace std;

void solve() {
    constexpr int SZ = 26;

    int n; cin >> n;
    array<array<bool, SZ>, SZ> adj{};
    for (int i = 0; i < SZ; i++)
        fill(adj[i].begin(), adj[i].end(), true);
    for (int i = 0; i < n; i++) {
        string digraph; cin >> digraph;
        int u = digraph[0] - 'a';
        int v = digraph[1] - 'a';
        adj[u][v] = false;
    }

    array<int, SZ> vis{};
    array<int, SZ> prev{};
    vector<int> cycle;
    function<bool(int)> find_cycle = [&](int v) -> bool {
        vis[v] = 1;
        for (int to = 0; to < SZ; to++) {
            if (adj[v][to]) {
                if (vis[to] == 1) {
                    int u = v;
                    while (u != to) {
                        cycle.push_back(u);
                        u = prev[u];
                    }
                    cycle.push_back(to);
                    reverse(cycle.begin(), cycle.end());
                    return true;

                } else if (vis[to] == 0) {
                    prev[to] = v;
                    if (find_cycle(to))
                        return true;
                }
            }
        }
        vis[v] = 2;
        return false;
    };

    for (int i = 0; i < SZ; i++) {
        fill(vis.begin(), vis.end(), 0);
        fill(prev.begin(), prev.end(), -1);

        if (find_cycle(i)) {
            int L = cycle.size();
            for (int j = 0; j < 20; j++) {
                for (int k = 0; k < 20; k++) {
                    cout << char('a' + cycle[(j + k) % L]);
                }
                cout << '\n';
            }
            return;
        }
    }

    array<int, SZ> indeg{};
    for (int i = 0; i < SZ; i++) {
        for (int j = 0; j < SZ; j++)
            indeg[j] += adj[i][j];
    }
    queue<int> q;
    for (int i = 0; i < SZ; i++) {
        if (indeg[i] == 0)
            q.push(i);
    }
    vector<int> ord;
    while (!q.empty()) {
        int v = q.front();
        ord.push_back(v);
        q.pop();
        for (int to = 0; to < SZ; to++) {
            if (adj[v][to]) {
                indeg[to]--;
                if (indeg[to] == 0)
                    q.push(to);
            }
        }
    }

    array<int, SZ> dist{};
    for (int v : ord) {
        dist[v] = 1;
        prev[v] = -1;
        for (int from = 0; from < SZ; from++) {
            if (adj[from][v] && dist[from] + 1 > dist[v]) {
                dist[v] = dist[from] + 1;
                prev[v] = from;
            }
        }
    }

    vector<int> best_path;
    int u = max_element(dist.begin(), dist.end()) - dist.begin();
    while (u != -1) {
        best_path.push_back(u);
        u = prev[u];
    }
    reverse(best_path.begin(), best_path.end());

    int S = (best_path.size() + 1) / 2;
    for (int i = 0; i < S; i++) {
        for (int j = 0; j < S; j++) {
            cout << char('a' + best_path[i + j]);
        }
        cout << '\n';
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T; cin >> T;
    while (T--) {
        solve();
    }

    return 0;
}