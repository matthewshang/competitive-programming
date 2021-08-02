#include <bits/stdc++.h>
using namespace std;

using Graph = vector<vector<int>>;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    vector<int> start_col(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> start_col[i];
    }
    Graph g(n + 1);
    for (int e = 0; e < m; e++) {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    auto check = [&](vector<int>& col) -> bool {
        for (int i = 1; i < n; i++) {
            if (col[i] != col[i + 1]) return false;
        }
        return true;
    };

    auto go = [&](int s, vector<int> col) -> int {
        int flips = 0;
        int c = col[s];
        while (!check(col)) {
            flips++;
            int nc = c ^ 1;
            vector<bool> vis(n + 1);
            function<void(int)> flip = [&](int v) {
                vis[v] = true;
                col[v] = nc;
                for (int to : g[v]) {
                    if (!vis[to] && col[to] == c) {
                        flip(to);
                    }
                }
            };
            flip(s);
            c = nc;
        }
        return flips;
    };

    int min_flips = n;
    for (int s = 1; s <= n; s++) {
        int flips = go(s, start_col);
        min_flips = min(min_flips, flips);
    }
    cout << min_flips << '\n';

    return 0;
}