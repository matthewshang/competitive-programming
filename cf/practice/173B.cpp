#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using vi = vector<int>;
using vvi = vector<vector<int>>;
using vll = vector<long long>;
using pii = pair<int, int>;
using pll = pair<long long, long long>;
using vpi = vector<pair<int, int>>;

#define F first
#define S second
#define pb push_back
#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()

#define FOR(i, a, b) for (int i=(a); i <=(b); i++)
#define F0R(i, a) for (int i=0; i < (a); i++)
#define RFOR(i, a, b) for (int i = (a); i >= b; i--)

const char nl = '\n';
const ll MOD = 1e9 + 7;
// const ll INF = 1e18;
const int INF = 1e9;

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);

    int n, m; cin >> n >> m;
    vector<string> g(n);
    vector<vpi> next(n, vpi(m, {-1, -1}));
    vector<vpi> prev(n, vpi(m, {-1, -1}));
    F0R (i, n) cin >> g[i];
    F0R (i, n) {
        int last = -1;
        RFOR (j, m - 1, 0) if (g[i][j] == '#') {
            next[i][j].F = last;
            last = j;
        }
        last = -1;
        F0R (j, m) if (g[i][j] == '#') {
            prev[i][j].F = last;
            last = j;
        }
    }
    F0R (j, m) {
        int last = -1;
        RFOR (i, n - 1, 0) if (g[i][j] == '#') {
            next[i][j].S = last;
            last = i;
        }
        last = -1;
        F0R (i, n) if (g[i][j] == '#') {
            prev[i][j].S = last;
            last = i;
        }
    }

    vector<vpi> dist(n, vpi(m, {1e9, 1e9}));
    deque<array<int, 3>> q;
    F0R (j, m) if (g[0][j] == '#') {
        dist[0][j].F = 0;
        q.push_front({0, j, 0});
        break;
    }
    while (!q.empty()) {
        auto [i, j, dir] = q.front();
        q.pop_front();

        if (i == n - 1 && dir == 0) {
            cout << dist[i][j].F << endl;
            return 0;
        }

        if (dir == 0) {
            if (dist[i][j].F + 1 < dist[i][j].S) {
                dist[i][j].S = dist[i][j].F + 1;
                q.push_back({i, j, 1});
            }
            int e = next[i][j].F;
            if (e != -1 && dist[i][j].F < dist[i][e].F) {
                dist[i][e].F = dist[i][j].F;
                q.push_front({i, e, 0});
            }
            e = prev[i][j].F;
            if (e != -1 && dist[i][j].F < dist[i][e].F) {
                dist[i][e].F = dist[i][j].F;
                q.push_front({i, e, 0});
            }
        } else {
            if (dist[i][j].S + 1 < dist[i][j].F) {
                dist[i][j].F = dist[i][j].S + 1;
                q.push_back({i, j, 0});
            }
            int e = next[i][j].S;
            if (e != -1 && dist[i][j].S < dist[e][j].S) {
                dist[e][j].S = dist[i][j].S;
                q.push_front({e, j, 1});
            }
            e = prev[i][j].S;
            if (e != -1 && dist[i][j].S < dist[e][j].S) {
                dist[e][j].S = dist[i][j].S;
                q.push_front({e, j, 1});
            }
        }
    }
    cout << "-1\n";
    return 0;
    

    return 0;
}