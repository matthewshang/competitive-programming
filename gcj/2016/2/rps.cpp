#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using vi = vector<int>;
using vb = vector<bool>;
using vvi = vector<vector<int>>;
using vll = vector<long long>;
using pii = pair<int, int>;
using pll = pair<long long, long long>;
using vpi = vector<pair<int, int>>;

#define F first
#define S second
#define pb push_back
#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()

#define FOR(i, a, b) for (int i = (a); i <= (b); ++i)
#define F0R(i, a) for (int i = 0; i < (a); ++i)
#define RFOR(i, a, b) for (int i = (a); i >= (b); --i)

const char nl = '\n';
const ll MOD = 1e9 + 7;
const ll INF = 1e18;

const int MAXN = 12;

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);

    int p[MAXN + 1][3], r[MAXN + 1][3], s[MAXN + 1][3];
    F0R (i, 3) p[0][i] = r[0][i] = s[0][i] = 0;
    p[0][0] = 1;
    r[0][1] = 1;
    s[0][2] = 1;
    F0R (i, MAXN) {
        F0R (j, 3) {
            p[i + 1][j] = p[i][j] + s[i][j];
            r[i + 1][j] = r[i][j] + p[i][j];
            s[i + 1][j] = s[i][j] + r[i][j];
            // cout << i << ", " << j << ": " << p[i + 1][j] << " " << r[i + 1][j] << " " << s[i + 1][j] << endl;
        }
    }

    string st[MAXN + 1][3];
    F0R (i, MAXN + 1) F0R (j, 3) st[i][j] = "";
    st[0][0] = "P";
    st[0][1] = "R";
    st[0][2] = "S";
    F0R (i, MAXN) {
        st[i + 1][0] = (st[i][0] < st[i][1]) ? (st[i][0] + st[i][1]) : (st[i][1] + st[i][0]);
        st[i + 1][1] = (st[i][1] < st[i][2]) ? (st[i][1] + st[i][2]) : (st[i][2] + st[i][1]);
        st[i + 1][2] = (st[i][2] < st[i][0]) ? (st[i][2] + st[i][0]) : (st[i][0] + st[i][2]);
    }

    int T; cin >> T;
    FOR (t, 1, T) {
        int N, R, P, S; cin >> N >> R >> P >> S;
        bool ok = false;
        F0R (j, 3) {
            if (r[N][j] == R && p[N][j] == P && s[N][j] == S) {
                cout << "Case #" << t << ": " << st[N][j] << endl;
                ok = true;
                break;
            }
        }
        if (!ok) {
            cout << "Case #" << t << ": IMPOSSIBLE\n";
        }
    }

    return 0;
}
