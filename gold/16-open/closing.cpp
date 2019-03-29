#include "bits/stdc++.h"

using namespace std;

#define fi first
#define se second
#define F0R(i, n) for (int i = 0; i < (n); ++i)
#define FOR(i, a, n) for (int i = (a); i < (n); ++i)
#define F0Rd(i, a) for (int i = (a); i >= 0; --i)

typedef pair<int, int> pii;
typedef vector<int> vi;
typedef long long LL;

namespace io {
    void setIO(string s) {
        freopen((s + ".in").c_str(), "r", stdin);
        #ifndef TESTING
        freopen((s + ".out").c_str(), "w", stdout);
        #endif
    }

    void pr(const vi &v) {
        F0R (i, v.size()) cout << v[i] << " ";
        cout << endl;
    }

    template <typename T> void pr(T *arr, int n) {
        F0R (i, n) cout << arr[i] << " ";
        cout << endl;
    }
}

struct DSU {
    int* par;
    int* sz;

    DSU(int s) {
        par = new int[s];
        sz = new int[s];
        F0R (i, s) {
            par[i] = i;
            sz[i] = 1;
        }
    }

    int find(int x) {
        if (par[x] != x) 
            par[x] = find(par[x]);
        return par[x];
    }

    bool unite(int x, int y) {
        int u = find(x), v = find(y);
        if (u == v) return false;
        if (sz[u] < sz[v]) swap(u, v);
        sz[u] += sz[v];
        par[v] = u;
        return true;        
    }
};

int main() {
    io::setIO("closing");
    
    int N, M; cin >> N >> M;
    vi adj[N];
    int close[N];
    bool active[N];
    bool answer[N];
    DSU D(N);

    F0R (i, M) {
        int u, v; cin >> u >> v;
        u--; v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    F0R (i, N) {
        cin >> close[i];
        close[i]--;
        active[i] = false;
    }

    F0Rd (i, N - 1) {
        int u = close[i];
        active[u] = true;
        for (int x : adj[u]) if (active[x]) {
            D.unite(u, x);
        }
        answer[i] = (D.sz[D.find(u)] == N - i);
    }

    F0R (i, N) cout << (answer[i] ? "YES" : "NO") << endl;

    return 0;
}
