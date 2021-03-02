#include "bits/stdc++.h"

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n; cin >> n;
    vector<long long> t(n);
    for (int i = 0; i < n; i++) {
        cin >> t[i];
    }
    vector<vector<pair<int, int>>> adj(n);
    for (int e = 0; e < n - 1; e++) { 
        int u, v, w; cin >> u >> v >> w;
        u--; v--;
        adj[u].push_back({ v, w });
        adj[v].push_back({ u, w });
    }

    vector<long long> sub(n);
    vector<long long> sum(n);
    long long A = 0;
    long long B = 0;
    function<void(int, int, int)> dfs1 = [&](int v, int p, int dist) {
        sub[v] = 1;
        sum[v] = t[v];
        A += dist;
        B += (long long)dist * t[v];
        for (auto [to, w] : adj[v]) {
            if (to != p) {
                dfs1(to, v, dist + w);
                sub[v] += sub[to];
                sum[v] += sum[to];
            }
        }
    };
    dfs1(0, 0, 0);
    long long total_sum = accumulate(t.begin(), t.end(), 0LL);

    vector<long long> cost(n);
    function<void(int, int)> dfs2 = [&](int v, int p) {
        cost[v] = A * t[v] + B;
        for (auto [to, w] : adj[v]) {
            if (to != p) {
                long long dA = ((n - sub[to]) - sub[to]) * w;
                long long dB = ((total_sum - sum[to]) - sum[to]) * w;
                A += dA;
                B += dB;
                dfs2(to, v);
                A -= dA;
                B -= dB;
            }
        }
    };
    dfs2(0, 0);

    for (int i = 0; i < n; i++) {
        cout << cost[i] << '\n';
    }

    return 0;
}