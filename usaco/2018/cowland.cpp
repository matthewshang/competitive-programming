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

template <typename T> 
void pr(T& v) {
    cout << "{";
    bool f = true; for (auto& x : v) cout << (!f ? ", " : ""), f = false, pr(x);
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

    LCA(int n, vector<int>* adj) { build(n, adj); }

    void build(int n, vector<int>* adj) {
        // Get Euler tour
        int N = 2 * n - 1;
        vector<int> tour(N), height(N);
        int idx = 0;
        function<void(int, int, int)> build = [&](int u, int h, int p) {
            int i = idx++;
            height[i] = h; tour[i] = u;
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

// Operation must be reversible
struct BIT {
    vector<int> bit;
    int n;

    BIT(int n) {
        this->n = n + 1;
        bit.assign(n + 1, 0);
    }

    // 0 <= i < n
    int query(int i) {
        int ans = 0;
        for (++i; i > 0; i -= i & -i) ans ^= bit[i];
        return ans;
    }

    // 0 <= i < n
    void upd(int i, int val) {
        for (++i; i < n; i += i & -i) bit[i] ^= val;
    }

    // range update, point query
    void upd_range(int l, int r, int val) {
        upd(l, val);
        upd(r + 1, val);
    }
};

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    setIO("cowland");

    int n, q; cin >> n >> q;
    vector<int> e(n); for (int &x : e) cin >> x;
    
    vector<int> adj[n];
    for (int i = 0; i < n - 1; i++) {
        int u, v; cin >> u >> v;
        u--; v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    LCA L(n, adj);

    vector<int> id(n), sz(n), pos(n);
    BIT B(n);
    int cur_pos = 0;
    function<int(int, int)> buildSz = [&](int u, int p) {
        int idx = cur_pos++;
        pos[u] = idx;
        sz[idx] = 1;
        for (int x : adj[u]) if (x != p) sz[idx] += buildSz(x, u);
        return sz[idx];
    };
    buildSz(0, -1);

    function<void(int, int)> build = [&](int u, int p) {
        int idx = pos[u];
        B.upd_range(idx, idx + sz[idx] - 1, e[u]);
        for (int x : adj[u]) if (x != p) build(x, u);
    };
    build(0, -1);

    while (q--) {
        int t, i, j; cin >> t >> i >> j;
        if (t == 1) {
            i--;
            int delta = j ^ e[i];
            e[i] = j;
            B.upd_range(pos[i], pos[i] + sz[pos[i]] - 1, delta);
        } else {
            int u = pos[i - 1], v = pos[j - 1];
            int path = B.query(u) ^ B.query(v) ^ e[L.query(i - 1, j - 1)];
            cout << path << endl;
        }
    }

    return 0;
}
