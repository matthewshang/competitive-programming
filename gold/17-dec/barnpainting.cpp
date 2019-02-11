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
} // namespace io

const int MAXN = 100000;
const LL MOD = 1000000007;

int n, k;
set<int> tree[MAXN];
int parent[MAXN];
LL dp[MAXN][3];
bool cfixed[MAXN];
int root = -1;
LL answer = 1;

void insert_edge(int x, int y) {
    if (parent[x] == -1) {
        parent[x] = y;
        tree[y].insert(x);
    } else if (parent[y] == -1) {
        parent[y] = x;
        tree[x].insert(y);
    } else {
        int u = parent[x], v = x;
        while (u != -1) {
            int p = parent[u];
            tree[u].erase(v);
            tree[v].insert(u);
            parent[u] = v;
            v = u;
            u = p;
        } 
        parent[x] = y;
        tree[y].insert(x);
    }
}

void color(int u) {
    // cout << "node " << u << ": "; for (int x : tree[u]) cout << x << " ";
    // cout << endl;
    for (int x : tree[u]) {
        color(x);
    }

    LL a = dp[u][0], b = dp[u][1], c = dp[u][2];
    if (!cfixed[u]) {
        a = b = c = 1;
    }
    for (int x : tree[u]) {
        a = (a * ((dp[x][1] + dp[x][2]) % MOD)) % MOD;
        b = (b * ((dp[x][2] + dp[x][0]) % MOD)) % MOD;
        c = (c * ((dp[x][0] + dp[x][1]) % MOD)) % MOD;
    }

    // cout << u << ": "; io::pr(dp[u], 3);
    if (cfixed[u] || u == root) {
        answer = (answer * ((a + b + c) % MOD)) % MOD;
    } else {
        dp[u][0] = a, dp[u][1] = b, dp[u][2] = c;
    }
}

int main() {
    io::setIO("barnpainting");
    cin >> n >> k;
    forn (i, n) parent[i] = -1;
    forn (i, n - 1) {
        int x, y;  cin >> x >> y;
        insert_edge(x - 1, y - 1);
    }

    forn (i, n) cfixed[i] = false;
    forn (i, n) forn (j, 3) dp[i][j] = 0;
    forn (i, k) {
        int b, c;  cin >> b >> c;
        dp[b - 1][c - 1] = 1;
        cfixed[b - 1] = true;
    }

    forn (i, n) {
        if (parent[i] == -1) {
            root = i;
            break;
        }
    }

    // cout << root << endl;
    color(root);
    cout << answer << endl;

    return 0;
}