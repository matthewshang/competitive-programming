#include <bits/stdc++.h>
#include <ext/pb_ds/priority_queue.hpp>
using namespace std;

// Min-cost max-flow. Start with the following observations: the player with
// the highest skill wins all their games. Everyone else must lose once.
// Now make a winner and loser vertex for each player. Add the following edges:
//   1) From the source to the loser node with cost 0 and capacity 1.
//   2) From the winner node to the sink with cost 0 and capacity g-1.
//      For the player with the highest skill, make the capacity g.
//   3) From the loser node to every winner node of a player with a higher skill.
//
// This works because we need to guarantee that every player loses exactly
// once and wins at most g-1 times. The only exception is the overal winner,
// who doesn't lose once and wins up to g times. Using the capacity from
// one player's loss node to another's win node corresponds to the first
// player losing to the second at some point.

// MCMF from KACTL
constexpr int64_t INF = numeric_limits<int64_t>::max() / 4;

struct MCMF {
public:
    MCMF(int N) :
        N(N), ed(N), red(N), cap(N, vector<int64_t>(N)), flow(cap), cost(cap),
        seen(N), dist(N), pi(N), par(N) {}

    void addEdge(int from, int to, int64_t cap, int64_t cost) {
        this->cap[from][to] = cap;
        this->cost[from][to] = cost;
        ed[from].push_back(to);
        red[to].push_back(from);
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
        fill(pi.begin(), pi.end(), INF); pi[s] = 0;
        int it = N, ch = 1; int64_t v;
        while (ch-- && it--)
            for (int i = 0; i < N; i++) if (pi[i] != INF)
                for (int to : ed[i]) if (cap[i][to])
                    if ((v = pi[i] + cost[i][to]) < pi[to])
                        pi[to] = v, ch = 1;
        assert(it >= 0); // negative cost cycle
    }

private:
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
        for (int i = 0; i < N; i++) {
            pi[i] = min(pi[i] + dist[i], INF);
        }
    }

    int N;
    vector<vector<int>> ed, red;
    vector<vector<int64_t>> cap, flow, cost;
    vector<int> seen;
    vector<int64_t> dist, pi;
    vector<pair<int, int>> par;

};


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> s(n);
    vector<int> g(n);
    for (int i = 0; i < n; i++) {
        cin >> s[i] >> g[i];
    }

    auto build = [&](MCMF &F) {
        int winner = max_element(s.begin(), s.end()) - s.begin();
        for (int i = 0; i < n; i++) {
            // s -> L
            F.addEdge(0, 2 * i + 1, 1, 0);
            // W -> t
            if (i == winner) {
                F.addEdge(2 * i + 2, 2 * n + 1, g[i], 0);
            } else {
                F.addEdge(2 * i + 2, 2 * n + 1, g[i] - 1, 0);
            }
        }
    };

    // 0 = s, 2n+1 = t, 2i+1 = L, 2i+2 = W
    MCMF F(n * 2 + 2);
    build(F);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (s[i] < s[j]) {
                F.addEdge(2 * i + 1, 2 * j + 2, 1, s[i] ^ s[j]);
            }
        }
    }
    int64_t min_excite = F.maxflow(0, 2 * n + 1).second;

    F = MCMF(n * 2 + 2);
    build(F);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (s[i] < s[j]) {
                F.addEdge(2 * i + 1, 2 * j + 2, 1, -(s[i] ^ s[j]));
            }
        }
    }
    int64_t max_excite = -F.maxflow(0, 2 * n + 1).second;

    cout << min_excite << ' ' << max_excite << '\n';
    return 0;
}