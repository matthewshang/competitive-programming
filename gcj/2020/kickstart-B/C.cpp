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
const ll MOD = 1e9;
const ll INF = 1e18;

void solve() {
    string s; cin >> s;
    int i = 0;

    function<pll(void)> go = [&]() -> pll {
        ll rep = s[i++] - '0';
        i++;
        pll ret = {0, 0};
        while (true) {
            if (s[i] == ')') {
                i++;
                break;
            } else if (s[i] == 'W') {
                ret.S = (ret.S - 1 + MOD) % MOD;
                i++;
            } else if (s[i] == 'E') {
                ret.S = (ret.S + 1) % MOD;
                i++;
            } else if (s[i] == 'S') {
                ret.F = (ret.F + 1) % MOD;
                i++;
            } else if (s[i] == 'N') {
                ret.F = (ret.F - 1 + MOD) % MOD;
                i++;
            } else {
                auto p = go();
                ret.F = (ret.F + p.F + MOD) % MOD;
                ret.S = (ret.S + p.S + MOD) % MOD;
            }
        }
        return {(rep * ret.F) % MOD, (rep * ret.S) % MOD};
    };

    s = "1(" + s + ")";
    auto res = go();
    cout << (res.S + 1) << " " << (res.F + 1) << nl;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);

    int t; cin >> t;
    FOR (i, 1, t) {
        cout << "Case #" << i << ": ";
        solve();
    }

    return 0;
}
