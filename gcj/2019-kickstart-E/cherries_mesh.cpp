#include "bits/stdc++.h"

using namespace std;

using ll = long long;

template <int SZ>
struct DSU {
    int par[SZ];
    int sz[SZ];

    DSU(int n) {
        for (int i = 0; i < n; i++) {
            par[i] = i;
            sz[i] = 1;
        }
    }

    int find(int x) {
        if (par[x] != x)
            par[x] = find(par[x]);
        return par[x];
    }

    bool unite(int x, int y) {
        int u = find(x), v = find(y);
        if (u == v) return false;
        if (sz[u] < sz[v]) swap(u, v);
        sz[u] += sz[v];
        par[v] = u;
        return true;
    }
};

int solve() {
    int n, m; cin >> n >> m;
    DSU<100010> D(n);
    for (int i = 0; i < m; i++) {
        int c, d; cin >> c >> d;
        D.unite(c - 1, d - 1);
    }

    int red = 0;
    for (int i = 1; i < n; i++) {
        if (D.find(0) != D.find(i)) {
            D.unite(0, i);
            red++;
        }
    }

    return n - 1 + red;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    int T; cin >> T;
    for (int i = 1; i <= T; i++) {
        cout << "Case #" << i << ": " << solve() << endl;
    }

    return 0;
}
