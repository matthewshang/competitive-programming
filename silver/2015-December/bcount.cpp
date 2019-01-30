#include "bits/stdc++.h"

using namespace std;

#define fi first
#define se second
#define fora(i, a, n) for (int i = (a); i < (n); ++i)
#define forn(i, n) for (int i = 0; i < (n); ++i)

typedef pair<int, int> pii;
typedef vector<int> vi;
typedef long long ll;

int leq(vi& v, int q) {
    int l = 0, r = v.size() - 1;
    while (l <= r) {
        int m = (l + r) / 2;
        // if (v[m] == q) {
        //     return m;
        // }
        if (v[m] <= q) {
            l = m + 1;
        } else {
            r = m - 1;
        }
    }
    return l;
}

int main() {
    int n, q;
    vi b[3];
    ifstream in("bcount.in");
    in >> n >> q;
    forn(i, n) {
        int id;  in >> id;
        b[id - 1].push_back(i + 1);
    }

    // forn(i, 3) {
    //     forn(j, b[i].size()) {
    //         cout << b[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    ofstream out("bcount.out");
    forn(i, q) {
        int s, e;  in >> s >> e;
        forn(j, 3) {
            out << leq(b[j], e) - leq(b[j], s - 1);
            if (j < 2) out << " ";
        }
        out << endl;
    }
    return 0;
}