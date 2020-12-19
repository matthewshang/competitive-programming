#include "bits/stdc++.h"

using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);

    int n, q; cin >> n >> q;
    vector<vector<int>> adj(n);
    for (int i = 1; i <= n - 1; i++) {
        int e; cin >> e;
        adj[e - 1].push_back(i);
    }

    int l = ceil(log2(n));
    vector<vector<int>> up(n, vector<int>(l + 1));
    vector<int> depth(n);
    depth[0] = 0;
    function<void(int, int)> dfs = [&](int v, int p) {
        up[v][0] = p;
        for (int i = 1; i <= l; i++) {
            up[v][i] = up[up[v][i - 1]][i - 1];
        }
        for (int to : adj[v]) {
            depth[to] = depth[v] + 1;
            dfs(to, v);
        }
    };
    dfs(0, 0);

    for (int i = 0; i < q; i++) {
        int x, k; cin >> x >> k;
        x--;
        if (k > depth[x]) {
            cout << -1 << '\n';
        } else {
            for (int j = l; j >= 0; j--) {
                if (k >= (1 << j)) {
                    x = up[x][j];
                    k -= (1 << j);
                }
            }
            cout << (x + 1) << '\n';
        }
    }
}