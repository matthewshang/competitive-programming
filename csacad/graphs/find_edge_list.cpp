#include "bits/stdc++.h"

using namespace std;

using ll = long long;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    int n; cin >> n;
    int total = 0;
    vector<int> adj[n + 1];
    for (int i = 1; i <= n; i++) {
        int l; cin >> l;
        for (int j = 0; j < l; j++) {
            int u; cin >> u;
            adj[i].push_back(u);
        }
        total += l;
    }

    vector<pair<int, int>> edges;
    while (true) {
        bool flag = false;
        for (int i = 1; i <= n; i++) {
            if (adj[i].size() == 0) continue;
            int u = adj[i].back();
            if (adj[u].back() == i) {
                edges.emplace_back(i, u);
                adj[i].pop_back();
                adj[u].pop_back();
                flag = true;
                total -= 2;
            }
        }

        if (total == 0) break;

        if (!flag) {
            cout << "-1\n";
            return 0;
        }
    }

    reverse(edges.begin(), edges.end());
    for (auto& e : edges) cout << e.first << " " << e.second << endl;

    return 0;
}
