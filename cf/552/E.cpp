#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using vi = vector<int>;
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

#define FOR(i, a, b) for (int i=(a); i <=(b); i++)
#define F0R(i, a) for (int i=0; i < (a); i++)
#define RFOR(i, a, b) for (int i = (a); i >= b; i--)

const char nl = '\n';
const ll MOD = 1e9 + 7;
const ll INF = 1e18;

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);

    string s; cin >> s;
    s = "1*" + s + "*1";
    int n = sz(s);

    auto calc = [&](int l, int r) -> ll {
        if (l > r) return 0;
        if (l == r) return s[r - 1] - '0';
        ll ans = 0;
        int i = l;
        while (i < r) {
            if (s[i] == '*') {
                ll mul = s[i - 1] - '0';
                int j = i;
                while (j < r && s[j] == '*') {
                    mul *= s[j + 1] - '0';
                    j += 2;
                }
                i = j;
                ans += mul;
            } else {
                ans += s[i - 1] - '0';
            }
            i += 2;
        }
        if (s[r - 2] != '*') ans += s[r - 1] - '0';
        return ans;
    };

    vi loc;
    F0R (i, n) if (s[i] == '*') loc.pb(i);
    ll ans = 0;
    F0R (lo, sz(loc) - 1) {
        FOR (hi, lo + 1, sz(loc) - 1) {
            ll val = 0;
            ll mid = calc(loc[lo] + 2, loc[hi]);
            int i = loc[lo];
            while (i > 0 && s[i] == '*') {
                mid *= s[i - 1] - '0';
                i -= 2;
            }
            val += calc(1, i);
            i = loc[hi];
            while (i < n && s[i] == '*') {
                mid *= s[i + 1] - '0';
                i += 2;
            }
            val += calc(i + 2, n - 2);
            val += mid;
            ans = max(ans, val);
        }
    }
    cout << ans << endl;

    return 0;
}