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
    template <typename T> void pr(const vector<T> &v) {
        F0R (i, v.size()) cout << v[i] << " ";
        cout << endl;
    }

    template <typename T> void pr(T *arr, int n) {
        F0R (i, n) cout << arr[i] << " ";
        cout << endl;
    }
}

LL query(int D) {
    cout << D << endl;
    LL N; cin >> N;
    return N;
}

int answer(LL R[6]) {
    io::pr(R, 6);
    int res; cin >> res;
    return res;
}

int main() {
    int T, W; cin >> T >> W;
    F0R (tt, T) {
        LL R[6];

        LL N[6];
        F0R (i, 6) N[i] = query(i + 1);
        LL M[6];
        F0R (i, 4) M[i + 1] = N[i + 1] - N[0];
        M[5] = N[5] - 2 * N[0];
        

        io::pr(M, 6); io::pr(N, 6);
        R[0] = (M[5] - 2 * M[2] - 4 * M[1]) / 40;
        R[1] = M[1] - 2 * R[0];
        R[2] = M[2] - M[1] - 4 * R[0];
        R[3] = M[3] - M[2] - 8 * R[0] - 2 * R[1];
        R[4] = M[4] - 30 * R[0] - 3 * R[1] - R[2] - R[3];
        R[5] = N[0] - 2 * R[0] - R[1] - R[2] - R[3] - R[4];

        int res = answer(R);
        if (res == -1) break;
    }
    return 0;
}
