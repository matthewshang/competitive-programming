#include <iostream>
#include <numeric>
#include <queue>
#include <set>
#include <vector>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int N, M, K;
    std::cin >> N >> M >> K;
    std::vector<int> keys(K);
    for (int i = 0; i < K; i++) {
        std::cin >> keys[i];
    }
    std::vector<std::vector<int>> adj(N);
    for (int e = 0; e < M; e++) {
        int u, v;
        std::cin >> u >> v;
        adj[u - 1].push_back(v - 1);
        adj[v - 1].push_back(u - 1);
    }

    std::vector<std::vector<int>> dist(N, std::vector<int>(K));
    for (int i = 0; i < K; i++) {
        std::set<int> visited;
        std::queue<int> q({keys[i] - 1});
        visited.insert(keys[i] - 1);
        while (!q.empty()) {
            int u = q.front();
            q.pop();

            for (int next : adj[u]) {
                if (visited.count(next) == 0) {
                    dist[next][i] = dist[u][i] + 1;
                    visited.insert(next);
                    q.push(next);
                }
            }
        }
    }

    std::pair<int, int> ans = {N * K, N};
    for (int u = 0; u < N; u++) {
        int sum = std::accumulate(dist[u].begin(), dist[u].end(), 0);
        ans = std::min(ans, {sum, u});
    }
    std::cout << (ans.second + 1) << " " << ans.first << std::endl;

    return 0;
}