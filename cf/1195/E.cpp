#include "bits/stdc++.h"

using namespace std;

using ll = long long;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    int n, m, a, b; cin >> n >> m >> a >> b;
    ll g, x, y, z; cin >> g >> x >> y >> z;

    ll h[n][m];
    for (int i = 0; i < n * m; i++) {
        int r = i / m, c = i % m;
        h[r][c] = g;
        g = ((g * x) % z + y) % z;
    }

    int cell[n][m - b + 1];
    for (int i = 0; i < n; i++) {
        deque<pair<int, int>> q;
        for (int j = 0; j < m; j++) {
            while (!q.empty() && q.back().first > h[i][j]) q.pop_back();
            q.emplace_back(h[i][j], j);

            while (q.front().second <= j - b) q.pop_front();
            if (j >= b - 1) cell[i][j - b + 1] = q.front().first;
        }
    }

    ll ans = 0;
    for (int j = 0; j < m - b + 1; j++) {
        deque<pair<int, int>> q;
        for (int i = 0; i < n; i++) {
            while (!q.empty() && q.back().first > cell[i][j]) q.pop_back();
            q.emplace_back(cell[i][j], i);

            while (q.front().second <= i - a) q.pop_front();
            if (i >= a - 1) ans += q.front().first;
        }
    }
    cout << ans << endl;

    return 0;
}
