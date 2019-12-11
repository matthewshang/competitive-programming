#include "bits/stdc++.h"

using namespace std;
using ll = long long;

void setIO(string s) {
    freopen((s + ".in").c_str(), "r", stdin);
    #ifndef TESTING
    freopen((s + ".out").c_str(), "w", stdout);
    #endif
}

void pr(bool x) { cout << (x ? "true" : "false"); }
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
    pr("{");
    bool f = true; for (const auto& x : v) pr(!f ? ", " : ""), f = false, pr(x);
    pr("}");
}

void pd() { cout << "]" << endl; }

template <typename T, typename... U>
void pd(T first, U... rest) {
    pr(first); if (sizeof...(rest)) pr(", "); pd(rest...);
}

#ifdef TESTING
#define dbg(x...) cout << "[" << #x << "] = [", pd(x)
#else
#define dbg(...)
#endif

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    setIO("dining");

    int n, m, k; cin >> n >> m >> k;
    vector<pair<int, int>> adj[n + 1];
    for (int i = 0; i < m; i++) {
        int a, b, t; cin >> a >> b >> t;
        a--; b--;
        adj[a].emplace_back(b, t);
        adj[b].emplace_back(a, t);
    }

    vector<pair<int, int>> h(k);
    for (int i = 0; i < k; i++) {
        int u, val; cin >> u >> val;
        h[i] = {u - 1, val};
    }

    const int INF = 1e9;
    auto dijkstra = [&](int source, vector<int>& dist) {
        priority_queue<pair<int, int>> q;
        vector<bool> vis(n + 1, false);
        dist[source] = 0;
        q.emplace(0, source);
        while (!q.empty()) {
            int u = q.top().second; q.pop();
            if (vis[u]) continue;
            for (const auto& e : adj[u]) {
                int d = dist[u] + e.second;
                if (d < dist[e.first]) {
                    dist[e.first] = d;
                    q.emplace(-d, e.first);
                }
            }

            vis[u] = true;
        }
    };

    vector<int> dist(n + 1, INF);
    dijkstra(n - 1, dist);

    vector<int> dist_old = dist;
    for (int i = 0; i < k; i++) {
        int idx = h[i].first;
        int w = dist_old[idx] - h[i].second;
        adj[n].emplace_back(idx, w);
    }
    for (int i = 0; i <= n; i++) dist[i] = INF;
    dijkstra(n, dist);

    for (int i = 0; i < n - 1; i++)
        cout << (dist[i] <= dist_old[i]) << endl;

    return 0;
}
