#include "bits/stdc++.h"

using namespace std;

using ll = long long;

void solve() {
    int n, m; cin >> n >> m;
    vector<bool> vis(3 * n + 1, false);
    vector<int> res;
    for (int i = 1; i <= m; i++) {
        int u, v; cin >> u >> v;
        if (!vis[u] && !vis[v]) {
            res.push_back(i);
            vis[u] = true;
            vis[v] = true;
        }
    }

    if (res.size() >= n) {
        res.resize(n);
        cout << "Matching\n";
        for (int x : res) cout << x << " ";
        cout << endl;
    } else {
        res.clear();
        for (int i = 1; i <= 3 * n; i++) {
            if (!vis[i]) res.push_back(i);
        }
        res.resize(n);
        cout << "IndSet\n";
        for (int x : res) cout << x << " ";
        cout << endl;
    }
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    int T; cin >> T;
    while (T--) {
        solve();
    }

    return 0;
}
