#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using vi = vector<int>;
using vb = vector<bool>;
using vvi = vector<vector<int>>;
using vll = vector<long long>;
using vpi = vector<pair<int, int>>;
using pii = pair<int, int>;
using pll = pair<long long, long long>;

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

const int DX[] = {1, 0, -1, 0};
const int DY[] = {0, 1, 0, -1};

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);

    int t; cin >> t;
    while (t--) {
        int n, m; cin >> n >> m;
        vector<string> g(n);
        F0R (i, n) cin >> g[i];

        vector<vb> reach(n, vb(m, false));
        function<void(int, int)> Dfs1 = [&](int r, int c) {
            if (r < 0 || r >= n || c < 0 || c >= m || g[r][c] == '#' || reach[r][c])
                return;

            reach[r][c] = true;
            F0R (i, 4) {
                Dfs1(r + DX[i], c + DY[i]);
            } 
        };
        Dfs1(n - 1, m - 1);

        bool ok = true;
        auto Set = [&](int r, int c) {
            if (r < 0 || r >= n || c < 0 || c >= m || g[r][c] != '.')
                return;
            g[r][c] = '#';
        };

        F0R (i, n) F0R (j, m) {
            if (g[i][j] == 'G' && !reach[i][j]) {
                ok = false;
            }
            if (g[i][j] == 'B' && reach[i][j]) {
                F0R (k, 4) {
                    Set(i + DX[k], j + DY[k]);
                }
            }
        }

        if (ok) {
            F0R (i, n) F0R (j, m) reach[i][j] = false;
            Dfs1(n - 1, m - 1);
            F0R (i, n) F0R (j, m) {
                if (g[i][j] == 'G' && !reach[i][j])
                    ok = false;
                if (g[i][j] == 'B' && reach[i][j])
                    ok = false;
            }
        }

        cout << (ok ? "Yes" : "No") << nl;
    }

    return 0;
}
