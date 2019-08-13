#include "bits/stdc++.h"

using namespace std;

using ll = long long;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int k, x, y; cin >> k >> x >> y;

    int MX = 10;
    int MW = 2 * MX + 1;
    int g[MW][MW];
    for (int i = 0; i < MW; i++) for (int j = 0; j < MW; j++) g[i][j] = 0;
    queue<tuple<int, int, int>> q;
    q.emplace(0, 0, 1);
    while (!q.empty()) {
        auto [u, v, d] = q.front(); q.pop();
        if (u >= MW || u < 0 || v >= MW || v < 0) continue;

        if (g[u][v] != 0) continue;
        g[u][v] = d;

        for (int i = 1; i < k; i++) {
            q.emplace(u + i, v + k - i, d + 1);
            q.emplace(u - i, v + k - i, d + 1);
            q.emplace(u + i, v - (k - i), d + 1);
            q.emplace(u - i, v - (k - i), d + 1);
        }
        q.emplace(u, v + k, d + 1);
        q.emplace(u, v - k, d + 1);
        q.emplace(u + k, v, d + 1);
        q.emplace(u - k, v, d + 1);
    }
    for (int i = 0; i < MW; i++) {
        for (int j = 0; j < MW; j++) cout << g[i][j] << " ";
        cout << endl;
    }

    return 0;
}
