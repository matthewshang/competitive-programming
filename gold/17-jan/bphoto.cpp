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

int main() {
    io::setIO("bphoto");
    int n;
    int h[MAXN], sorted[MAXN];
    unordered_map<int, int> htoi;
    cin >> n;
    forn (i, n) {
        cin >> h[i];
        sorted[i] = h[i];
        htoi[h[i]] = i;
    }
    sort(sorted, sorted + n);
    forn (i, n) {
        h[htoi[sorted[i]]] = i;
    }

    BIT L(n), R(n);
    int answer = 0;
    forn (i, n) R.update(h[i], 1);
    forn (i, n) {
        int l = i - L.query(h[i]);
        int r = n - i - R.query(h[i]);
        if (l > 2 * r || r > 2 * l) {
            answer++;
        }

        R.update(h[i], -1);
        L.update(h[i], 1);
    }
    cout << answer << endl;

    return 0;
}