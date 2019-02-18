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

void print_state(int dp[11][3][3], int n, int m) {
    forn (k, 3) {
        cout << "k = " << k << endl;
        forn (j, m) {
            forn (i, n) cout << dp[i][j][k] << " ";
            cout << endl;
        }
        cout << endl;
    }
}

const int MAXN = 100000, MAXM = 20;

int main() {
    io::setIO("hps");
    int n, m;
    int dp[MAXN + 1][MAXM + 1][3];
    // int dp[10 + 1][2 + 1][3];
    int g[100000];
    cin >> n >> m;
    forn (i, n) {
        char c; cin >> c;
        if (c == 'H') g[i] = 0;
        else if (c == 'P') g[i] = 1;
        else g[i] = 2;
    }
    // io::pr(g, n);

    forn (i, n) forn (j, m) forn (k, 3) dp[i][j][k] = 0;

    dp[0][0][0] = g[0] == 0;
    dp[0][0][1] = g[0] == 1;
    dp[0][0][2] = g[0] == 2;

    forn (i, n) {
        forn (j, m) {
            forn (k, 3) {
                int k1 = (k + 1) % 3;
                int k2 = (k + 2) % 3;
                int equals = g[i + 1] == k;
                if (i < n) {
                    dp[i + 1][j][k] = max(dp[i + 1][j][k], dp[i][j][k] + equals);
                }

                if (i < n && j < m) {
                    int res = max(dp[i][j][k1] + (k == g[i + 1]), dp[i][j][k2] + (k == g[i + 1]));
                    dp[i + 1][j + 1][k] = max(dp[i + 1][j + 1][k], res);
                }
            }
        }
    }
    // print_state(dp, n, m + 1);
    cout << max(dp[n - 1][m][0], max(dp[n - 1][m][1], dp[n - 1][m][2])) << endl;;
    return 0;
}