#include <bits/stdc++.h>
using namespace std;

// Represent the imposter lists as a graph where there's a directed edge
// from u to v if v is on u's list. Then if v is an imposter, u must be
// one too. We can just try every vertex. If the number of nodes that
// can reach the trial vertex is more than k, then it can't be an imposter.

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
decltype(auto) y_comb(Fun &&fun) {
    return y_combinator_result<std::decay_t<Fun>>(std::forward<Fun>(fun));
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;
    vector<vector<int>> adj(n + 1);
    for (int i = 1; i <= n; i++) {
        int s;
        cin >> s;
        for (int j = 0; j < s; j++) {
            int v;
            cin >> v;
            adj[v].push_back(i);
        }
    }

    vector<bool> vis(n + 1);
    auto dfs = y_comb([&](auto dfs, int v) -> int {
        int count = 1;
        vis[v] = true;
        for (int to : adj[v]) {
            if (!vis[to]) {
                count += dfs(to);
            }
        }
        return count;
    });

    for (int v = 1; v <= n; v++) {
        fill(vis.begin(), vis.end(), false);
        cout << (dfs(v) > k) << '\n';
    }

    return 0;
}