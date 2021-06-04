#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N; cin >> N;
    vector<int> a(N);
    vector<int> b(N);
    vector<int> uni;
    for (int i = 0; i < N; i++) {
        cin >> a[i] >> b[i];
        uni.push_back(a[i]);
        uni.push_back(b[i]);
    }

    sort(uni.begin(), uni.end());
    int M = unique(uni.begin(), uni.end()) - uni.begin();
    uni.resize(M);
    vector<vector<int>> adj(M);
    for (int i = 0; i < N; i++) {
        a[i] = lower_bound(uni.begin(), uni.end(), a[i]) - uni.begin();
        b[i] = lower_bound(uni.begin(), uni.end(), b[i]) - uni.begin();
        adj[a[i]].push_back(b[i]);
        adj[b[i]].push_back(a[i]);
    }

    vector<bool> vis(M);
    function<pair<int, int>(int)> dfs = [&](int v) -> pair<int, int> {
        int verts = 1;
        int edges = 0;
        vis[v] = true;
        for (int to : adj[v]) {
            if (!vis[to]) {
                auto [to_verts, to_edges] = dfs(to);
                verts += to_verts;
                edges += to_edges;
            }
            edges += 1;
        }
        return { verts, edges };
    };

    int ans = 0;
    for (int v = 0; v < M; v++) {
        if (!vis[v]) {
            auto [verts, edges] = dfs(v);
            edges /= 2;
            if (edges >= verts) {
                ans += verts;
            } else {
                ans += verts - 1;
            }
        }
    }
    cout << ans << '\n';

    return 0;
}
