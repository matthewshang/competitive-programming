#include "bits/stdc++.h"
 
using namespace std;
using ll = long long;
 
const int MX = 300;
 
int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n, m, l; cin >> n >> m >> l;
    int adj[MX + 1][MX + 1];
    for (int i = 1; i <= MX; i++)
    for (int j = 1; j <= MX; j++)
        adj[i][j] = 0;

    for (int i = 0; i < m; i++) {
        int a, b, c; cin >> a >> b >> c;
        if (c > l) continue;
        adj[a][b] = adj[b][a] = c;
    }

    const ll INF = 1LL << 40;
    ll dist[MX + 1][MX + 1];
    int next[MX + 1][MX + 1];
    for (int i = 1; i <= MX; i++) {
        for (int j = 1; j <= MX; j++) {
            if (adj[i][j] > 0) {
                dist[i][j] = adj[i][j];
                next[i][j] = j; next[j][i] = i;
            } else {
                dist[i][j] = INF;
                next[i][j] = next[j][i] = -1;
            }
        }
    }

    for (int i = 1; i <= MX; i++) {
        dist[i][i] = 0;
        next[i][i] = i;
    }
    for (int k = 1; k <= MX; k++) {
        for (int i = 1; i <= MX; i++) {
            for (int j = 1; j <= MX; j++) {
                if (dist[i][j] > dist[i][k] + dist[k][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                    next[i][j] = next[i][k];
                }
            }
        }
    }

    int q; cin >> q;
    while (q--) {
        int s, t; cin >> s >> t;
        if (next[s][t] == -1) {
            cout << -1 << endl;
        } else {
            int ans = 0, fuel = l;
            while (s != t) {
                int u = next[s][t];
                int w = dist[s][u];
                if (fuel - w < 0) {
                    fuel = l;
                    ans++;
                }
                fuel -= w;
                s = u;
            }
            cout << ans << endl;
        }
    }
}
