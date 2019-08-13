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
int c[MAXN];

int find_cut() {
    forn (i, n) {
        forn (j, n) {
            int pre = (c[j] - c[i] + n) % n;
            if (pre == 0) pre = n;
            if (i == 0) pre = c[j];
            if (pre < (j - i + n) % n + 1) break;
        }
        return i;
    }
    return n - 1;
}

int main() {
    io::setIO("cbarn");
    cin >> n;
    forn (i, n) {
        cin >> c[i];
        if (i > 0) c[i] += c[i - 1];
    }

    io::pr(c, n);
    int cut = find_cut();
    cout << cut << endl;

    
    return 0;
}