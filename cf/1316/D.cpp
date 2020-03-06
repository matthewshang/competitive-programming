#include "bits/stdc++.h"

using namespace std;
using ll = long long;

void pr(int x) { cout << x; }
void pr(ll x) { cout << x; }
void pr(size_t x) { cout << x; }
void pr(const char* s) { cout << s; }
void pr(string& s) { cout << s; }
void pr(bool x) { cout << (x ? "true" : "false"); }

template <typename T1, typename T2>
void pr(const pair<T1, T2>& p) {
    pr("{ "); pr(p.first); pr(", "); pr(p.second); pr(" }");
}

template <typename T> 
void pr(T& v) {
    cout << "{";
    bool f = true; for (const auto& x : v) cout << (!f ? ", " : ""), f = false, pr(x);
    cout << "}";
}

void pd() { cout << "]" << endl; }

template <typename T, typename... U>
void pd(T first, U... rest) {
    pr(first); if (sizeof...(rest)) cout << ", "; pd(rest...);
}

#ifdef TESTING
#define dbg(x...) cout << "[" << #x << "] = [", pd(x)
#else
#define dbg(...)
#endif

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    auto bad = []() -> void {
        cout << "INVALID" << endl;
        exit(0);
    };

    int n; cin >> n;
    char g[n][n];
    int r[n][n];
    int c[n][n];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int a, b; cin >> a >> b;
            if (a != -1) a--;
            if (b != -1) b--;
            r[i][j] = a; c[i][j] = b;
        }
    }
    int col[n][n];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            col[i][j] = -1;

    queue<pair<int, int>> que;
    vector<pair<int, int>> goal;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            g[i][j] = '_';
            if (r[i][j] == i && c[i][j] == j) {
                g[i][j] = 'X';
                col[i][j] = que.size();
                que.push({ i, j });
                goal.emplace_back(i, j);
            }
        }
    }
    int color_max = goal.size();
    
    int dir[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    char move[4] = {'U', 'D', 'L', 'R'};

    while (!que.empty()) {
        auto [u, v] = que.front(); que.pop();
        int color = col[u][v];
        for (int D = 0; D < 4; D++) {
            int i = u + dir[D][0], j = v + dir[D][1];
            if (i < 0 || i >= n || j < 0 || j >= n || col[i][j] != -1) continue;
            if (make_pair(r[i][j], c[i][j]) == goal[color]) {
                g[i][j] = move[D];
                col[i][j] = color;
                que.push({ i, j });
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (r[i][j] != -1 && c[i][j] != -1 && col[i][j] == -1)
                bad();
            if (r[i][j] == -1 && c[i][j] == -1 && col[i][j] == -1) {
                col[i][j] = color_max++;
                que.push({ i, j });
                bool good = false;
                for (int D = 0; D < 4; D++) {
                    int x = i + dir[D][0], y = j + dir[D][1];
                    if (x < 0 || x >= n || y < 0 || y >= n || col[x][y] != -1) continue;
                    if (r[x][y] == -1) {
                        good = true;
                        que.push({ x, y });
                        col[x][y] = col[i][j];
                        char invmove[4] = {'D', 'U', 'R', 'L'};
                        g[i][j] = invmove[D];
                        g[x][y] = move[D];
                        break;
                    }
                }
                if (!good) bad();

                while (!que.empty()) {
                    auto [u, v] = que.front(); que.pop();
                    int color = col[u][v];
                    for (int D = 0; D < 4; D++) {
                        int x = u + dir[D][0], y = v + dir[D][1];
                        if (x < 0 || x >= n || y < 0 || y >= n || col[x][y] != -1) continue;
                        if (r[x][y] == -1) {
                            g[x][y] = move[D];
                            col[x][y] = color;
                            que.push({x, y});
                        }
                    }
                }
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (g[i][j] == '_') bad();
        }
    }

    cout << "VALID" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            cout << g[i][j];
        cout << endl;
    }

    return 0;
}
