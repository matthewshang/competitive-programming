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
    io::setIO("paintbarn");
    int n, k; cin >> n >> k;
    int g[1010][1010];
    int pre[1010][1010];
    F0R (i, 1010) F0R (j, 1010) g[i][j] = pre[i][j] = 0;

    int N = 0;
    F0R (i, n) {
        int x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;
        g[x1][y1]++; g[x2][y2]++;
        g[x1][y2]--; g[x2][y1]--;
        N = max(N, max(x2, y2));
    }

    pre[0][0] = g[0][0];
    FOR (i, 1, N + 1) {
        pre[0][i] = pre[0][i - 1] + g[0][i];
        pre[i][0] = pre[i - 1][0] + g[i][0];
    }

    int answer = 0;
    F0R (i, N + 1) {
        F0R (j, N + 1) {
            if (i && j) pre[i][j] = pre[i - 1][j] + pre[i][j - 1] - pre[i - 1][j - 1] + g[i][j];
            if (pre[i][j] == k) answer++;
        }
    }
    cout << answer << endl;
    return 0;
}
