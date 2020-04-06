// Range Minimum Queries II

#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using vi = vector<int>;
using pii = pair<int, int>;
using vpi = vector<pair<int, int>>;

#define f first
#define s second
#define pb push_back
#define mp make_pair
#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()

#define FOR(i, a, b) for (int i=(a); i <(b); i++)
#define F0R(i, a) for (int i=0; i < (a); i++)
#define RFOR(i, a, b) for (int i = (a); i >= b; i--)

// Source: Based on KACTL and bqi343
template <typename T>
struct Seg {
    const T ID = 2e9;
    T f(T a, T b) { return min(a, b); } // f should be associative
    vector<T> seg; int n;
    Seg(int _n) { n = _n; seg.assign(2 * n, ID); }
    void update(int pos, T val) {
        seg[pos += n] = val;
        for (pos /= 2; pos; pos /= 2) 
            seg[pos] = f(seg[2 * pos], seg[2 * pos + 1]);
    }
    T query(int l, int r) { // interval [l, r]
        T ra = ID, rb = ID;
        for (l += n, r += n + 1; l < r; l /= 2, r /= 2) {
            if (l & 1) ra = f(ra, seg[l++]);
            if (r & 1) rb = f(seg[--r], rb);
        }
        return f(ra, rb);
    }
};

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    int n, q; cin >> n >> q;
    Seg<int> S(n + 1);
    F0R (i, n) {
        int x; cin >> x;
        S.update(i + 1, x);
    }

    F0R (i, q) {
        int t, x, y; cin >> t >> x >> y;
        if (t == 1) {
            S.update(x, y);
        } else {
            cout << S.query(x, y) << endl;
        }
    }

    return 0;
}
