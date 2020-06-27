#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using vi = vector<int>;
using vb = vector<bool>;
using vvi = vector<vector<int>>;
using vll = vector<long long>;
using vpi = vector<pair<int, int>>;
using pii = pair<int, int>;
using pll = pair<long long, long long>;

#define F first
#define S second
#define pb push_back
#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()

#define FOR(i, a, b) for (int i = (a); i <= (b); ++i)
#define F0R(i, a) for (int i = 0; i < (a); ++i)
#define RFOR(i, a, b) for (int i = (a); i >= (b); --i)

const char nl = '\n';
const ll MOD = 1e9 + 7;

struct DSU {
    vi par;
    vi sz;

    DSU(int n) {
        par.resize(n);
        sz.resize(n);
        for (int i = 0; i < n; i++) {
            par[i] = i;
            sz[i] = 1;
        }
    }

    int find(int x) {
        if (x == par[x]) return x;
        return par[x] = find(par[x]);
    }

    bool join(int u, int v) {
        int a = find(u), b = find(v);
        if (a == b) return false;
        if (sz[a] < sz[b]) swap(a, b);
        par[b] = a;
        sz[a] += sz[b];
        return true;
    }
};

const int MAXN = 100010;

int n, m, k; 
vi adj[MAXN];

void dfs_tree(int u, int p, int color, vi& u1, vi& u2) {
    if (color == 0)
        u1.pb(u);
    else
        u2.pb(u);
    
    for (int x : adj[u]) if (x != p) {
        dfs_tree(x, u, 1 - color, u1, u2);
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);

    cin >> n >> m >> k;
    vpi In(m);
    F0R (i, m) cin >> In[i].F >> In[i].S;

    // Graph is a tree
    if (m == n - 1) {
        F0R (i, m) {
            int u = In[i].F;
            int v = In[i].S;
            adj[u].pb(v);
            adj[v].pb(u);
        }
        cout << "1" << nl;
        vi u1, u2;
        dfs_tree(1, 0, 1, u1, u2);
        int need = (k + 1) / 2;
        if (sz(u1) >= need) {
            F0R (i, need)
                cout << u1[i] << " ";
        } else {
            F0R (i, need)
                cout << u2[i] << " ";
        }

        cout << nl;
        return 0;
    } 

    // Find any cycle
    DSU D(n + 1);
    F0R (i, m) {
        int u = In[i].F;
        int v = In[i].S;
        if (D.find(u) == D.find(v)) {
            vb vis(n + 1, false);
            vi prev(n + 1, -1);
            queue<int> q({ u });
            while (!q.empty()) {
                int x = q.front(); q.pop();
                if (vis[x]) continue;
                vis[x] = true;
                if (x == v) break;

                for (int next : adj[x]) {
                    if (!vis[next]) {
                        prev[next] = x;
                        q.push(next);
                    }
                }
            }

            vi ul;
            int cur = v;
            while (cur != u) {
                ul.pb(cur);
                cur = prev[cur];
            }
            ul.pb(u);

            // cout << "UF ";
            // for (int x : ul) cout << x << " ";
            // cout << endl;

            int len = sz(ul);
            // cout << "LEN " << len << " " << sz(ul) << nl;
            // cout << "WhAT " << u << " " << v << nl;
            if (len <= k) {
                cout << "2 " << nl << len << nl;
                F0R (j, sz(ul))
                    cout << ul[j] << " ";
                cout << nl;
                return 0;
            } else {
                int lo = 0;
                int hi = sz(ul) - 1;
                map<int, int> pos;
                F0R (j, sz(ul))
                    pos[ul[j]] = j;
                FOR (j, i + 1, m - 1) {
                    int a = In[j].F;
                    int b = In[j].S;
                    auto ita = pos.find(a);
                    auto itb = pos.find(b);
                    if (ita == pos.end() || itb == pos.end()) continue;
                    int pa = ita->second;
                    int pb = itb->second;
                    if (pa > pb) swap(pa, pb);
                    if (lo <= pa && pb <= hi) {
                        lo = pa;
                        hi = pb;
                    }
                }

                if (hi - lo + 1 <= k) {
                    cout << "2" << nl;
                    cout << (hi - lo + 1) << nl;
                    FOR (j, lo, hi)
                        cout << ul[j] << " ";
                    cout << nl;
                } else {
                    cout << "1" << nl;
                    int need = (k + 1) / 2;
                    int j = lo;
                    while (need > 0 && j <= hi) {
                        cout << ul[j] << " ";
                        j += 2;
                        need--;
                    }
                    cout << nl;
                }
                return 0;
            }

        } else {
            D.join(u, v);
            adj[u].pb(v);
            adj[v].pb(u);
        }
    }

    return 0;
}
