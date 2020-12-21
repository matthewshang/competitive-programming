#include "bits/stdc++.h"

using namespace std;
 
int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
 
    int n; cin >> n;
    vector<int> adj(n + 1);
    for (int v = 1; v <= n; v++) {
        cin >> adj[v];
    }
 
    vector<vector<int>> cycles;
    vector<pair<int, int>> cycle_pos(n + 1, { -1, -1 });
    int l = ceil(log2(n));
    vector<vector<int>> down(n + 1, vector<int>(l + 1));
 
    vector<int> vis(n + 1);
    function<void(int)> dfs = [&](int v) {
        vis[v] = 1;
        int to = adj[v];
        if (vis[to] == 1) {
            int cycle_id = cycles.size();
            vector<int> cycle;
 
            int cur = to;
            while (cur != down[v][0]) {
                cycle_pos[cur] = { cycle_id, cycle.size() };
                cycle.push_back(cur);
                cur = down[cur][0];
            }
            cycles.push_back(cycle);
        }
 
        down[v][0] = adj[v];
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
 
    for (int i = 1; i <= l; i++) {
        for (int v = 1; v <= n; v++) {
            down[v][i] = down[down[v][i - 1]][i - 1];
        }
    }
 
    for (int v = 1; v <= n; v++) {
        int dist_to_cycle = 0;
        int cur = v;
        for (int i = l; i >= 0; i--) {
            if (cycle_pos[down[cur][i]].first == -1) {
                cur = down[cur][i];
                dist_to_cycle += 1 << i;
            }
        }
        int cycle_id = cycle_pos[cur].first;
        if (cycle_id == -1) {
            cur = down[cur][0];
            dist_to_cycle += 1;
            cycle_id = cycle_pos[cur].first;
        }
        assert(cycle_id != -1);

        cout << (dist_to_cycle + cycles[cycle_id].size()) << " ";
    }
    cout << '\n';
}