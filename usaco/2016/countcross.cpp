#include "bits/stdc++.h"

using namespace std;

#define fi first
#define se second
#define fora(i, a, n) for (int i = (a); i < (n); ++i)
#define forn(i, n) for (int i = 0; i < (n); ++i)

typedef pair<int, int> pii;
typedef vector<int> vi;
typedef long long LL;

namespace io {
    void setIO(string s) {
        freopen((s + ".in").c_str(), "r", stdin);
        #ifndef TESTING 
        freopen((s + ".out").c_str(), "w", stdout);
        #endif
    }

    void pr(const vi &v) {
        forn(i, v.size()) cout << v[i] << " ";
        cout << endl;
    }

    template <typename T> void pr(T *arr, int n) {
        forn(i, n) cout << arr[i] << " ";
        cout << endl;
    }
}

int n, k, r;
bool road[100][100];
bool cow[100][100];
bool mark[100][100];
set<pair<int, int>> pairs;

const int xdir[4] = {1, 0, -1, 0}, ydir[4] = {0, 1, 0, -1};

void flood0(int row, int col, int c, bool last_was_road) {
    if (row < 0 || row >= n || col < 0 || col >= n || mark[row][col]) {
        return;
    }

    mark[row][col] = true;

    if (!last_was_road && road[row][col] && cow[row][col]) {
        pairs.insert(minmax(c, row * n + col));
    }

    if (!road[row][col]) forn (i, 4) flood0(row + xdir[i], col + ydir[i], c, false);
}

void flood(int row, int col) {
    forn (i, 100) forn (j, 100) mark[i][j] = false;
    int c = row * n + col;
    if (road[row][col]) {
        mark[row][col] = true;
        forn (i, 4) flood0(row + xdir[i], col + ydir[i], c, true);
    }
    flood0(row, col, c, road[row][col]);
}

int main() {
    io::setIO("countcross");
    cin >> n >> k >> r;
    forn (i, 100) forn (j, 100) road[i][j] = cow[i][j] = false;
    forn (i, r) {
        int a, b, c, d; cin >> a >> b >> c >> d;
        road[a - 1][b - 1] = road[c - 1][d - 1] = true;
    }
    forn (i, k) {
        int a, b; cin >> a >> b;
        cow[a - 1][b - 1] = true;
    }

    forn (i, 100) forn (j, 100) if (cow[i][j]) flood(i, j);
    cout << k * (k - 1) / 2 - pairs.size();

    return 0;
}