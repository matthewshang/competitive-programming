#include <bits/stdc++.h>
using namespace std;

// Represent the state at each node with polynomials. Since the degree of
// a polynomial at a node is the size of the node's subtree, it turns out
// that the overall complexity is O(n^2) instead of O(n^3) for some reason.

template<class Fun>
class y_combinator_result {
    Fun fun_;
public:
    template<class T>
    explicit y_combinator_result(T &&fun): fun_(std::forward<T>(fun)) {}

    template<class ...Args>
    decltype(auto) operator()(Args &&...args) {
        return fun_(std::ref(*this), std::forward<Args>(args)...);
    }
};

template<class Fun>
decltype(auto) y_combinator(Fun &&fun) {
    return y_combinator_result<std::decay_t<Fun>>(std::forward<Fun>(fun));
}

int main() {
    int n;
    cin >> n;
    int64_t K;
    cin >> K;
    vector<vector<int>> adj(n + 1);
    for (int e = 0; e < n - 1; e++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    auto mult = [&](const vector<int64_t>& a, const vector<int64_t>& b) -> vector<int64_t> {
        vector<int64_t> c(a.size() + b.size() - 1);
        for (int i = 0; i < (int)a.size(); i++) {
            for (int j = 0; j < (int)b.size(); j++) {
                int64_t x = min((__int128_t)a[i] * b[j], (__int128_t)K);
                c[i + j] = min(c[i + j] + x, K);
            }
        }
        return c;
    };

    auto add = [&](vector<int64_t>& a, const vector<int64_t>& b) {
        for (int i = 0; i < (int)b.size(); i++) {
            a[i] = min(a[i] + b[i], K);
        }
    };

    vector<int64_t> t(n + 1);
    y_combinator([&](auto dfs, int v, int par) -> vector<int64_t> {
        vector<int64_t> p(2);
        p[1] = 1;
        for (int to : adj[v]) {
            if (to == par) {
                continue;
            }
            auto q = dfs(to, v);
            q[0] = 1;
            p = mult(p, q);
        }
        add(t, p);
        return p;
    })(1, 0);

    int64_t count = 0;
    for (int size = 1; size <= n; size++) {
        count += t[size];
        if (count >= K) {
            cout << size << '\n';
            return 0;
        }
    }
    cout << -1 << '\n';

}