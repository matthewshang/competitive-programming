#include <bits/stdc++.h>
using namespace std;

// Tree dp. The state at node i is a polynomial of degree at most m, where the
// jth coefficient is the number of ways to take a subset from the subtree of i
// with j reds and satisfying the ancestor condition. If we don't take a node,
// we can do anything with its children. If we do, either add 1 or x depending
// on its color. A node starts as 1, corresponding to not taking it. Doing
// the poly multiplication correctly means O(nm).

constexpr int MOD = 1e9 + 7;

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n + 1);
    for (int v = 2; v <= n; v++) {
        int p;
        cin >> p;
        adj[p].push_back(v);
    }
    vector<bool> red(n + 1);
    for (int i = 0; i < m; i++) {
        int v;
        cin >> v;
        red[v] = true;
    }

    auto mult = [&](const vector<int>& a, const vector<int>& b) -> vector<int> {
        int A = a.size(), B = b.size();
        int size = min(A + B - 1, m + 1);
        vector<int> c(size);
        for (int i = 0; i < A; i++) {
            for (int j = 0; j < B; j++) {
                if (i + j >= size) break;
                c[i + j] += (int64_t)a[i] * b[j] % MOD;
                c[i + j] %= MOD;
            }
        }
        return c;
    };

    function<vector<int>(int)> dfs = [&](int v) -> vector<int> {
        vector<int> p(1);
        p[0] = 1;
        for (int to : adj[v]) {
            auto q = dfs(to);
            p = mult(p, q);
        }
        if (red[v]) {
            if (p.size() < 2) {
                p.push_back(0);
            }
            p[1] = (p[1] + 1) % MOD;
        } else {
            p[0] = (p[0] + 1) % MOD;
        }
        return p;
    };
    auto p = dfs(1);
    while (int(p.size()) <= m) {
        p.push_back(0);
    }
    for (int i = 0; i <= m; i++) {
        cout << p[i] << '\n';
    }

    return 0;
}
