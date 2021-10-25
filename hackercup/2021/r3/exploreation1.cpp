#include <bits/stdc++.h>
using namespace std;

/* Date: 2021-10-09
 * Source: FB Hacker Cup 2021 R3
 * Summary: Step through times in non-increasing order, keeping track of
 * components with a DSU. Build a binary tree representing merges to greedily
 * assign robots after processing all events.
 */

struct dsu {
    vector<int> par, sizes, color;
    dsu(int n) : par(n), sizes(n, 1), color(n) { 
        iota(par.begin(), par.end(), 0);
        iota(color.begin(), color.end(), 0);
    }
    int make(int c) {
        int id = par.size();
        par.push_back(id);
        sizes.push_back(1);
        color.push_back(c);
        return id;
    }
    int get_color(int x) {
        return color[find(x)];
    }
    int find(int x) {
        if (x == par[x]) return x;
        return par[x] = find(par[x]);
    }
    bool join(int u, int v, int c) {
        int a = find(u), b = find(v);
        if (a == b) return false;
        if (sizes[a] < sizes[b]) swap(a, b);
        par[b] = a;
        sizes[a] += sizes[b];
        color[a] = c;
        return true;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    for (int tc = 1; tc <= T; tc++) {
        int R, C;
        cin >> R >> C;
        vector<vector<int>> H(R, vector<int>(C));
        vector<vector<int>> S(R, vector<int>(C));
        for (int i = 0; i < R; i++) {
            for (int j = 0; j < C; j++) {
                cin >> H[i][j];
            }
        }
        for (int i = 0; i < R; i++) {
            for (int j = 0; j < C; j++) {
                cin >> S[i][j];
            }
        }

        int collected = 0;
        set<int> times;
        map<int, vector<array<int, 2>>> time_sample;
        map<int, vector<array<int, 2>>> time_ready;
        for (int i = 0; i < R; i++) {
            for (int j = 0; j < C; j++) {
                 if (H[i][j] > S[i][j]) {
                     time_sample[S[i][j]].push_back({i, j});
                     collected++;
                 }
                 time_ready[H[i][j] - 1].push_back({i, j});
                 times.insert(-S[i][j]);
                 times.insert(-(H[i][j] - 1));
            }
        }

        dsu D(0);
        map<array<int, 2>, int> active;
        unordered_set<int> roots;
        int color = 0;
        vector<vector<int>> g;
        vector<bool> mark;
        for (int time : times) {
            time = -time;

            for (auto [i, j] : time_ready[time]) {
                active[{i, j}] = D.make(color++);
                g.push_back({});
                mark.push_back(false);
                for (auto [di, dj] : vector<array<int, 2>>{{1, 0}, {-1, 0}, {0, 1}, {0, -1}}) {
                    int ni = i + di;
                    int nj = j + dj;
                    if (auto next_it = active.find({ni, nj}); next_it != active.end()) {
                        int a = active[{i, j}];
                        int b = next_it->second;
                        if (D.find(a) != D.find(b)) {
                            g.push_back({D.get_color(a), D.get_color(b)});
                            mark.push_back(false);
                            D.join(a, b, color++);
                        }
                    }
                }
            }

            for (auto [i, j] : time_sample[time]) {
                mark[D.get_color(active[{i, j}])] = true;
            }
        }

        function<int(int)> dfs = [&](int v) -> int {
            int need = 0;
            for (int to : g[v]) {
                need += dfs(to);
            }
            return max(need, (int)mark[v]);
        };
        int ans = dfs(color - 1);
        cout << "Case #" << tc << ": " << collected << " " << ans << '\n';
    }

    return 0;
}