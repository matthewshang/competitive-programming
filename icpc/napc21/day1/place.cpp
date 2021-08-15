#include <bits/stdc++.h>
using namespace std;

struct BIT { // Operation must be reversible
    vector<int64_t> bit;
    BIT(int n) : bit(n) {}
    int64_t query(int pos) { // sum from [0, pos]
        int64_t ans = 0;
        for (pos++; pos > 0; pos &= pos - 1) ans += bit[pos - 1];
        return ans;
    }
    int64_t query(int l, int r) { // sum from [l, r]
        return query(r) - query(l - 1);
    }
    void update(int pos, int delta) { // a[pos] += delta; 
        for (; pos < (int)bit.size(); pos |= pos + 1) bit[pos] += delta;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;
    vector<int> wage(n + 1);
    vector<vector<int>> adj(n + 1);
    cin >> wage[1];
    for (int i = 2; i <= n; i++) {
        int par;
        cin >> wage[i] >> par;
        adj[par].push_back(i);
    }

    vector<int> tin(n + 1);
    vector<int> tout(n + 1);
    int timer = 0;
    function<void(int)> dfs = [&](int v) {
        tin[v] = ++timer;
        for (int to : adj[v]) {
            dfs(to);
        }
        tout[v] = ++timer;
    };
    dfs(1);

    BIT B(2 * n + 1);
    while (q--) {
        char type;
        cin >> type;
        if (type == 'p') {
            int a, x;
            cin >> a >> x;
            B.update(tin[a], x);
            B.update(tout[a], -x);
        } else {
            int a;
            cin >> a;
            int now = wage[a] + B.query(tin[a] - 1);
            cout << now << '\n';
        }
    }

    return 0;
}