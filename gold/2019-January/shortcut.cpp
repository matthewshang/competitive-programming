#include "bits/stdc++.h"

using namespace std;

#define fi first
#define se second
#define fora(i, a, n) for (int i = (a); i < (n); ++i)
#define forn(i, n) for (int i = 0; i < (n); ++i)

typedef pair<int, int> pii;
typedef vector<int> vi;
typedef long long ll;

namespace io {
    void pr(const vi& v, const string& s) {
        cout << s << ": ";
        forn (i, v.size()) cout << v[i] << " ";
        cout << endl;
    }

    template <typename T>
    void pr(T* arr, int n) {
        forn (i, n) cout << arr[i] << " ";
        cout << endl;
    }
}

const int MAXN = 10000;
vector<pii>* graph;
int c[MAXN];
int parent[MAXN];
int dist[MAXN];

void dijkstra(int n) {
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    forn (i, n) dist[i] = INT_MAX;

    pq.emplace(0, 0);
    dist[0] = 0;
    parent[0] = -1;

    while (!pq.empty()) {
        int u = pq.top().se;
        pq.pop();

        for (const auto& x : graph[u]) {
            int v = x.fi;
            int w = x.se;

            // cout << "dist: ";
            // forn (i, n) cout << dist[i] << " ";
            // cout << endl;
            // cout << "u: " << u << " v: " << v << " w: " << w << endl;;

            if (dist[v] > dist[u] + w) {
                dist[v] = dist[u] + w;
                pq.emplace(dist[v], v);
                parent[v] = u;
            }

            if (dist[v] == dist[u] + w && u < parent[v]) {
                parent[v] = u;
            }
        }
    }
    // forn (i, n) cout << parent[i] << " ";
    // cout << endl;
}

int main() {
    int n, m, t;
    ifstream in("shortcut.in");
    in >> n >> m >> t;
    forn (i, n) in >> c[i];
    graph = new vector<pii>[n];
    forn (i, m) {
        int u, v, w;
        in >> u >> v >> w;
        graph[u - 1].push_back(make_pair(v - 1, w));
        graph[v - 1].push_back(make_pair(u - 1, w));
    }

    dijkstra(n);

    vi pass(n, 0);
    forn (i, n) {
        int u = i;
        while (u != -1) {
            pass[u] += c[i];
            u = parent[u];
        }
        // io::pr(pass, "pass");
    }
    // io::pr(parent, n);
    // io::pr(c, n);
    ll max_saved = 0;
    forn (i, n) {
        ll saved = (ll)pass[i] * (ll)max(dist[i] - t, 0);
        max_saved = max(max_saved, saved);
    }
    // cout << max_saved << endl;

    ofstream out("shortcut.out");
    out << max_saved << endl;
    return 0;
}