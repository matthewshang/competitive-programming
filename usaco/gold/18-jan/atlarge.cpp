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

const int MAXN = 100000, INF = 1<<30;
int n, k;
vi tree[MAXN];
int dist[MAXN];
int parent[MAXN];
int leafdist[MAXN];
vi leaves;

void dfs(int x, int depth, int p) {
    dist[x] = depth;
    parent[x] = p;
    for (int y : tree[x]) {
        if (y != p) dfs(y, depth + 1, x);
    }
    if (tree[x].size() == 1) {
        leaves.push_back(x);
    }
}

int dfs2(int x) {
    int sum = 0;
    for (int y : tree[x]) {
        if (y == parent[x]) continue;

        if (dist[y] == leafdist[y] || dist[x] == leafdist[y]) sum += 1;
        else sum += dfs2(y);
    }
    return sum;
}

int main() {
    io::setIO("atlarge");
    cin >> n >> k;
    k--;
    forn (i, n - 1) {
        int u, v; cin >> u >> v;
        u--; v--;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }

    dfs(k, 0, -1); 

    forn (i, n) leafdist[i] = INF;
    for (int x : leaves) {
        int d = 0;
        while (x != -1) {
            if (leafdist[x] < d) break;
            leafdist[x] = d;
            d++;
            x = parent[x];
        }
    }
    cout << dfs2(k) << endl;

    return 0;
}