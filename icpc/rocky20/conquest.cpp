#include "bits/stdc++.h"

using namespace std;

/* Date: 2021-03-30
 * Source: Rocky Mountains 2020
 */

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M; cin >> N >> M;
    vector<vector<int>> adj(N + 1);
    for (int e = 0; e < M; e++) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<int> size(N + 1);
    for (int v = 1; v <= N; v++) {
        cin >> size[v];
    }

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    vector<bool> used(N + 1);
    used[1] = true;
    for (int to : adj[1]) {
        pq.push({ size[to], to });
        used[to] = true;
    }

    while (!pq.empty()) {
        auto [s, v] = pq.top();
        if (s >= size[1]) {
            break;
        }
        pq.pop();
        size[1] += s;
        for (int to : adj[v]) {
            if (!used[to]) {
                pq.push({ size[to], to });
                used[to] = true;
            }
        }
    }
    cout << size[1] << '\n';

    return 0;
}