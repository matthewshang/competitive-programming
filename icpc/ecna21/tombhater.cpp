#include <bits/stdc++.h>
using namespace std;

/* Date: 2022-03-04
 * Source: ECNA 2021
 * Notes: Backtracking. Remember to build states correctly (dp[state] = distance
 * to end, not from start).
 */

constexpr int INF = 1e9;
vector<vector<char>> g;
int n, m, k;
vector<string> words;
int store[55][55][55][55][5];
int all_best = INF;

int explore(int r, int c, int w, int p, int last) {
    assert(0 <= r && r <= n && 0 <= c && c < m && 0 <= w && w < k && 0 <= p && p < int(words[w].size()));
    if (store[r][c][w][p][last] != -1) {
        return store[r][c][w][p][last];
    }
    if (r == n) {
        if (p == 0) {
            return 0;
        } else {
            return INF;
        }
    }

    if (g[r][c] != words[w][p]) {
        return INF;
    }

    if (p + 1 == int(words[w].size())) {
        int best = INF;
        for (int nw = 0; nw < k; nw++) {
            best = min(best, 1 + explore(r + 1, c, nw, 0, 2));
        }
        for (int nw = 0; nw < k; nw++) {
            if (last != 1 && c < m - 1) {
                best = min(best, 1 + explore(r, c + 1, nw, 0, 0));
            }
        }
        for (int nw = 0; nw < k; nw++) {
            if (last != 0 && c > 0) {
                best = min(best, 1 + explore(r, c - 1, nw, 0, 1));
            }
        }
        store[r][c][w][p][last] = best;
        return best;
    } else {
        int best = INF;
        best = min(best, 1 + explore(r + 1, c, w, p + 1, 2));
        if (last != 1 && c < m - 1) {
            best = min(best, 1 + explore(r, c + 1, w, p + 1, 0));
        }
        if (last != 0 && c > 0) {
            best = min(best, 1 + explore(r, c - 1, w, p + 1, 1));
        }
        store[r][c][w][p][last] = best;
        return best;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m >> k;
    g = vector<vector<char>>(n, vector<char>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> g[i][j];
        }
    }
    words.resize(k);
    for (int i = 0; i < k; i++) {
        cin >> words[i];
    }

    for (int i = 0; i < 55; i++) {
        for (int j = 0; j < 55; j++) {
            for (int b = 0; b < 55; b++) {
                for (int l = 0; l < 55; l++) {
                    for (int a = 0; a < 5; a++) {
                        store[i][j][b][l][a] = -1;
                    }
                }
            }
        }
    }

    for (int i = 0; i < m; i++) {
        for (int w = 0; w < k; w++) {
            int cost = explore(0, i, w, 0, 2);
            all_best = min(all_best, cost);
        }
    }
    if (all_best == INF) {
        cout << "impossible" << "\n";
    } else {
        cout << all_best << "\n";
    }

    return 0;
}