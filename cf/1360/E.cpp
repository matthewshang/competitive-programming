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

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);

    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<string> m(n);
        F0R (i, n)
            cin >> m[i];
        
        vector<vb> vis(n, vb(n, false));
        function<void(int, int)> Fill = [&](int i, int j) {
            if (i < 0 || j < 0 || vis[i][j] || m[i][j] == '0')
                return;
            vis[i][j] = true;
            Fill(i - 1, j);
            Fill(i, j - 1);
        };

        F0R (i, n) {
            if (!vis[i][n - 1])
                Fill(i, n - 1);
            if (!vis[n - 1][i])
                Fill(n - 1, i);
        }

        bool ok = true;
        F0R (i, n)
            F0R (j, n)
                if (m[i][j] == '1' && !vis[i][j])
                    ok = false;
        cout << (ok ? "YES" : "NO") << nl;
    }



    return 0;
}
