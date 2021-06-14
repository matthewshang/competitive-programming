#include <bits/stdc++.h>
using namespace std;

// Do a BFS over a new graph with each node representing the three robots'
// positions in the original graph. At each node, try to move 1 or 2 robots o
// to another node in the original graph. After the BFS, an edge in the original
// graph can be painted if it was found at some point in the BFS.

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m, r, b, y;
	cin >> n >> m >> r >> b >> y;
	array<array<char, 101>, 101> g;
	for (auto& row : g) {
		fill(row.begin(), row.end(), '$');
	}
	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		char c;
		cin >> c;
		g[u][v] = g[v][u] = c;
	}

	array<array<bool, 101>, 101> used{};
	array<array<array<bool, 101>, 101>, 101> vis{};
	queue<array<int, 3>> q;
	q.push({r, b, y});
	vis[r][b][y] = true;
	while (!q.empty()) {
		auto [R, B, Y] = q.front();
		q.pop();
		for (int to = 1; to <= n; to++) {
			if (g[R][to] == 'R' || g[R][to] == 'X') {
				if (!vis[to][B][Y]) {
					q.push({to, B, Y});
					vis[to][B][Y] = true;
				}
				used[R][to] = true;
			} 
			if (g[B][to] == 'B' || g[B][to] == 'X') {
				if (!vis[R][to][Y]) {
					q.push({R, to, Y});
					vis[R][to][Y] = true;
				}
				used[B][to] = true;
			} 
			if (g[Y][to] == 'Y' || g[Y][to] == 'X') {
				if (!vis[R][B][to]) {
					q.push({R, B, to});
					vis[R][B][to] = true;
				}
				used[Y][to] = true;
			} 
			if (R == B && g[R][to] == 'P') {
				if (!vis[to][to][Y]) {
					q.push({to, to, Y});
					vis[to][to][Y] = true;
				}
				used[R][to] = true;
			}
			if (Y == R && g[Y][to] == 'O') {
				if (!vis[to][B][to]) {
					q.push({to, B, to});
					vis[to][B][to] = true;
				}
				used[Y][to] = true;
			}
			if (B == Y && g[B][to] == 'G') {
				if (!vis[R][to][to]) {
					q.push({R, to, to});
					vis[R][to][to] = true;
				}
				used[B][to] = true;
			}
		}
	}

	for (int u = 1; u <= n; u++) {
		for (int v = 1; v <= n; v++) {
			if (g[u][v] != 'X' && g[u][v] != '$' && !used[u][v] && !used[v][u]) {
				cout << 0 << '\n';
				return 0;
			}
		}
	}
	cout << 1 << '\n';

	return 0;
}