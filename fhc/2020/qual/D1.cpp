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
// Source: Based on KACTL and bqi343
struct Seg {
    const ll ID = INF;
    ll f(ll a, ll b) { return min(a, b); } // f should be associative
    vector<ll> seg; int n;
    Seg(int _n) { n = _n; seg.assign(2 * n, ID); }
    void update(int pos, ll val) {
        seg[pos += n] = val;
        for (pos /= 2; pos; pos /= 2) 
            seg[pos] = f(seg[2 * pos], seg[2 * pos + 1]);
    }
    ll query(int l, int r) { // interval [l, r]
        ll ra = ID, rb = ID;
        for (l += n, r += n + 1; l < r; l /= 2, r /= 2) {
            if (l & 1) ra = f(ra, seg[l++]);
            if (r & 1) rb = f(seg[--r], rb);
        }
        return f(ra, rb);
    }
};

void solve(int tt) {
    int n, m; cin >> n >> m;
    vi c(n);
    F0R (i, n) cin >> c[i];

    int in_row = 0;
    FOR (i, 1, n - 2) {
        if (c[i] == 0) {
            in_row++;
        } else {
            in_row = 0;
        }
        if (in_row >= m) {
            cout << "Case #" << tt << ": -1" << nl;
            return;
        }
    }

    c[0] = 0;
    Seg seg(n + 1);
    seg.update(n, 0);
    RFOR (i, n - 1, 1) {
        if (c[i - 1] == 0) continue;
        ll next = seg.query(i + 1, min(i + m, n));
        ll cost = c[i - 1] + next;
        seg.update(i, cost);
    }

    ll ans = seg.query(1, min(m + 1, n));
    cout << "Case #" << tt << ": " << ans << nl;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);

    int T; cin >> T;
    FOR (tt, 1, T) {
        solve(tt);
    }
    return 0;
}
