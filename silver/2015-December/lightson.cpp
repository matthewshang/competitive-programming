#include "bits/stdc++.h"

using namespace std;

#define fi first
#define se second
#define fora(i, a, n) for (int i = (a); i < (n); ++i)
#define forn(i, n) for (int i = 0; i < (n); ++i)

typedef pair<int, int> pii;
typedef vector<int> vi;
typedef long long ll;

const int DIR[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

const int MAXN = 100;
int n, m;
bool lit[MAXN][MAXN];
bool visit[MAXN][MAXN];
bool mark[MAXN][MAXN];
map<pii, vector<pii>> switches;

void flood(queue<pii>& q, int r, int c) {
    if (r < 0 || r >= n || c < 0 || c >= n || mark[r][c]) {
        return;
    }
    mark[r][c] = true;

    if (!lit[r][c]) return;

    if (!visit[r][c]) {
        q.emplace(r, c);
    }

    forn(i, 4) {
        flood(q, r + DIR[i][0], c + DIR[i][1]);
    }
}

int count(int r, int c) {
    if (r < 0 || r >= n || c < 0 || c >= n || mark[r][c]) {
        return 0;
    }
    mark[r][c] = true;

    if (!lit[r][c]) return 0;

    int sum = 1;
    forn(i, 4) {
        sum += count(r + DIR[i][0], c + DIR[i][1]);
    }
    return sum;
}

int main() {
    ifstream in("lightson.in");
    in >> n >> m;
    forn(i, n) {
        int x, y, a, b;  in >> x >> y >> a >> b;
        switches[make_pair(x - 1, y - 1)].emplace_back(a - 1, b - 1);
    }
    forn(i, n) {
        forn(j, n) {
            lit[i][j] = false;
            visit[i][j] = false;
        }
    }

    lit[0][0] = true;
    queue<pii> rooms;
    rooms.emplace(0, 0);
    while (!rooms.empty()) {
        auto r = rooms.front();
        rooms.pop();
        if (visit[r.fi][r.se]) continue;

        visit[r.fi][r.se] = true;
        auto it = switches.find(r);
        if (it != switches.end()) {
            for (const auto& p : it->second) {
                lit[p.fi][p.se] = true;
            }
        }

        forn(i, n) forn(j, n) mark[i][j] = false;
        flood(rooms, 0, 0);
    }
    forn(i, n) forn(j, n) mark[i][j] = false;
    cout << count(0, 0) << endl;

    ofstream out("lightson.out");
    return 0;
}