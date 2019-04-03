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

    void pr(const vi &v) {
        F0R (i, v.size()) cout << v[i] << " ";
        cout << endl;
    }

    template <typename T> void pr(T *arr, int n) {
        F0R (i, n) cout << arr[i] << " ";
        cout << endl;
    }
}

const int MAXN = 100000;

struct BIT {
    int n;
    int b[MAXN + 1];

    BIT(int _n) : n(_n) {
        F0R (i, n + 1) b[i] = 0; 
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
    io::setIO("balance");
    int N; cin >> N;
    int a[N], b[N]; 
    F0R (i, N) cin >> a[i];
    F0R (i, N) cin >> b[i];
    
    BIT L(N), R(N);
    F0R (i, N) L.update(N - i - 1, 1 - a[i]);
    F0R (i, N) R.update(N - i - 1, 1 - b[i]);

    int l = 0, r = 0;
    int lz = 0, rz = 0;
    F0R (i, N) {
        l += L.query(i) * a[N - i - 1];
        r += R.query(i) * b[N - i - 1];
        lz += !a[i]; rz += !b[i];
    }
    cout << l << ", " << r << endl;
    cout << lz << ", " << rz << endl;

    int answer = 0;
    int d = abs(l - r);
    // int p = N - 1, q = 0;
    // while (l != r) {
        if (a[N - 1] == 1 && b[0] == 0) {
            // int x = N - L.query(N - 1) - 1;
            // int y = R.query(N - 1) - 1;
            int x = N - lz - 1, y = rz - 1;
            int d2 = abs(l + x - r - y); 
            if (d2 < d) {
                L.update(0, -1); R.update(N - 1, 1);
                answer++;
                d = d2;
                l += x; r += y;
                lz ++; rz --;
            }
        } else if (a[N - 1] == 0 && b[0] == 1) {
            // int x = N - L.query(N - 1);
            // int y = R.query(N - 1);
            int x = N - lz, y = rz;
            int d2 = abs(l - x - r + y);
            // cout << d2 << endl;
            if (d2 < d) {
                L.update(0, 1); R.update(N - 1, -1);
                answer++;
                d = d2;
                l -= x; r -= y;
                lz --; rz ++;
            }
        }
        answer += d;
        // } else {
             
        // }
    // }
    cout << answer << endl;
    return 0;
}
