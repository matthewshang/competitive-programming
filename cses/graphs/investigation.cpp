#include "bits/stdc++.h"

using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);

    int n, m; cin >> n >> m;
    vector<vector<pair<int, int>>> adj(n + 1);
    for (int e = 0; e < m; e++) {
        int a, b, c; cin >> a >> b >> c;
        adj[a].push_back({ b, c });
    }

    const int64_t MOD = 1e9 + 7;
    const int64_t INF = 1e15;
    vector<int64_t> dist(n + 1, INF);
    vector<int64_t> ways(n + 1);
    vector<int> min_flights(n + 1, m);
    vector<int> max_flights(n + 1, 0);
    vector<bool> vis(n + 1);
    priority_queue<pair<int64_t, int>> pq;
    dist[1] = 0;
    ways[1] = 1;
    min_flights[1] = 0;
    max_flights[1] = 0;

    pq.push({ 0, 1 });
    while (!pq.empty()) {
        auto [cur_dist, cur] = pq.top();
        pq.pop();
        cur_dist *= -1;

        if (vis[cur]) {
            continue;
        }
        vis[cur] = true;

        for (auto [to, cost] : adj[cur]) {
            int64_t to_dist = cur_dist + cost;
            if (to_dist < dist[to]) {
                dist[to] = to_dist;
                ways[to] = ways[cur];
                min_flights[to] = min_flights[cur] + 1;
                max_flights[to] = max_flights[cur] + 1;

                pq.push({ -to_dist, to });
            } else if (to_dist == dist[to]) {
                ways[to] = (ways[to] + ways[cur]) % MOD;
                min_flights[to] = min(min_flights[to], min_flights[cur] + 1);
                max_flights[to] = max(max_flights[to], max_flights[cur] + 1);
            }
        }
    }

    cout << dist[n] << " " << ways[n] << " " << min_flights[n] << " " << max_flights[n] << '\n';

    return 0;
}