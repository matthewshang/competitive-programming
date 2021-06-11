#include <bits/stdc++.h>
using namespace std;

// Construct a graph with a node for every zoom level and center and BFS on
// it. To find which nodes are visible in a window, use a two pointer sweep
// and keep track of the largest weights with a set.

// ~log2(2e8) + 1
constexpr int M = 30;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;
    vector<pair<int, int>> x(n + 1);
    for (int i = 0; i < n; i++) {
        cin >> x[i].first;
        x[i].second = i + 1;
    }
    x[n] = {0,0};
    sort(x.begin(), x.end());
    vector<int> rpos(n + 1);
    for (int i = 0; i < n + 1; i++) {
        rpos[x[i].second] = i;
    }

    vector<vector<vector<int>>> adj(M, vector<vector<int>>(n + 1));
    vector<int> zoom(n + 1);  // 0 = width 1
    int width = 1;
    for (int L = 1; L < M; L++) {
        set<int> active;
        int cur = 0;
        int l = 0;
        int r = 0;
        while (cur < n + 1) {
            while (r < n + 1 && x[r].first - x[cur].first <= width) {
                active.insert(x[r].second);
                r++;
            }
            while (l < cur && x[cur].first - x[l].first > width) {
                active.erase(x[l].second);
                l++;
            }

            auto it = active.rbegin();
            for (int i = 0; i < min(k, (int)active.size()); i++) {
                int to = rpos[*it];
                if (to != cur) {
                    adj[L][cur].push_back(to);
                } else {
                    zoom[cur] = L;
                }
                ++it;
            }

            cur++;
        }
        width *= 2;
    }

    queue<pair<int, int>> q({{1, rpos[0]}});
    vector<vector<int>> dist(M, vector<int>(n + 1, 1e9));
    vector<vector<bool>> vis(M, vector<bool>(n + 1));
    dist[1][rpos[0]] = 0;
    vis[1][rpos[0]] = true;
    while (!q.empty()) {
        auto [l, v] = q.front();
        q.pop();
        for (int to : adj[l][v]) {
            if (!vis[l][to]) {
                dist[l][to] = dist[l][v] + 1;
                vis[l][to] = true;
                q.push({l, to});
            }
        }
        if (l > 0 && !vis[l - 1][v]) {
            dist[l - 1][v] = dist[l][v] + 1;
            vis[l - 1][v] = true;
            q.push({l - 1, v});
        }
        if (l < M - 1 && !vis[l + 1][v]) {
            dist[l + 1][v] = dist[l][v] + 1;
            vis[l + 1][v] = true;
            q.push({l + 1, v});
        }
    }

    vector<int> d(n + 1, 1e9);
    for (int i = 0; i < n + 1; i++) {
        for (int l = 0; l <= zoom[i]; l++) {
            d[x[i].second] = min(d[x[i].second], dist[l][i]);
        }
        if (d[x[i].second] == 1e9) {
            d[x[i].second] = -1;
        }
    }
    for (int i = 1; i <= n; i++) {
        cout << d[i] << '\n';
    }

    return 0;
}