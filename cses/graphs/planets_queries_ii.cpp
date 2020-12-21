#include "bits/stdc++.h"

using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
 
    int n, q; cin >> n >> q;
    vector<int> adj(n + 1);
    vector<vector<int>> radj(n + 1);
    for (int v = 1; v <= n; v++) {
        cin >> adj[v];
        radj[adj[v]].push_back(v);
    }
 
    vector<int> cycle_len;
    vector<pair<int, int>> cycle_pos(n + 1, { -1, -1 });
 
    vector<int> vis(n + 1);
    function<void(int)> dfs = [&](int v) {
        vis[v] = 1;
        int to = adj[v];
        if (vis[to] == 1) {
            int cycle_id = cycle_len.size();
            int len = 0;
            int cur = to;
            bool first = true;
            while (first || cur != adj[v]) {
                cycle_pos[cur] = { cycle_id, len };
                cur = adj[cur];
                first = false;
                len++;
            }
            cycle_len.push_back(len);
        }
 
        if (vis[to] == 0) {
            dfs(to);
        }
        vis[v] = 2;
    };
    
    for (int v = 1; v <= n; v++) {
        if (vis[v] == 0) {
            dfs(v);
        }
    }

    vector<int> time_in(n + 1);
    vector<int> time_out(n + 1);
    vector<int> dist_to_cycle(n + 1, 0);
    vector<int> tree_root(n + 1);
    int timer = 0;
    
    fill(vis.begin(), vis.end(), 0);
    function<void(int)> dfs2 = [&](int v) {
        vis[v] = 1;
        time_in[v] = ++timer;

        if (cycle_pos[v].first != -1) {
            tree_root[v] = v;
        }

        for (int to : radj[v]) {
            if (!vis[to]) {
                if (cycle_pos[to].first == -1) {
                    dist_to_cycle[to] = dist_to_cycle[v] + 1;
                    tree_root[to] = tree_root[v];
                }
                dfs2(to);
            }
        }

        time_out[v] = ++timer;
    };
    for (int v = 1; v <= n; v++) {
        if (vis[v] == 0 && cycle_pos[v].first != -1) {
            dfs2(v);
        }
    }
 
    while (q--) {
        int a, b; cin >> a >> b;
        int a_cycle_id = cycle_pos[a].first;
        int b_cycle_id = cycle_pos[b].first;

        if (a_cycle_id != -1 && b_cycle_id != -1) {
            if (a_cycle_id == b_cycle_id) {
                int a_off = cycle_pos[a].second;
                int b_off = cycle_pos[b].second;
                int len = cycle_len[a_cycle_id];
                cout << ((b_off - a_off + len) % len) << '\n';
            } else {
                cout << -1 << '\n';
            }
        } else if (a_cycle_id != -1 && b_cycle_id == -1) {
            cout << -1 << '\n';
        } else if (a_cycle_id == -1 && b_cycle_id != -1) {
            int root = tree_root[a];
            if (cycle_pos[root].first != b_cycle_id) {
                cout << -1 << '\n';
            } else {
                int root_off = cycle_pos[root].second;
                int b_off = cycle_pos[b].second;
                int len = cycle_len[b_cycle_id];
                cout << ((b_off - root_off + len) % len + dist_to_cycle[a]) << '\n';
            }
        } else {
            if (time_in[b] <= time_in[a] && time_out[a] <= time_out[b]) {
                cout << (dist_to_cycle[a] - dist_to_cycle[b]) << '\n';
            } else {
                cout << -1 << '\n';
            }
        }
    }
}
