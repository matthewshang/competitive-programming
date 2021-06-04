#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, m; cin >> n >> m;
    vector<string> g(n);
    for (int i = 0; i < n; i++) {
        cin >> g[i];
    }

    vector<vector<int>> c(n, vector<int>(m, -1));
    function<void(int, int, char, int)> fill = [&](int i, int j, char who, int v) {
        if (i >= 0 && i < n && j >= 0 && j < m && c[i][j] == -1 && g[i][j] == who) {
            c[i][j] = v;
            fill(i + 1, j, who, v);
            fill(i - 1, j, who, v);
            fill(i, j + 1, who, v);
            fill(i, j - 1, who, v);
        }
    };
    vector<int> val;
    int verts = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (c[i][j] == -1) {
                fill(i, j, g[i][j], verts++);
                val.push_back(g[i][j] - '0');
            }
        }
    }
    vector<int> out(verts, -1);
    for (int i = 0; i < n; i++) {
        out[c[i][0]] = '1' - g[i][0];
        out[c[i][m - 1]] = '1' - g[i][m - 1];
    }
    for (int j = 0; j < m; j++) {
        out[c[0][j]] = '1' - g[0][j];
        out[c[n - 1][j]] = '1' - g[n - 1][j];
    }
    int extra = 0;
    for (int i = 0; i < verts; i++) {
        if (out[i] != -1) {
            extra++;
            val.push_back(out[i]);
        }
    }
    int total = verts + extra;

    vector<vector<bool>> adj(total, vector<bool>(total));
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < m - 1; j++) {
            if (c[i][j] != c[i + 1][j]) {
                int u = c[i][j];
                int v = c[i + 1][j];
                adj[u][v] = adj[v][u] = true;
            }
            if (c[i][j] != c[i][j + 1]) {
                int u = c[i][j];
                int v = c[i][j + 1];
                adj[u][v] = adj[v][u] = true;
            }
        }
    }
    int extra_used = 0;
    for (int i = 0; i < verts; i++) {
        if (out[i] != -1) {
            int u = verts + extra_used;
            adj[i][u] = adj[u][i] = true;
            extra_used++;
        }
    }

    vector<int> mt(total, -1);
    vector<bool> used(total);
    function<bool(int)> try_kuhn = [&](int v) -> bool {
        if (used[v]) {
            return false;
        }
        used[v] = true;
        for (int to = 0; to < total; to++) if (adj[v][to]) {
            if (mt[to] == -1 || try_kuhn(mt[to])) {
                mt[to] = v;
                return true;
            }
        }
        return false;
    };
    for (int v = 0; v < total; v++) {
        if (val[v] == 0) {
            used.assign(total, false);
            try_kuhn(v);
        }
    }

    int matching = 0;
    for (int i = 0; i < total; i++) {
        if (mt[i] != -1) {
            matching++;
        }
    }
    cout << matching << '\n';

    return 0;
}