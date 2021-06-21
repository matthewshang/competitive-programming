#include <bits/stdc++.h>
using namespace std;
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    int n, m;
    cin >> n >> m;
    vector<vector<int>> g(n + 1);
    vector<array<int, 2>> edges(m);
    map<array<int, 2>, array<int, 2>> dir;
    for (int e = 0; e < m; e++) {
        int a, b;
        cin >> a >> b;
        if (a > b) swap(a, b);
        g[a].push_back(b);
        g[b].push_back(a);
        edges[e] = {a, b};
    }
 
    auto get = [&](int a, int b) -> array<int, 2>& {
        if (a > b) swap(a, b);
        return dir[{a, b}];
    };
 
    vector<int> lvl(n + 1);
    lvl[1] = 1;
    vector<int> back(n + 1);
    function<void(int)> dfs = [&](int v) {
        for (int to : g[v]) {
            if (lvl[to] == 0) {
                lvl[to] = lvl[v] + 1;
                dfs(to);
                back[v] += back[to];
                get(v, to) = {v, to};
            } else if (lvl[v] < lvl[to]) {
                back[v] -= 1;
                get(v, to) = {to, v};
            } else if (lvl[v] > lvl[to]) {
                back[v] += 1;
                get(v, to) = {v, to};
            }
        }
        back[v] -= 1;
 
        if (lvl[v] != 1 && back[v] == 0) {
            cout << "IMPOSSIBLE" << '\n';
            exit(0);
        }
    };
    dfs(1);
    for (int v = 1; v <= n; v++) {
        if (lvl[v] == 0) {
            cout << "IMPOSSIBLE" << '\n';
            return 0;
        }
    }
 
    for (auto [a, b] : edges) {
        auto [u, v] = dir[{a, b}];
        cout << u << " " << v << '\n';
    }
 
    return 0;
}
