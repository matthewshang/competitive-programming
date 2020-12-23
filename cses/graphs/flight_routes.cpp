#include "bits/stdc++.h"

using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);

    int n, m, k; cin >> n >> m >> k;
    vector<vector<pair<int, int>>> adj(n + 1);
    for (int e = 0; e < m; e++) {
        int a, b, c; cin >> a >> b >> c;
        adj[a].push_back({ b, c });
    }

    vector<int64_t> routes;
    vector<int> num_visits(n + 1, 0);
    priority_queue<pair<int64_t, int>> pq;
    pq.push({ 0, 1 });
    while (!pq.empty() && (int)routes.size() < k) {
        auto [weight, cur] = pq.top();
        pq.pop();

        if (cur == n) {
            routes.push_back(-weight);
        }
        if (num_visits[cur] > k) {
            continue;
        }
        num_visits[cur]++;

        for (auto [to, cost] : adj[cur]) {
            int64_t d = -weight + cost;
            pq.push({ -d, to });
        }
    }

    for (int i = 0; i < k; i++) {
        cout << routes[i] << " ";
    }
    cout << '\n';
}