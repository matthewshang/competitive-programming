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

struct DSU {
    vector<int> par;
    vector<int> sz;

    DSU(int n) {
        par.resize(n);
        sz.resize(n);
        for (int i = 0; i < n; i++) {
            par[i] = i;
            sz[i] = 1;
        }
    }

    int find(int x) {
        if (x == par[x]) return x;
        return par[x] = find(par[x]);
    }

    bool join(int u, int v) {
        int a = find(u), b = find(v);
        if (a == b) return false;
        if (sz[a] < sz[b]) swap(a, b);
        par[b] = a;
        sz[a] += sz[b];
        return true;
    }
};

const ll MD = 1e9 + 7;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    setIO("cave");

    int n, m; cin >> n >> m;
    // grid[i][j] is true if it's water
    vector<vector<bool>> grid(n, vector<bool>(m));
    for (int i = 0; i < n; i++) {
        string s; cin >> s;
        for (int j = 0; j < m; j++) {
            grid[i][j] = (s[j] == '.');
        }
    }

    vector<DSU> D(n, DSU(m));
    vector<vector<int>> par(n, vector<int>(m, -1));
    for (int i = n - 2; i > 0; i--) {
        for (int j = 0; j < m - 1; j++) {
            if (grid[i][j] && grid[i][j + 1]) {
                D[i].join(j, j + 1);
            }
        }

        for (int j = 0; j < m; j++) {
            if (grid[i][j] && grid[i + 1][j]) {
                int v = D[i + 1].find(j);
                if (par[i + 1][v] == -1) {
                    par[i + 1][v] = D[i].find(j);
                } else {
                    int u = par[i + 1][v];
                    D[i].join(u, j);
                }
            }
        }
    }

    vector<vector<int>> adj(n * m + 1);
    vector<vector<bool>> vis(n, vector<bool>(m, false));
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (!grid[i][j]) continue; 

            int u = D[i].find(j);
            if (vis[i][u]) continue;
            else vis[i][u] = true;

            if (par[i][u] == -1) {
                adj[0].push_back(i * m + u + 1);
            } else {
                int v = D[i - 1].find(par[i][u]);
                adj[(i - 1) * m + v + 1].push_back(i * m + u + 1);
            }
        }
    }

    function<ll(int)> pull = [&](int u) -> ll {
        ll dp = 1;
        for (int x : adj[u]) {
            dp = (dp * pull(x)) % MD;
        }
        return (u == 0) ? dp : (dp + 1) % MD;
    };

    cout << pull(0) << endl;
    return 0;
}
