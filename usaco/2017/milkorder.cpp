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

const int MAXM = 50000;

int N, M;
vi obs[MAXM];
map<int, vi> indeg_cache;

void dfs_build(int node, map<int, vi>& adj, bool* visited, vi& sorted) {
    if (visited[node]) return;
    visited[node] = true;

    sort(adj[node].begin(), adj[node].end(), greater<int>());
    for (auto x : adj[node]) {
        dfs_build(x, adj, visited, sorted);
    }

    sorted.push_back(node);
}

bool dfs(int node, map<int, vi>& adj, map<int, int>& status) {
    int stat = status[node];
    if (stat == 1) return true;
    else if (stat == -1) return false;
    status[node] = -1;

    for (auto x : adj[node]) {
        if (!dfs(x, adj, status)) {
            return false;
        }
    }

    status[node] = 1;
    return true;
}

bool ok(int X) {
    // cout << "ok: " << X << endl;

    // construct directed graph
    map<int, vi> adj;
    // 0 = not visited, 1 = visited, -1 = on stack
    map<int, int> status;
    set<int> indeg;
    F0R (i, X) {
        indeg.insert(obs[i][0]);
        F0R (j, obs[i].size() - 1) {
            int u = obs[i][j];
            int v = obs[i][j + 1];
            adj[u].push_back(v);
            status[u] = 0;
            auto it = indeg.find(v);
            if (it != indeg.end()) indeg.erase(it);
        }
    }
    // for (auto& x : adj) {
    //     cout << "adj " << x.fi << ": "; io::pr(x.se);
    // }

    if (indeg.empty()) return false;

    for (auto x : indeg) {
        indeg_cache[X].push_back(x);
        // cout << x << endl;
        if (!dfs(x, adj, status)) {
            return false;
        }
    }
    return true;
}

int main() {
    io::setIO("milkorder");

    cin >> N >> M;
    F0R (i, M) {
        int m; cin >> m;
        F0R (j, m) {
            int x; cin >> x;
            obs[i].push_back(x - 1);
        }
    }

    // binary search on number of observations
    int lo = 1, hi = M;
    while (lo <= hi) {
        int m = (lo + hi) / 2;
        if (ok(m)) {
            lo = m + 1;
        } else {
            hi = m - 1;
        }
    }
    // cout << "hi: " << hi << endl;

    // rebuild graph for hi and output
    map<int, vi> adj;
    F0R (i, hi) {
        F0R (j, obs[i].size() - 1) {
            int u = obs[i][j];
            int v = obs[i][j + 1];
            adj[u].push_back(v);
        }
    }

    vi sorted;
    bool visited[N];
    F0R (i, N) visited[i] = false;
    auto& indeg = indeg_cache[hi];
    sort(indeg.begin(), indeg.end(), greater<int>());
    // io::pr(indeg);
    F0R (i, indeg.size()) {
        dfs_build(indeg[i], adj, visited, sorted);
    }

    F0Rd (i, sorted.size() - 1) {
        cout << sorted[i];
        if (i > 0) cout << " ";
    }
    cout << endl;

    // final output - print out unused as well
    int un = 0;
    while (un < N && visited[un]) ++un;
    int to = sorted.size() - 1;
    int printed = 0;
    while (printed < N) {
        if (un < N && to >= 0) {
            if (un < sorted[to]) {
                cout << un + 1;
                ++un;
            } else {
                cout << sorted[to] + 1;
                --to;
            }
            printed++;
            if (printed < N) cout << " ";
        } else if (un < N) {
            while (un < N) {
                if (!visited[un]) {
                    cout << un + 1; printed++;
                    if (printed < N) cout << " ";
                }
                ++un;
            }
            break;
        } else if (to >= 0) {
            while (to >= 0) {
                cout << sorted[to] + 1; printed++;
                if (printed < N) cout << " ";
                --to;
            }
            break;
        }
        
    }
    cout << endl;
}
