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

const int MAXN = 2000;
int A, B, n, m;
int a[MAXN], b[MAXN];

#define FLATTEN(row, col) ((row) * (n + 1) + (col))

struct DSU {
    int* par;
    int* sz;

    DSU(int s) {
        par = new int[s];
        sz = new int[s];
        forn (i, s) {
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
        if (sz[u] < sz[v]) {
            int tmp = u;
            u = v;
            v = tmp;
        }

        sz[u] += sz[v];
        par[v] = u;
        return true;        
    }
};

int main() {
    io::setIO("fencedin");
    cin >> A >> B >> n >> m;
    forn (i, n) cin >> a[i];
    forn (i, m) cin >> b[i];
    sort(a, a + n);
    sort(b, b + m);

    vector<pair<int, pii>> edges;
    forn (i, n + 1) {
        int d;
        if (i == 0) d = a[i];
        else if (i == n) d = A - a[n - 1];
        else d = a[i] - a[i - 1];

        forn (j, m) {
            edges.push_back(make_pair(d, make_pair(FLATTEN(j, i), FLATTEN(j + 1, i))));
        }
    }
    forn (j, m + 1) {
        int d;
        if (j == 0) d = b[j];
        else if (j == m) d = B - b[m - 1];
        else d = b[j] - b[j - 1];
        forn (i, n) {
            edges.push_back(make_pair(d, make_pair(FLATTEN(j, i), FLATTEN(j, i + 1))));
        }
    }
    sort(edges.begin(), edges.end());

    DSU D((n + 1) * (m + 1));
    LL answer;
    for (const auto& x : edges) {
        if (D.unite(x.se.fi, x.se.se)) {
            answer += x.fi;
        }
    }
    cout << answer << endl;

    return 0;
}