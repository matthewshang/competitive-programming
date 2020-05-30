#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using vi = vector<int>;
using vb = vector<bool>;
using vvi = vector<vector<int>>;
using vll = vector<long long>;
using vpi = vector<pair<int, int>>;
using pii = pair<int, int>;
using pll = pair<long long, long long>;

#define F first
#define S second
#define pb push_back
#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()

#define FOR(i, a, b) for (int i = (a); i <= (b); ++i)
#define F0R(i, a) for (int i = 0; i < (a); ++i)
#define RFOR(i, a, b) for (int i = (a); i >= (b); --i)

const char nl = '\n';
const ll MOD = 1e9 + 7;
// const ll INF = 1e18;
const int INF = 1e8;

const int D[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);

    int n, m, t; cin >> n >> m >> t;
    vector<string> g(n);
    F0R (i, n) 
        cin >> g[i];

    vvi dist(n, vi(m, INF));
    queue<pii> q;
    bool any = false;
    F0R (i, n) {
        F0R (j, m) {
            int adj = 0;
            if (i > 0) 
                adj += g[i - 1][j] == g[i][j];
            if (i < n - 1) 
                adj += g[i + 1][j] == g[i][j];
            if (j > 0)
                adj += g[i][j - 1] == g[i][j];
            if (j < m - 1)
                adj += g[i][j + 1] == g[i][j];
            if (adj > 0) {
                dist[i][j] = 0;
                q.emplace(i, j);
                any = true;
            }
        }
    }

    while (!q.empty()) {
        auto [i, j] = q.front(); q.pop();
        F0R (d, 4) {
            int u = i + D[d][0];
            int v = j + D[d][1];
            if (u < 0 || u >= n || v < 0 || v >= m)
                continue;
            if (dist[i][j] + 1 < dist[u][v]) {
                dist[u][v] = dist[i][j] + 1;
                q.emplace(u, v);
            }
        } 
    }

    F0R (_t, t) {
        int i, j; cin >> i >> j;
        i--; j--;
        ll p; cin >> p;
        if (any) {
            if (p < dist[i][j]) {
                cout << g[i][j] << nl;
            } else {
                bool ori = g[i][j] == '1';
                cout << ((p - dist[i][j]) % 2 ? !ori : ori) << nl;
            }
        } else {
            cout << g[i][j] << nl;
        }
    }

    return 0;
}
