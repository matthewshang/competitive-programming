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

struct LCA {
    vector<int> first;
    vector<vector<pair<int, int>>> st;

    void build(int n, vector<int>* adj, vector<int>& H) {
        // Get Euler tour
        int N = 2 * n - 1;
        vector<int> tour(N), height(N);
        int idx = 0;
        function<void(int, int, int)> build = [&](int u, int h, int p) {
            int i = idx++;
            height[i] = h; tour[i] = u;
            H[u] = h;
            for (int x: adj[u]) if (x != p) {
                build(x, h + 1, u);
                i = idx++;
                height[i] = h; tour[i] = u;
            }
        };
        build(0, 0, -1);

        first.resize(n, -1);
        for (int i = 0; i < 2 * n - 1; i++) {
            if (first[tour[i]] == -1) first[tour[i]] = i;
        }

        // Build RMQ
        int k = (int)floor(log2(N)) + 1;
        st.resize(N, vector<pair<int, int>>(k));
        for (int i = 0; i < N; i++)
            st[i][0] = { height[i], tour[i] };
        for (int j = 1; j <= k; j++)
            for (int i = 0; i + (1 << j) <= N; i++)
                st[i][j] = min(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]);
    }

    int query(int u, int v) {
        int a = first[u], b = first[v];
        if (a > b) swap(a, b);
        int j = (int)floor(log2(b - a + 1));
        return min(st[a][j], st[b - (1 << j) + 1][j]).second;
    }
};

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    int n; cin >> n;
    vector<int> adj[n];
    for (int i = 0; i < n - 1; i++) {
        int u, v; cin >> u >> v;
        u--; v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    LCA L;
    vector<int> h(n);
    L.build(n, adj, h);

    auto D = [&](int u, int v) -> int {
        return h[u] + h[v] - 2 * h[L.query(u, v)];
    };

    int q; cin >> q;
    while (q--) {
        int x, y, a, b, k; cin >> x >> y >> a >> b >> k;
        x--; y--; a--; b--;
        bool ok = false;
        int paths[3] = { D(a, b), D(a, x) + D(b, y) + 1, D(a, y) + D(b, x) + 1 };
        for (int i = 0; i < 3; i++) {
            if (k >= paths[i] && (k - paths[i]) % 2 == 0) {
                ok = true;
                break;
            }
        }
        cout << (ok ? "YES" : "NO") << endl;
    }

    return 0;
}
