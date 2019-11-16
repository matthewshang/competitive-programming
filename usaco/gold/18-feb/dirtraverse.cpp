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

int n;
vi edges[MAXN];
int parent[MAXN];
int lens[MAXN];
int nfiles[MAXN];
LL total_len = 0;
LL max_save = 0;

void fill_nfiles(int u) {
    for (int x : edges[u])
        fill_nfiles(x);
    
    if (edges[u].size() == 0) 
        nfiles[u] = 1;
    
    for (int x : edges[u]) 
        nfiles[u] += nfiles[x];
}

void dfs(int u, LL last_dot, LL last_save) {
    if (edges[u].size() == 0) return;

    LL save = last_save;
    save += (LL)nfiles[u] * (lens[u] - lens[parent[u]]);
    if (parent[u] == 0) save += nfiles[u];
    last_dot += nfiles[0] - nfiles[u];
    max_save = max(max_save, save - 3 * last_dot);

    for (int x : edges[u]) {
        dfs(x, last_dot, save);
    }
}

int main() {
    io::setIO("dirtraverse");
    cin >> n;
    parent[0] = -1;
    forn (i, n) nfiles[i] = lens[i] = 0;
    forn (i, n) {
        string s; int m, id;
        cin >> s >> m;
        
        if (i != 0) lens[i] += s.length() + (i == 0 || parent[i] == 0 ? 0 : 1);
        if (m == 0) {
            total_len += lens[i];
        }
        forn (j, m) {
            cin >> id; id--;
            lens[id] += lens[i];
            edges[i].push_back(id);
            parent[id] = i;
        }
    }
    fill_nfiles(0);

    for (int u : edges[0]) {
        dfs(u, 0, 0);
    }
    cout << total_len - max_save << endl;
    return 0;
}