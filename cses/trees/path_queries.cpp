#include "bits/stdc++.h"

using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);

    int n, q; cin >> n >> q;
    vector<int> val(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> val[i];
    }

    vector<vector<int>> adj(n + 1);
    for (int e = 0; e < n - 1; e++) {
        int a, b; cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    vector<int> tin(n + 1);
    vector<int> tout(n + 1);
    int timer = 0;
    function<void(int, int)> dfs = [&](int v, int p) {
        tin[v] = timer++;
        for (int to : adj[v]) {
            if (to != p) {
                dfs(to, v);
            }
        }
        tout[v] = timer++;
    };
    dfs(1, 0);

    vector<long long> a(2 * n + 1);
    auto update = [&](int pos, long long delta) {
        for (; pos < 2 * n; pos |= pos + 1) a[pos] += delta;
    };

    auto query = [&](int pos) -> long long {
        long long res = 0;
        for (pos++; pos > 0; pos &= pos - 1) res += a[pos - 1];
        return res;
    };

    for (int v = 1; v <= n; v++) {
        update(tin[v], val[v]);
        update(tout[v], -val[v]);
    }

    while (q--) {
        int type; cin >> type;
        if (type == 1) {
            int s, x; cin >> s >> x;
            long long change = x - val[s];
            update(tin[s], change);
            update(tout[s], -change);
            val[s] = x;
        } else {
            int s; cin >> s;
            cout << query(tin[s]) << '\n';
        }
    }

    return 0;
}