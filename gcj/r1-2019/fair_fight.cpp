#include "bits/stdc++.h"

using namespace std;

#define fi first
#define se second
#define F0R(i, n) for (int i = 0; i < (n); ++i)
#define FOR(i, a, n) for (int i = (a); i < (n); ++i)
#define F0Rd(i, a) for (int i = (a); i >= 0; --i)

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

    template <typename T> void pr(const vector<T> &v) {
        F0R (i, v.size()) cout << v[i] << " ";
        cout << endl;
    }

    template <typename T> void pr(T *arr, int n) {
        F0R (i, n) cout << arr[i] << " ";
        cout << endl;
    }
}

struct Seg {
    int* seg;
    int sz;

    Seg(vi& v) {
        sz = v.size();
        seg = new int[2 * sz];
        F0R (i, sz) seg[i] = 0;
        F0R (i, sz) seg[sz + i] = v[i];
    }

    void build() {
        for (int i = sz - 1; i > 0; --i) seg[i] = max(seg[2 * i], seg[2 * i + 1]);
    }

    void update(int i, int val) {
        for (seg[i += sz] = val; i > 1; i >>= 1) {
            seg[i >> 1] = max(seg[i], seg[i ^ 1]);
        }
    }

    int query(int l, int r) {
        int res = 0;
        for (l += sz, r += sz; l < r; l >>=1, r >>= 1) {
            if (l & 1) res = max(res, seg[l++]);
            if (r & 1) res = max(seg[--r], res);
        }
        return res;
    }
};

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int T; cin >> T;
    FOR (tt, 1, T + 1) {
        int N, K; cin >> N >> K;
        vi C(N), D(N);
        F0R (i, N) cin >> C[i];
        F0R (i, N) cin >> D[i];
        
        Seg max_c(C), max_d(D);
        F0R (i, N) max_c.update(i, C[i]);
        F0R (i, N) max_d.update(i, D[i]);

        max_c.build(); max_d.build();
        cout << max_c.query(0, 2) << endl;

        int answer = 0;
        F0R (i, N) {
            FOR (j, i, N) {
                if (abs(max_c.query(i, j + 1) - max_d.query(i, j + 1)) <= K) ++answer;
            }
        }
        cout << "Case #" << tt << ": " << answer << endl;

    }
    return 0;
}
