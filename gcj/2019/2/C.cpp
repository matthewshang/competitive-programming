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

void solve() {
    auto reduce = [](pll f) -> pll {
        ll g = __gcd(f.F, f.S);
        return { f.F / g, f.S / g };
    };

    int n; cin >> n;
    vi C(n), J(n);
    F0R (i, n) cin >> C[i] >> J[i];

    pll lo = { 0, 1 };
    pll hi = { 1, 0 };
    F0R (i, n - 1) {
        if ((C[i + 1] == C[i] && J[i + 1] < J[i]) || 
            (J[i + 1] == J[i] && C[i + 1] < C[i])) {
            cout << "IMPOSSIBLE\n";
            return;
        } else if (C[i + 1] >= C[i] && J[i + 1] >= J[i]) {
            continue;
        } else {
            if (C[i + 1] > C[i]) {
                // cout << "ho " << i << endl;
                ll a = C[i + 1] - C[i], b = J[i] - J[i + 1];
                if (a * hi.S < b * hi.F) hi = reduce({ a, b });
            } else {
                // cout << "hi " << i << endl;
                ll a = C[i] - C[i + 1], b = J[i + 1] - J[i];
                if (b * lo.F < a * lo.S) lo = reduce({ a, b });
            }
        }
    }

    if (lo.F * hi.S >= lo.S * hi.F) {
        cout << "IMPOSSIBLE\n";
        return;
    }

    function<pll(pll, pll)> go = [&](pll l, pll r) -> pll {
        if (l.F < l.S && r.F <= r.S) {
            pll res = go({ r.S, r.F }, { l.S, l.F });
            return { res.S, res.F };
        } else if (l.F >= l.S && r.F >= r.S) {
            ll k = l.F / l.S;
            pll res = go({ l.F - k * l.S, l.S }, { r.F - k * r.S, r.S });
            return { res.F + k * res.S, res.S };
        } else {
            return { 1, 1 };
        }
    };
    
    // auto res = go(lo, hi);
    // res = reduce(res);
    // cout << lo.F << "/" << lo.S << "; " << hi.F << "/" << hi.S << endl;
    FOR (y, 1, 200) {
        int x = (lo.F * y) / lo.S + 1;
        if (x * hi.S < y * hi.F) {
            auto res = reduce({ x, y });
            cout << res.S << " " << res.F << endl;
            return;
        }
        // int l = lo.F * hi.S * y;
        // int r = lo.S * hi.F * y;
        // int m = lo.S * hi.S;
        // if ((l + m - 1) / m <= r / m) {
        //     cout << m << " " << ((l + m - 1) / m) << endl;
        //     return;
        // }
    }
    // cout << res.S << " " << res.F << endl;
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
