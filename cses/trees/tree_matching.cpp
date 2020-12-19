#include "bits/stdc++.h"

using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);

    int n; cin >> n;
    vector<vector<int>> adj(n);
    for (int e = 0; e < n - 1; e++) {
        int a, b; cin >> a >> b;
        a--; b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    function<pair<int, int>(int, int)> dfs = [&](int v, int p) -> pair<int, int> {
        vector<pair<int, int>> res;
        for (int to : adj[v]) {
            if (to != p) {
                res.push_back(dfs(to, v));
            }
        }

        int none = 0;
        for (auto [skip, _] : res) {
            none += skip;
        }
        int best = none;
        for (auto [skip, take] : res) {
            best = max(best, none - skip + take);
        }

        if (p == -1) {
            return { best, 0 };
        } else {
            return { best, 1 + none };
        }
    };

    auto best = dfs(0, -1);
    cout << max(best.first, best.second) << '\n';
}