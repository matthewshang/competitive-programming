const int l = ceil(log2(N));
vector<vector<int>> up(N + 1, vector<int>(l + 1));
vector<int> tin(N + 1);
vector<int> tout(N + 1);
int timer = 0;
function<void(int, int)> build_lca = [&](int v, int p) {
    tin[v] = ++timer;

    up[v][0] = p;
    for (int i = 1; i <= l; i++) {
        up[v][i] = up[up[v][i - 1]][i - 1];
    }
    for (int to : g[v]) {
        if (to != p) {
            build_lca(to, v);
        }
    }

    tout[v] = ++timer;
};
build_lca(1, 1);

auto is_ancestor = [&](int u, int v) -> bool {
    return tin[u] <= tin[v] && tout[v] <= tout[u];
};

auto lca = [&](int u, int v) -> int {
    if (is_ancestor(u, v)) {
        return u;
    }
    if (is_ancestor(v, u)) {
        return v;
    }
    for (int i = l; i >= 0; i--) {
        if (!is_ancestor(up[u][i], v)) {
            u = up[u][i];
        }
    }
    return up[u][0];
};