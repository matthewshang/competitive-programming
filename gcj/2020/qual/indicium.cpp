#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using vi = vector<int>;
using pii = pair<int, int>;
using vpi = vector<pair<int, int>>;

#define f first
#define s second
#define pb push_back
#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()

#define FOR(i, a, b) for (int i=(a); i <=(b); i++)
#define F0R(i, a) for (int i=0; i < (a); i++)
#define RFOR(i, a, b) for (int i = (a); i >= b; i--)

void solve() {
    int n, k; cin >> n >> k;
    vector<vector<int>> g(n, vector<int>(n, -1));
    auto valid = [&](int r, int c) -> bool {
        F0R (i, r+1) F0R (j, r+1) if (i != j && g[i][c] == g[j][c]) return false;
        F0R (i, c+1) F0R (j, c+1) if (i != j && g[r][i] == g[r][j]) return false;
        return true;
    };
    function<bool(int, int)> back = [&](int r, int c) -> bool {
        if (r == n - 1 && c == n - 1) {
            int so_far = 0;
            F0R (i, n - 1) so_far += g[i][i];
            if (k - so_far > n || k - so_far <= 0) {
                return false;
            } else {
                g[r][c] = k - so_far;
                return valid(r, c);
            }
        }
        
        F0R (i, n) {
            g[r][c] = i + 1;
            if (valid(r, c)) {
                int next_c = c + 1;
                int next_r = r;
                if (next_c >= n) {
                    next_r = r + 1;
                    next_c = 0;
                }
                if (back(next_r, next_c)) return true;
            }
        }
        g[r][c] = -1;
        return false;
    };
    bool res = back(0, 0);
    if (res) {
        cout << "POSSIBLE\n";
        F0R (i, n) {
            F0R (j, n) cout << g[i][j] << " ";
            cout << endl;
        }
    } else {
        cout << "IMPOSSIBLE" << endl;
    }
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    int t; cin >> t;
    FOR (i, 1, t) {
        cout << "Case #" << i << ": ";
        solve();
    }

    return 0;
}
