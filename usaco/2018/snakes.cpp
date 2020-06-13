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

int main() {
    io::setIO("snakes");
    int N, K; cin >> N >> K;
    K++;
    int a[N];
    F0R (i, N) cin >> a[i];

    const LL INF = 1LL<<32;
    LL dp[N][N][K];
    LL m[N][K];
    F0R (i, N) F0R (j, N) F0R(k, K) dp[i][j][k] = INF;
    F0R (i, N) F0R (j, K) m[i][j] = INF;

    F0R (i, N) {
        LL d = a[i] - a[0];
        if (d >= 0) {
            dp[0][i][0] = d;
            m[0][0] = min(m[0][0], d);
        }
    }

    FOR (i, 1, N) {
        FOR (j, 0, N) {
            FOR (k, 0, K) {
                LL d = a[j] - a[i];
                if (d >= 0) {
                    dp[i][j][k] = min(dp[i][j][k], dp[i - 1][j][k] + d);
                }
                if (k > 0 && d >= 0) {
                    dp[i][j][k] = min(dp[i][j][k], m[i - 1][k - 1] + d);
                }
                m[i][k] = min(m[i][k], dp[i][j][k]);
            }
        }
    }

    LL answer = INF;
    F0R (i, K) answer = min(answer, m[N - 1][i]);
    cout << answer << endl;
    return 0;
}
