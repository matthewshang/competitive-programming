#include "bits/stdc++.h"

using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);

    int n; cin >> n;
    vector<set<int>> color(n);
    for (int i = 0; i < n; i++) {
        int c; cin >> c;
        color[i].insert(c);
    }

    vector<vector<int>> adj(n);
    for (int e = 0; e < n - 1; e++) {
        int a, b; cin >> a >> b;
        a--; b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    vector<int> ans(n);
    function<void(int, int)> dfs = [&](int v, int p) {
        for (int to : adj[v]) {
            if (to != p) {
                dfs(to, v);

                if (color[v].size() < color[to].size()) {
                    swap(color[v], color[to]);
                }
                for (int c : color[to]) {
                    color[v].insert(c);
                }
            }
        }

        ans[v] = color[v].size();
    };
    dfs(0, -1);

    for (int v = 0; v < n; v++) {
        cout << ans[v] << " ";
    }
    cout << '\n';

    return 0;
}
