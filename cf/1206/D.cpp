#include "bits/stdc++.h"

using namespace std;

using ll = long long;

const int SZ = 60;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    int n; cin >> n;
    vector<ll> place[SZ];
    for (int i = 0; i < n; i++) {
        ll a; cin >> a;
        for (int j = 0; j < SZ; j++) {
            bool con = a & (1LL << j);
            if (con) place[j].push_back(a);
        }
    }

    bool bad = true;
    for (int i = 0; i < SZ; i++) {
        if (place[i].size() > 2) {
            cout << "3\n";
            return 0;
        } else if (place[i].size() == 2) {
            bad = false;
        } else if (place[i].size() == 1) {
            place[i].clear();
        }
    }

    if (bad) {
        cout << "-1\n";
        return 0;
    }

    bool adj[SZ][SZ];
    map<ll, int> mp;
    auto compress = [&](ll x) -> int {
        auto it = mp.find(x);
        if (it == mp.end()) {
            mp[x] = mp.size();
        }
        return mp[x];
    };

    for (int i = 0; i < SZ; i++) for (int j = 0; j < SZ; j++) adj[i][j] = false;
    for (int i = 0; i < SZ; i++) {
        if (place[i].size() != 2) continue;
        int u = compress(place[i][0]), v = compress(place[i][1]);
        adj[u][v] = true;
        adj[v][u] = true;
    }

    auto shortest = [&](int u, int v) -> int {
        adj[u][v] = adj[v][u] = false;

        vector<int> dist(SZ, 1 << 20);
        dist[u] = 0;
        queue<int> q({u});
        while (!q.empty()) {
            int node = q.front(); q.pop();

            if (node == v) {
                adj[u][v] = adj[v][u] = true;
                return dist[v] + 1;
            }

            for (int i = 0; i < SZ; i++) {
                if (!adj[i][node] || i == u) continue;
                if (dist[i] > dist[node] + 1) {
                    dist[i] = dist[node] + 1;
                    q.push(i);
                }
            }
        }

        adj[u][v] = adj[v][u] = true;
        return 1 << 20;
    };

    int ans = 1 << 20;
    for (int start = 1; start < SZ; start++) {
        for (int end = 0; end < start; end++) {
            if (!adj[start][end]) continue;
            ans = min(ans, shortest(start, end));
        }
    }
    cout << ((ans == 1 << 20) ? -1 : ans) << endl;
    return 0;
}
