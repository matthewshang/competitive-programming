#include <bits/stdc++.h>
using namespace std;

/* Date: 2022-03-04
 * Source: ECNA 2021
 * Notes: Try all pairs of leaves. For some reason traversing up every time
 * is still fast enough.
 */

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    vector<int> pages(n);
    for (int i = 0; i < n; i++) {
        cin >> pages[i];
    }

    vector<vector<int>> adj(n);
    vector<int> up(n, -1);
    for (int e = 0; e < m; e++) {
        int a, b;
        cin >> a >> b;
        adj[a - 1].push_back(b - 1);
        up[b - 1] = a - 1;
    }

    int best_cost = 1e9;
    for (int v = 0; v < n; v++) {
        if (!adj[v].empty()) {
            continue;
        }

        int cost = 0;
        vector<int> count(n);
        int cur = v;
        while (cur != -1) {
            count[cur]++;
            cost += pages[cur];
            cur = up[cur];
        }

        for (int other = 0; other < n; other++) {
            if (other == v || !adj[other].empty()) {
                continue;
            }

            int extra_cost = 0;
            cur = other;
            while (cur != -1) {
                if (count[cur] == 0) {
                    extra_cost += pages[cur];
                }
                count[cur]++;
                cur = up[cur];
            }

            best_cost = min(best_cost, cost + extra_cost);

            cur = other;
            while (cur != -1) {
                count[cur]--;
                cur = up[cur];
            }
        }
    }
    cout << best_cost << "\n";

    return 0;
}