#include "bits/stdc++.h"

using namespace std;
using ll = long long;

void pr(int x) { cout << x; }
void pr(ll x) { cout << x; }
void pr(size_t x) { cout << x; }
void pr(const char* s) { cout << s; }
void pr(string& s) { cout << s; }
void pr(bool x) { cout << (x ? "true" : "false"); }

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

    int n, m; cin >> n >> m;
    vector<vector<int>> adj(n + 1);
    for (int i = 0; i < n - 1; i++) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> in(n + 1), out(n + 1);
    vector<int> par(n + 1), hei(n + 1);
    int time = 0;
    function<void(int, int, int)> dfs = [&](int u, int p, int h) -> void {
        par[u] = p;
        hei[u] = h;
        ++time;
        in[u] = time;
        for (int x : adj[u]) if (x != p) dfs(x, u, h + 1);
        ++time;
        out[u] = time;
    };
    dfs(1, 0, 0);
    par[1] = 1;

    auto query = [&](int u, int v) -> bool {
        if (u == v) return true;
        return ((in[u] < in[v] && out[u] > out[v]) ||
                (in[v] < in[u] && out[v] > out[u]) );
    };

    for (int i = 0; i < m; i++) {
        int k; cin >> k;
        vector<int> v(k); for (int& x : v) cin >> x;
        int deepest = 1;
        for (int j = 0; j < k; j++) {
            v[j] = par[v[j]];
            if (hei[v[j]] > hei[deepest]) {
                deepest = v[j];
            }
        }
        bool good = true;
        for (int j = 0; j < k; j++) {
            if (!query(deepest, v[j])) {
                good = false;
                break;
            }
        }
        cout << (good ? "YES" : "NO") << endl;
    }

    return 0;
}
