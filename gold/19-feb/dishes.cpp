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

const int MAXN = 100000;

int n;
int plate[MAXN]; 

struct BIT {
    int n;
    int b[MAXN + 1];

    BIT(int _n) : n(_n) {
        forn (i, n + 1) b[i] = 0; 
    }

    void update(int i, int v) {
        i++;
        for (; i <= n; i += i&-i)
            b[i] += v;
    }

    int query(int i) {
        i++;
        int s = 0;
        for (; i > 0; i -= i&-i)
            s += b[i];
        return s;
    }
};

bool ok(int m) {
    BIT B(m);
    bool interval[MAXN];
    forn (i, m) interval[i] = false;
    forn (i, m) {
        int e = plate[i];
        int j = B.query(e);
    }
}

int main() {
    io::setIO("dishes");
    cin >> n;
    forn (i, n) cin >> plate[i];

    int lo = 1, hi = n;
    while (lo <= hi) {
        int m = (lo + hi) / 2;
        if (ok(m)) {
            lo = m + 1;
        } else {
            hi = m - 1;
        }
    }
    cout << hi << endl;
    return 0;
}