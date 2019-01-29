#include "bits/stdc++.h"

using namespace std;

#define pb push_back
#define fi first
#define se second
#define forn(i, n) for (int i = 0; i < (n); ++i)
#define fors(i, s, n) for (int i = (s); i < (n); ++i)

typedef pair<int, int> pii;
typedef vector<int> vi;
typedef long long ll;

const int MAXN = 1000;
int n;
int x[MAXN], y[MAXN];

bool graph[MAXN][MAXN];
bool mark[MAXN];

inline int dist(int a, int b) {
    return a * a + b * b;
}

int dfs(int i) {
    mark[i] = true;
    int sum = 1;
    forn(j, n) {
        if (graph[i][j] && !mark[j]) {
            sum += dfs(j);
        }
    }
    return sum;
}

bool ok(int X) {
    forn(i, n) {
        forn(j, i) {
            graph[i][j] = graph[j][i];
        }
        graph[i][i] = false;
        fors(j, i + 1, n) {
            graph[i][j] = dist(x[i] - x[j], y[i] - y[j]) <= X;
        }
    }
    // forn(i, n) {
    //     forn(j, n) {
    //         cout << graph[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    forn(i, n) mark[i] = false;
    return dfs(0) == n;
}

int main() {
    ifstream in("moocast.in");
    in >> n;
    int x1 = INT_MAX, y1 = INT_MAX, x2 = 0, y2 = 0;
    forn(i, n) {
        in >> x[i] >> y[i];
        x1 = min(x1, x[i]);
        y1 = min(y1, y[i]);
        x2 = max(x2, x[i]);
        y2 = max(y2, y[i]);
    }

    int lo = 0, hi = dist(x2 - x1, y2 - y1);
    // cout << hi << endl;
    // ok(hi / 2);
    while (lo <= hi) {
        int m = (lo + hi) / 2;
        if (ok(m)) {
            hi = m - 1;
        } else {
            lo = m + 1;
        }
    }
    // cout << lo << endl;

    ofstream out("moocast.out");
    out << lo << endl;
    return 0;
}