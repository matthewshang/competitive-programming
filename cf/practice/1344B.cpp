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
const ll INF = 1e18;

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);

    int n, m; cin >> n >> m;
    vector<string> g(n);
    F0R (i, n)
        cin >> g[i];

    int row_emp = n, col_emp = m;
    // rows
    F0R (i, n) {
        bool seen = false;
        int j = 0;
        while (j < m) {
            if (g[i][j] == '#') {
                if (seen) {
                    cout << "-1\n";
                    return 0;
                } else {
                    seen = true;
                    int k = j;
                    while (k < m && g[i][k] == '#')
                        k++;
                    j = k;
                }
            } else {
                j++;
            }
        }
        if (seen)
            row_emp--;
    }
    // cols
    F0R (j, m) {
        bool seen = false;
        int i = 0;
        while (i < n) {
            if (g[i][j] == '#') {
                if (seen) {
                    cout << "-1\n";
                    return 0;
                } else {
                    seen = true;
                    int k = i;
                    while (k < n && g[k][j] == '#')
                        k++;
                    i = k;
                }
            } else {
                i++;
            }
        }
        if (seen)
            col_emp--;
    }

    if ((!row_emp && col_emp) || (row_emp && !col_emp)) {
        cout << "-1\n";
        return 0;
    }

    vvi mark(n, vi(m, 0));
    function<void(int, int, int)> fill = [&](int i, int j, int color) {
        if (i < 0 || i >= n || j < 0 || j >= m || mark[i][j] != 0 || g[i][j] == '.')
            return;
        mark[i][j] = color;
        fill(i - 1, j, color);
        fill(i + 1, j, color);
        fill(i, j - 1, color);
        fill(i, j + 1, color);
    };
    int cur_color = 1;
    F0R (i, n) {
        F0R (j, m) {
            if (g[i][j] == '#' && mark[i][j] == 0) {
                fill(i, j, cur_color);
                cur_color++;
            }
        }
    }

    cout << (cur_color - 1) << endl;

    return 0;
}
