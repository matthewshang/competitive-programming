#include "bits/stdc++.h"

using namespace std;

#define fi first
#define se second
#define F0R(i, n) for (int i = 0; i < (n); ++i)
#define FOR(i, a, n) for (int i = (a); i < (n); ++i)
#define F0Rd(i, a) for (int i = (a); i >= 0; --i)
#define FORd(i, a, b) for (int i = (a); i >= (b); --i)

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

LL d(int x, int y) {
    return -84 * x - 48 * y;
}

int main() {
    io::setIO("walk");

    int N, K; cin >> N >> K;
    vector<pair<int, pii>> edges;
    // FORd (i, N, 1) {
    //     FORd (j, N, i + 1) {
    //         edges.push_back(make_pair(d(i, j), make_pair(i, j)));
    //     }
    // }
    FOR (i, 1, N) {
        edges.push_back(make_pair(d(i, N), make_pair(i, N)));
    }

    sort(edges.begin(), edges.end());
    // DSU D(edges.size());
    // vector<pii> MST;
    // for (auto& a : edges) {
    //     if (D.unite(a.se.fi - 1, a.se.se - 1)) {
    //         MST.emplace_back(a.se.fi, a.se.se);
    //         // cout << a.se.fi << ", " << a.se.se << endl;
    //     }
    //     if (MST.size() == N - 1) break;
    // }

    // pii p = MST[N - K];
    pii p = edges[N - K].se;
    const LL MOD = 2019201997;
    cout << MOD + (LL) d(p.fi, p.se) << endl;
    return 0;
}
