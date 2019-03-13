#include "bits/stdc++.h"

using namespace std;

#define fi first
#define se second
#define fora(i, a, n) for (int i = (a); i < (n); ++i)
#define forn(i, n) for (int i = 0; i < (n); ++i)

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
        forn(i, v.size()) cout << v[i] << " ";
        cout << endl;
    }

    template <typename T> void pr(T *arr, int n) {
        forn(i, n) cout << arr[i] << " ";
        cout << endl;
    }
}

const int MAXN = 100000;

int n, q;
int enjoy[MAXN];
int parent[MAXN];
vi edges[MAXN];
int val[MAXN];

int dfs(int x, int p, int stop) {
    if (x == stop) return enjoy[x];

    for (int u : edges[x]) {
        if (u == p) continue;
        int v = dfs(u, x, stop);
        if (v > 0) return enjoy[x] ^ v;
    }
    return -1;
}

int query(int u, int v) {
    if (u > v) swap(u, v);
    if (u == 0) return val[v];
    else return val[parent[u]] ^ val[v];
}

int main() {
    io::setIO("cowland");
    cin >> n >> q;
    forn (i, n) cin >> enjoy[i];
    forn (i, n - 1) {
        int a, b; cin >> a >> b;
        a--; b--;
        edges[a].push_back(b);
        edges[b].push_back(a);
    }
    // io::pr(val, n);
    
    forn (k, q) {
        int t, i, j; cin >> t >> i >> j;
        if (t == 2) {
            // cout << query(i - 1, j - 1) << endl;
            cout << dfs(i - 1, -1, j - 1) << endl;
        } else {
            enjoy[i - 1] = j;
        }
    }

    return 0;
}