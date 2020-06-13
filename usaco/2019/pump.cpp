#include "bits/stdc++.h"

using namespace std;
using ll = long long;

void setIO(string s) {
    freopen((s + ".in").c_str(), "r", stdin);
    #ifndef TESTING
    freopen((s + ".out").c_str(), "w", stdout);
    #endif
}

void pr(int x) { cout << x; }
void pr(ll x) { cout << x; }
void pr(size_t x) { cout << x; }
void pr(const char* s) { cout << s; }
void pr(string& s) { cout << s; }

template <typename T1, typename T2>
void pr(const pair<T1, T2>& p) {
    pr("{ "); pr(p.first); pr(", "); pr(p.second); pr(" }");
}

template <typename T> 
void pr(T& v) {
    cout << "{";
    bool f = true; for (const auto& x : v) cout << (!f ? ", " : ""), f = false, pr(x);
    cout << "}";
}

void pd() { cout << "]" << endl; }

template <typename T, typename... U>
void pd(T first, U... rest) {
    pr(first); if (sizeof...(rest)) cout << ", "; pd(rest...);
}

#ifdef TESTING
#define dbg(x...) cout << "[" << #x << "] = [", pd(x)
#else
#define dbg(...)
#endif

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    setIO("pump");

    int n, m; cin >> n >> m;
    vector<array<int, 4>> pipe(m);
    // 0: flow, 1: b, 2: cost, 3: a
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < 4; j++) {
            cin >> pipe[i][j];
        }
        swap(pipe[i][0], pipe[i][3]);
    }
    sort(pipe.begin(), pipe.end());
    for (int i = 0; i < m; i++) {
        dbg(i, pipe[i]);
    }

    vector<vector<int>> adj(n, vector<int>(n));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            adj[i][j] = -1;
    for (int i = 0; i < m; i++) {
        int a = pipe[i][3], b = pipe[i][1];
        a--; b--;
        adj[a][b] = pipe[i][2];
        adj[b][a] = pipe[i][2];
    }

    auto dijkstra = [&]() -> int {
        priority_queue<pair<int, int>> q;
        vector<bool> vis(n + 1, false);
        const int INF = 1e9;
        vector<int> dist(n, INF);
        dist[0] = 0;
        q.emplace(0, 0);
        while (!q.empty()) {
            int u = q.top().second; q.pop();
            if (u == n - 1) {
                return dist[u];
            }
            if (vis[u]) continue;
            for (int j = 0; j < n; j++) {
                int x = adj[u][j];
                if (x == -1) continue;

                int d = dist[u] + x;
                if (d < dist[j]) {
                    dist[j] = d;
                    q.emplace(-d, j);
                }
            }

            vis[u] = true;
        }
        return -1;
    };

    int i = 0;
    double ans = 0;
    while (i < m) {
        int flow = pipe[i][0];
        int cost = dijkstra();
        if (cost == -1) break;
        ans = max(ans, (double)flow / (double)cost);

        int j = i;
        while (j < m && pipe[j][0] == flow) {
            int a = pipe[j][3], b = pipe[j][1];
            a--; b--;
            adj[a][b] = -1;
            adj[b][a] = -1;
            j++;
        }
        i = j;
    }

    ll trun = (ll)floor(1000000.0 * ans);
    cout << trun << endl;

    return 0;
}
