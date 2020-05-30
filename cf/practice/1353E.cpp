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

    int tt; cin >> tt;
    while (tt--) {
        int n, k; cin >> n >> k;
        string s; cin >> s;

        vi pre(n + 1);
        pre[0] = 0;
        F0R (i, n)
            pre[i + 1] = pre[i] + (s[i] == '1');
        vi use(n);
        vi dont(n);

        F0R (i, n) {
            if (i == 0) {
                use[i] = s[i] == '0';
                dont[i] = 1 - use[i];
            } else if (i < k) {
                use[i] = (s[i] == '0') + pre[i];
                dont[i] = (s[i] == '1') + min(use[i - 1], dont[i - 1]);
            } else {
                use[i] = (s[i] == '0') + min(pre[i], use[i - k] + pre[i] - pre[i - k + 1]);
                dont[i] = (s[i] == '1') + min(use[i - 1], dont[i - 1]);
            }
        }
        cout << min(use[n - 1], dont[n - 1]) << endl;
    }
    return 0;
}
