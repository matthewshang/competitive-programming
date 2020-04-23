#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using vi = vector<int>;
using vvi = vector<vector<int>>;
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
    vi first; RMQ<pii> Q;
    LCA(int n, vvi& adj) { build(n, adj); }
    void build(int n, vvi& adj) {
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
    vvi adj(n);
    F0R (i, n - 1) {
        int a, b; cin >> a >> b;
        adj[a-1].pb(b-1); adj[b-1].pb(a-1);
    }
    LCA L(n, adj);
    vi h(n);
    h[0] = 0;
    function<void(int, int)> dfs = [&](int u, int p) {
        for (int x : adj[u]) if (x != p) {
            h[x] = h[u] + 1;
            dfs(x, u);
        }
    };
    dfs(0, -1);
    while (q--) {
        int a, b; cin >> a >> b;
        int d = h[a-1] + h[b-1] - 2 * h[L.query(a-1, b-1)];
        cout << d << endl;
    }

    return 0;
}
