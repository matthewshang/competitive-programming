#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using vi = vector<int>;
using pii = pair<int, int>;
using vpi = vector<pair<int, int>>;

#define f first
#define s second
#define pb push_back
#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()

#define FOR(i, a, b) for (int i=(a); i <=(b); i++)
#define F0R(i, a) for (int i=0; i < (a); i++)
#define RFOR(i, a, b) for (int i = (a); i >= b; i--)

const ll MOD = 1e9 + 7;
const int INF = 1e9;
const int DIR[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
const char MOV[4] = {'D', 'U', 'R', 'L'};

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    int n, m; cin >> n >> m;
    vector<string> g(n);
    F0R (i, n) cin >> g[i];
    pii start, end;
    F0R (i, n) {
        F0R (j, m) {
            if (g[i][j] == 'A') start = {i, j};
            if (g[i][j] == 'B') end = {i, j};
        }
    }
    
    char move[n][m];
    pii last[n][m];
    F0R (i, n) F0R (j, m) move[i][j] = '.';
    queue<pii> q;
    q.push(start);
    while (!q.empty()) {
        pii pos = q.front(); q.pop();
        if (pos == end) break;
        F0R (d, 4) {
            int r = pos.f + DIR[d][0], c = pos.s + DIR[d][1];
            if (r < 0 || r >= n || c < 0 || c >= m) continue;
            if (g[r][c] == '#' || move[r][c] != '.') continue;
            move[r][c] = MOV[d];
            last[r][c] = pos;
            q.emplace(r, c);
        }
    }

    if (move[end.f][end.s] == '.') {
        cout << "NO" << endl;
    } else {
        cout << "YES" << endl;
        string path = "";
        pii pos = end;
        while (pos != start) {
            path += move[pos.f][pos.s];
            pos = last[pos.f][pos.s];
        }
        reverse(all(path));
        cout << path.size() << endl << path << endl;
    }

    return 0;
}

