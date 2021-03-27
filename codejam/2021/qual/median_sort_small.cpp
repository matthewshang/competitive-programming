#include "bits/stdc++.h"
using namespace std;

int query(int i, int j, int k) {
    cout << i << ' ' << j << ' ' << k << endl;
    int L; cin >> L;
    if (L == -1) {
        exit(0);
    }
    return L;
}

bool answer(vector<int>& a) {
    for (int x : a) {
        cout << x << ' ';
    }
    cout << endl;
    int res; cin >> res;
    return res == 1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T, N, Q; cin >> T >> N >> Q;
    for (int tc = 1; tc <= T; tc++) {
        vector<vector<int>> g(N + 1);

        auto has_cycle = [&]() -> bool {
            vector<int> vis(N + 1);
            function<bool(int)> dfs = [&](int v) -> bool {
                vis[v] = 1;
                for (int to : g[v]) {
                    if (vis[to] == 1) {
                        return true;
                    } else if (vis[to] == 0) {
                        if (dfs(to)) {
                            return true;
                        }
                    }
                }
                vis[v] = 2;
                return false;
            };

            for (int v = 1; v <= N; v++) {
                if (dfs(v)) {
                    return true;
                }
            }
            return false;
        };

        vector<array<int, 2>> edges;
        auto add_edge = [&](int u, int v) {
            edges.push_back({ u, v });
        };

        auto ask = [&](int i, int j, int k) {
            int mid = query(i, j, k);
            if (mid == i) {
                swap(i, j);
            } else if (mid == k) {
                swap(j, k);
            }

            g[j].push_back(i);
            g[k].push_back(j);
            if (has_cycle()) {
                g[j].pop_back();
                g[k].pop_back();
                
                g[i].push_back(j);
                g[j].push_back(k);
                add_edge(i, j);
                add_edge(j, k);
            } else {
                add_edge(j, i);
                add_edge(k, j);
            }
        };

        for (int i = 1; i <= N - 2; i++) {
            for (int j = i + 1; j <= N - 1; j++) {
                for (int k = j + 1; k <= N; k++) {
                    ask(i, j, k);
                }
            }
        }

        vector<int> indeg(N + 1);
        for (int v = 1; v <= N; v++) {
            for (int to : g[v]) {
                indeg[to]++;
            }
        }
        queue<int> q;
        for (int v = 1; v <= N; v++) {
            if (indeg[v] == 0) {
                q.push(v);
            }
        }

        vector<int> ord;
        while (!q.empty()) {
            int v = q.front();
            q.pop();
            ord.push_back(v);
            for (int to : g[v]) {
                indeg[to]--;
                if (indeg[to] == 0) {
                    q.push(to);
                }
            }
        }

        answer(ord);
    }

    return 0;
}