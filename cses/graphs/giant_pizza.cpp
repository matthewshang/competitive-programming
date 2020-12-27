#include "bits/stdc++.h"

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m; cin >> n >> m;
    // vertex 2k = + k, vertex 2k-1 = - k
    vector<vector<int>> adj(2 * m + 1);
    vector<vector<int>> radj(2 * m + 1);
    for (int e = 0; e < n; e++) {
        char type_a, type_b;
        int a, b;
        cin >> type_a >> a >> type_b >> b;

        int off_a = type_a == '+';
        int off_b = type_b == '+';
        adj[2 * a - (1 - off_a)].push_back(2 * b - off_b);
        adj[2 * b - (1 - off_b)].push_back(2 * a - off_a);

        radj[2 * a - off_a].push_back(2 * b - (1 - off_b));
        radj[2 * b - off_b].push_back(2 * a - (1 - off_a));
    }

    vector<int> ord;
    vector<bool> vis(2 * m + 1);
    function<void(int)> dfs1 = [&](int v) {
        vis[v] = true;
        for (int to : adj[v]) {
            if (!vis[to]) {
                dfs1(to);
            }
        }
        ord.push_back(v);
    };

    for (int v = 1; v <= 2 * m; v++) {
        if (!vis[v]) {
            dfs1(v);
        }
    }

    vector<int> comp(2 * m + 1);
    function<void(int, int)> dfs2 = [&](int v, int cc) {
        vis[v] = true;
        comp[v] = cc;
        for (int to : radj[v]) {
            if (!vis[to]) {
                dfs2(to, cc);
            }
        }
    };

    reverse(ord.begin(), ord.end());
    fill(vis.begin(), vis.end(), false);
    int cc = 1;
    for (int i = 0; i < 2 * m; i++) {
        int v = ord[i];
        if (!vis[v]) {
            dfs2(v, cc++);
        }
    }

    vector<char> toppings(m + 1);
    for (int v = 1; v <= m; v++) {
        if (comp[2 * v] == comp[2 * v - 1]) {
            cout << "IMPOSSIBLE" << '\n';
            return 0;
        } else if (comp[2 * v - 1] < comp[2 * v]) {
            toppings[v] = '-';
        } else {
            toppings[v] = '+';
        }
    }

    for (int v = 1; v <= m; v++) {
        cout << toppings[v] << ' ';
    }
    cout << '\n';
}