#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;
#define sz(x) int((x).size())
#define rep(i, a, b) for (int i = (a); i < (b); i++)

struct Dinic {
	struct Edge {
		int to, rev;
		ll c, oc;
		ll flow() { return max(oc - c, 0LL); } // if you need flows
	};
	vi lvl, ptr, q;
	vector<vector<Edge>> adj;
	Dinic(int n) : lvl(n), ptr(n), q(n), adj(n) {}
	void addEdge(int a, int b, ll c, ll rcap = 0) {
		adj[a].push_back({b, sz(adj[b]), c, c});
		adj[b].push_back({a, sz(adj[a]) - 1, rcap, rcap});
	}
	ll dfs(int v, int t, ll f) {
		if (v == t || !f) return f;
		for (int& i = ptr[v]; i < sz(adj[v]); i++) {
			Edge& e = adj[v][i];
			if (lvl[e.to] == lvl[v] + 1)
				if (ll p = dfs(e.to, t, min(f, e.c))) {
					e.c -= p, adj[e.to][e.rev].c += p;
					return p;
				}
		}
		return 0;
	}
	ll calc(int s, int t) {
		ll flow = 0; q[0] = s;
		rep(L,0,31) do { // 'int L=30' maybe faster for random data
			lvl = ptr = vi(sz(q));
			int qi = 0, qe = lvl[s] = 1;
			while (qi < qe && !lvl[t]) {
				int v = q[qi++];
				for (Edge e : adj[v])
					if (!lvl[e.to] && e.c >> (30 - L))
						q[qe++] = e.to, lvl[e.to] = lvl[v] + 1;
			}
			while (ll p = dfs(s, t, LLONG_MAX)) flow += p;
		} while (lvl[t]);
		return flow;
	}
	bool leftOfMinCut(int a) { return lvl[a] != 0; }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int w, h;
        cin >> w >> h;
        int d, f, b;
        cin >> d >> f >> b;
        vector<string> g(h);
        for (int i = 0; i < h; i++) {
            cin >> g[i];
        }

        Dinic F(w * h + 2);
        auto id = [&](int r, int c) -> int {
            return r * w + c;
        };
        
        const int hole = w * h;
        const int grass = w * h + 1;
        const ll INF = 1e12;
        const array<int, 2> dirs[2] = {{1, 0}, {0, 1}};

        for (int r = 0; r < h; r++) {
            for (int c = 0; c < w; c++) {
                if (r == 0 || r == h - 1 || c == 0 || c == w - 1) {
                    F.addEdge(grass, id(r, c), INF, INF);
                } else {
                    int cost = (g[r][c] == '#') * d;
                    F.addEdge(grass, id(r, c), cost, cost);
                }
                int cost = (g[r][c] == '.') * f;
                F.addEdge(hole, id(r, c), cost, cost);

                for (auto [dx, dy] : dirs) {
                    int rr = r + dx;
                    int cc = c + dy;
                    if (0 <= rr && rr < h &&  0 <= cc && cc < w) {
                        F.addEdge(id(r, c), id(rr, cc), b, b);
                    }
                }
            }
        }

        ll cost = F.calc(hole, grass);
        cout << cost << '\n';
    }

    return 0;
}