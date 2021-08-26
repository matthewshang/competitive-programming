#include "bits/stdc++.h"

using namespace std;

/* Date: 2021-04-08
 * Source: NAQ 2018
 */

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, k; cin >> n >> k;
    vector<vector<int>> a(n, vector<int>(n));
    for (int i = 0; i < k; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }

    for (int i = 0; i < k; i++) {
        vector<bool> used(n + 1);
        for (int j = 0; j < n; j++) {
            if (used[a[i][j]]) {
                cout << "no\n";
                return 0;
            }
            used[a[i][j]] = true;
        }
    }

    vector<vector<bool>> used(n, vector<bool>(n + 1));
    for (int j = 0; j < n; j++) {
        for (int i = 0; i < k; i++) {
            if (used[j][a[i][j]]) {
                cout << "no\n";
                return 0;
            }
            used[j][a[i][j]] = true;
        }
    }

    // cols -> nums
    auto bipartite_matching = [&](vector<vector<int>>& g) -> vector<int> {
        vector<int> mt(n + 1, -1);
        vector<bool> vis(n);

        function<bool(int)> try_kuhn = [&](int v) -> bool {
            if (vis[v])
                return false;
            vis[v] = true;
            for (int to : g[v]) {
                if (mt[to] == -1 || try_kuhn(mt[to])) {
                    mt[to] = v;
                    return true;
                }
            }
            return false;
        };

        vector<bool> pre_vis(n);
        for (int v = 0; v < n; v++) {
            for (int to : g[v]) {
                if (mt[to] == -1) {
                    mt[to] = v;
                    pre_vis[v] = true;
                    break;
                }
            }
        }

        for (int v = 0; v < n; v++) {
            if (pre_vis[v])
                continue;
            fill(vis.begin(), vis.end(), false);
            try_kuhn(v);
        }
        return mt;
    };

    for (int i = k; i < n; i++) {
        vector<vector<int>> g(n);
        for (int j = 0; j < n; j++) {
            for (int e = 1; e <= n; e++) {
                if (!used[j][e]) {
                    g[j].push_back(e);
                }
            }
        }
        vector<int> mt = bipartite_matching(g);
        for (int e = 1; e <= n; e++) {
            a[i][mt[e]] = e;
            used[mt[e]][e] = true;
        }
    }

    cout << "yes\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << a[i][j] << ' ';
        }
        cout << '\n';
    }

    return 0;
}