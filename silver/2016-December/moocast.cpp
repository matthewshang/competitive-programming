#include "bits/stdc++.h"

using namespace std;

#define pb push_back
#define fi first
#define se second
#define forn(i, n) for (int i = 0; i < (n); ++i)

typedef pair<int, int> pii;
typedef vector<int> vi;
typedef long long ll;

const int MAXN = 200;
int n;
int x[MAXN], y[MAXN], r[MAXN];

bool can[MAXN][MAXN];
bool mark[MAXN];

int sum(int row) {
    mark[row] = true;
    int total = 0;
    forn(i, n) {
        if (can[row][i] && !mark[i]) {
            total += sum(i);
        }
    }
    return total + 1;
}

bool reach(int i, int j) {
    int a = x[i] - x[j];
    int b = y[i] - y[j];
    return a * a + b * b <= r[i] * r[i];
}

int main() {
    ifstream in("moocast.in");
    // ifstream in("cast/2.in");
    ofstream out("moocast.out");

    in >> n;
    forn(i, n) in >> x[i] >> y[i] >> r[i];

    forn(i, n) {
        forn(j, n) {
            if (i == j) can[i][j] = false;
            else can[i][j] = reach(i, j);
        }
    }

    int max_len = 0;
    forn(i, n) {
        forn(j, n) mark[j] = false;
        max_len = max(max_len, sum(i));
    }

    // cout << max_len << endl;
    out << max_len << endl;

    return 0;
}