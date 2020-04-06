#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using vi = vector<int>;
using pii = pair<int, int>;
using vpi = vector<pair<int, int>>;

#define f first
#define s second
#define pb push_back
#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()

#define FOR(i, a, b) for (int i=(a); i <=(b); i++)
#define F0R(i, a) for (int i=0; i < (a); i++)
#define RFOR(i, a, b) for (int i = (a); i >= b; i--)

template <typename T>
struct RMQ {
    vector<vector<T>> st;
    void build(vector<T>& v) {
        int t = __lg(sz(v));
        st.resize(t + 1);
        st[0].resize(sz(v));
        F0R (i, sz(v)) st[0][i] = v[i];
        F0R (l, t) {
            int m = sz(v) - (1 << (l + 1)) + 1;
            st[l + 1].resize(m);
            F0R (i, m) st[l + 1][i] = min(st[l][i], st[l][i + (1 << l)]);
        }
    }
    T query(int l, int r) { // [l, r]
        int t = __lg(r - l + 1);
        return min(st[t][l], st[t][r - (1 << t) + 1]);
    }
};

struct LCA {
    vector<int> first; RMQ<pii> Q;
    LCA(int n, vector<vector<int>>& adj) { build(n, adj); }
    void build(int n, vector<vector<int>>& adj) {
        int N = 2 * n - 1, idx = 0; vpi v(N);
        function<void(int, int, int)> dfs = [&](int u, int h, int p) {
            int i = idx++;
            v[i] = {h, u};
            for (int x : adj[u]) if (x != p) {
                dfs(x, h + 1, u);
                i = idx++;
                v[i] = {h, u};
            }
        };
        dfs(0, 0, -1);
        Q.build(v);
        first.resize(n, -1);
        for (int i = 0; i < 2 * n - 1; i++)
            if (first[v[i].s] == -1) first[v[i].s] = i;
    }
    int query(int u, int v) {
        int a = first[u], b = first[v];
        if (a > b) swap(a, b);
        return Q.query(a, b).s;
    }
};

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    int n, q; cin >> n >> q;
    vector<vector<int>> adj(n);
    FOR (i, 1, n - 1) {
        int e; cin >> e;
        adj[e - 1].push_back(i);
    }
    LCA L(n, adj);
    while (q--) {
        int a, b; cin >> a >> b;
        cout << (L.query(a - 1, b - 1) + 1) << endl;
    }

    return 0;
}
