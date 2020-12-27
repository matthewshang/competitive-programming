#include "bits/stdc++.h"

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    #ifndef LOCAL
    freopen("gathering.in", "r", stdin);
    freopen("gathering.out", "w", stdout);
    #endif

    int N, M; cin >> N >> M;
    vector<vector<int>> adj(N + 1);
    for (int e = 0; e < N - 1; e++) {
        int x, y; cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    int L = ceil(log2(N));
    vector<vector<int>> up(N + 1, vector<int>(L + 1));
    vector<int> tin(N + 1);
    vector<int> tout(N + 1);
    int timer = 1;
    function<void(int, int)> dfs1 = [&](int v, int p) {
        tin[v] = timer++;
        up[v][0] = p;
        for (int i = 1; i <= L; i++) {
            up[v][i] = up[up[v][i - 1]][i - 1];
        }
        for (int to : adj[v]) {
            if (to != p) {
                dfs1(to, v);
            }
        }
        tout[v] = timer++;
    };
    dfs1(1, 1);

    auto is_ancestor = [&](int u, int v) -> bool {
        return tin[u] <= tin[v] && tout[v] <= tout[u];
    };

    int K = 2 * N;
    vector<bool> seg(4 * K, true);
    vector<bool> lazy(4 * K, false);
    auto push = [&](int v, int l, int r) {
        if (lazy[v]) {
            seg[v] = false;
            if (l != r) {
                lazy[2 * v] = true;
                lazy[2 * v + 1] = true;
            }
            lazy[v] = false;
        }
    };

    function<void(int, int, int, int, int)> update = [&](int v, int l, int r, int lo, int hi) {
        push(v, l, r);
        if (r < lo || l > hi) {
            return;
        }
        if (lo <= l && r <= hi) {
            lazy[v] = true;
            push(v, l, r);
        } else {
            int m = (l + r) / 2;
            update(2 * v, l, m, lo, hi);
            update(2 * v + 1, m + 1, r, lo, hi);
        }
    };

    function<bool(int, int, int, int)> query = [&](int v, int l, int r, int pos) -> bool {
        push(v, l, r);
        if (l == r) {
            return seg[v];
        } else {
            int m = (l + r) / 2;
            return pos <= m ? query(2 * v, l, m, pos) : query(2 * v + 1, m + 1, r, pos);
        }
    };

    vector<vector<int>> gr(N + 1);
    for (int i = 0; i < M; i++) {
        int a, b; cin >> a >> b;
        gr[a].push_back(b);
        if (is_ancestor(a, b)) {
            for (int j = L; j >= 0; j--) {
                if (is_ancestor(a, up[b][j]) && a != up[b][j]) {
                    b = up[b][j];
                }
            }
            update(1, 0, K - 1, 0, tin[b] - 1);
            update(1, 0, K - 1, tout[b] + 1, K - 1);
        } else {
            update(1, 0, K - 1, tin[a], tout[a]);
        }
    }

    vector<int> vis(N + 1, 0);
    bool bad = false;
    function<void(int)> dfs2 = [&](int v) {
        vis[v] = 1;
        for (int to : gr[v]) {
            if (vis[to] == 1) {
                bad = true;
            } else if (vis[to] == 0) {
                dfs2(to);
            }
        }
        vis[v] = 2;
    };
    for (int v = 1; v <= N; v++) {
        if (vis[v] == 0) {
            dfs2(v);
        }
    }

    if (bad) {
        for (int v = 1; v <= N; v++) {
            cout << 0 << '\n';
        }
    } else {
        for (int v = 1; v <= N; v++) {
            cout << query(1, 0, K - 1, tin[v]) << '\n';
        }
    }
}