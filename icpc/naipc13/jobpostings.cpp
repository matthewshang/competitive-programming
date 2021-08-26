#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/priority_queue.hpp>

/* Date: 2021-08-25
 * Source: NAIPC 2013
 * Summary: Min-cost max-flow. Make edges:
 *   - from source to students with cost 0/cap 1
 *   - from students to jobs with cost -1*satisfaction (to maxmimize)/cap 1
 *   - from jobs to sink with cost 0/cap depending on job positions
 * There are only n+m+4m ~= 500 edges.
 */

// Source: KACTL
constexpr int64_t INF = numeric_limits<int64_t>::max() / 4;
struct MCMF {
	int N;
	vector<vector<int>> ed, red;
	vector<vector<int64_t>> cap, flow, cost;
	vector<int> seen;
	vector<int64_t> dist, pi;
	vector<pair<int, int>> par;

	MCMF(int N) :
		N(N), ed(N), red(N), cap(N, vector<int64_t>(N)), flow(cap), cost(cap),
		seen(N), dist(N), pi(N), par(N) {}

	void addEdge(int from, int to, int64_t cap, int64_t cost) {
		this->cap[from][to] = cap;
		this->cost[from][to] = cost;
		ed[from].push_back(to);
		red[to].push_back(from);
	}

	void path(int s) {
        fill(seen.begin(), seen.end(), 0);
        fill(dist.begin(), dist.end(), INF);
		dist[s] = 0; int64_t di;

		__gnu_pbds::priority_queue<pair<int64_t, int>> q;
		vector<decltype(q)::point_iterator> its(N);
		q.push({0, s});

		auto relax = [&](int i, int64_t cap, int64_t cost, int dir) {
			int64_t val = di - pi[i] + cost;
			if (cap && val < dist[i]) {
				dist[i] = val;
				par[i] = {s, dir};
				if (its[i] == q.end()) its[i] = q.push({-dist[i], i});
				else q.modify(its[i], {-dist[i], i});
			}
		};

		while (!q.empty()) {
			s = q.top().second; q.pop();
			seen[s] = 1; di = dist[s] + pi[s];
			for (int i : ed[s]) if (!seen[i])
				relax(i, cap[s][i] - flow[s][i], cost[s][i], 1);
			for (int i : red[s]) if (!seen[i])
				relax(i, flow[i][s], -cost[i][s], 0);
		}
		for (int i = 0; i < N; i++) pi[i] = min(pi[i] + dist[i], INF);
	}

	pair<int64_t, int64_t> maxflow(int s, int t) {
		int64_t totflow = 0, totcost = 0;
		while (path(s), seen[t]) {
			int64_t fl = INF;
			for (int p,r,x = t; tie(p,r) = par[x], x != s; x = p)
				fl = min(fl, r ? cap[p][x] - flow[p][x] : flow[x][p]);
			totflow += fl;
			for (int p,r,x = t; tie(p,r) = par[x], x != s; x = p)
				if (r) flow[p][x] += fl;
				else flow[x][p] -= fl;
		}
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                totcost += cost[i][j] * flow[i][j];
            }
        }
		return {totflow, totcost};
	}

	// If some costs can be negative, call this before maxflow:
	void setpi(int s) { // (otherwise, leave this out)
        fill(pi.begin(), pi.end(), INF);
        pi[s] = 0;
		int it = N, ch = 1; int64_t v;
		while (ch-- && it--)
            for (int i = 0; i < N; i++) if (pi[i] != INF)
				for (int to : ed[i]) if (cap[i][to])
					if ((v = pi[i] + cost[i][to]) < pi[to])
						pi[to] = v, ch = 1;
		assert(it >= 0); // negative cost cycle
	}
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    while (true) {
        int n, m;
        cin >> n >> m;
        if (n == 0 && m == 0) {
            break;
        }
        MCMF F(m + n + 2);
        const int source = m + n;
        const int sink = m + n + 1;

        for (int job = 0; job < n; job++) {
            int positions;
            cin >> positions;
            F.addEdge(m + job, sink, positions, 0);
        }
        for (int student = 0; student < m; student++) {
            int year;
            cin >> year;
            F.addEdge(source, student, 1, 0);
            for (int choice = 0; choice < 4; choice++) {
                int job;
                cin >> job;
                int satisfaction = 4 * year - choice;
                F.addEdge(student, m + job, 1, -satisfaction);
            }
        }

        F.setpi(source);
        auto [flow, cost] = F.maxflow(source, sink);
        assert(flow == m);
        cout << -cost << '\n';
    }

    return 0;
}