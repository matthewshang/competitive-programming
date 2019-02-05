#include "bits/stdc++.h"

using namespace std;

#define fi first
#define se second
#define fora(i, a, n) for (int i = (a); i < (n); ++i)
#define forn(i, n) for (int i = 0; i < (n); ++i)

typedef pair<int, int> pii;
typedef vector<int> vi;
typedef long long ll;

const int MAXN = 100000;

int n;
int p[MAXN];
int BIT[MAXN + 1];

void inc(int x) {
    x++;
    for (; x <= n; x += x&(-x))
        BIT[x] += 1;
}

int sum(int x) {
    x++;
    int s = 0;
    for (; x > 0; x -= x&(-x))
        s += BIT[x];
    return s;
}

int main() {
    ifstream in("sleepy.in");
    ofstream out("sleepy.out");
    in >> n;
    forn (i, n) {
        in >> p[i];
        p[i]--;
    }

    int j = n - 1;
    while (j > 0 && p[j] > p[j - 1]) {
        j--;
    }
    out << j << endl;
    fora (i, j, n) inc(p[i]);

    forn (i, j) {
        out << j - i - 1 + sum(p[i]);
        if (i < j - 1) out << " ";
        inc(p[i]);
    }
    out << endl;

    return 0;
}