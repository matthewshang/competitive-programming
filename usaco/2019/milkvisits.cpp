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

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    setIO("milkvisits");

    int n, m; cin >> n >> m;
    vector<int> T(n);
    for (int& x : T) cin >> x;
    vector<int> adj[n];
    for (int i = 0; i < n - 1; i++) {
        int x, y; cin >> x >> y;
        x--; y--;
        adj[x].push_back(y); adj[y].push_back(x);
    }
    LCA L(n, adj);

    vector<int> A(m), B(m), C(m), U(m);
    map<int, vector<int>> mp;
    map<pair<int, int>, int> store;
    for (int i = 0; i < m; i++) {
        cin >> A[i] >> B[i] >> C[i];
        A[i]--; B[i]--; C[i]--;
        U[i] = L.query(A[i], B[i]);
        mp[A[i]].push_back(C[i]);
        mp[B[i]].push_back(C[i]);
        mp[U[i]].push_back(C[i]);
    }

    map<int, int> count;
    function<void(int, int)> dfs = [&](int u, int p) -> void {
        count[T[u] - 1]++;

        auto it = mp.find(u);
        if (it != mp.end()) {
            auto& v = it->second;
            for (int i = 0; i < v.size(); i++) {
                int type = v[i];
                int sz = count[type];
                store[make_pair(u, type)] = sz;
            }
        }

        for (int x : adj[u]) if (x != p) {
            dfs(x, u);
        }

        count[T[u] - 1]--;
    };
    dfs(0, -1);

    for (int i = 0; i < m; i++) {
        int X = store[make_pair(A[i], C[i])];
        int Y = store[make_pair(B[i], C[i])];
        int Z = store[make_pair(U[i], C[i])];
        int num = X + Y - 2 * Z + (T[U[i]] == C[i] + 1);
        cout << (num > 0);
    }
    cout << endl;

    return 0;
}
