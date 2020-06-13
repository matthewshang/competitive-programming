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

int h, g;
pii hol[1000], gue[1000];
LL dp[1010][1010][2];

int dist(const pii& a, const pii& b) {
    return (b.fi - a.fi) * (b.fi - a.fi) + (b.se - a.se) * (b.se - a.se);
}

void print_state() {
    forn (k, 2) {
        forn (j, g + 1) {
            fora (i, 0, h) {
                cout << dp[i][j][k] << " ";
            }
            cout << endl;
        }
        cout << endl;
    }
}

int main() {
    io::setIO("checklist");
    cin >> h >> g;
    forn (i, h) cin >> hol[i].fi >> hol[i].se;
    forn (i, g) cin >> gue[i].fi >> gue[i].se;

    forn (i, h + 1) {
        forn (j, g + 1) {
            dp[i][j][0] = dp[i][j][1] = 1LL<<32;
        }
    }

    dp[1][0][0] = 0;
    forn (i, h + 1) {
        forn (j, g + 1) {
            forn (k, 2) {
                if (i == 0 && k == 0) continue;
                if (j == 0 && k == 1) continue;
                pii& last = k == 0 ? hol[i - 1] : gue[j - 1];
                if (i < h) {
                    dp[i + 1][j][0] = min(dp[i + 1][j][0], dp[i][j][k] + dist(last, hol[i]));
                }
                if (j < g) {
                    dp[i][j + 1][1] = min(dp[i][j + 1][1], dp[i][j][k] + dist(last, gue[j]));
                }                
            }
        }
    }
    // print_state();

    cout << dp[h][g][0] << endl;

    return 0;
}