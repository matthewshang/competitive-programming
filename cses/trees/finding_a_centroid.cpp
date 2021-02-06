#include "bits/stdc++.h"
using namespace std;

int main() {
    int n; cin >> n;
    vector<vector<int>> adj(n + 1);
    for (int e = 0; e < n - 1; e++) {
        int a, b; cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    function<int(int, int)> dfs = [&](int v, int p) -> int {
        int size = 1;
        bool is_centroid = true;
        for (int to : adj[v]) {
            if (to != p) {
                int sub_size = dfs(to, v);
                size += sub_size;
                if (sub_size > (n + 1) / 2) 
                    is_centroid = false;
            }
        }

        if (n - size + 1 > (n + 1) / 2)
            is_centroid = false;

        if (is_centroid) {
            cout << v << '\n';
            exit(0);
        }
        return size;
    };
    dfs(1, 0);

    return 0;
}