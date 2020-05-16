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

// Source: KACTL
struct BIT { // Operation must be reversible
    vector<ll> bit;
    BIT(int n) : bit(n) {}
    ll query(int pos) { // pos in [0, n]
        ll ans = 0;
        for (pos += 1; pos > 0; pos &= pos - 1) ans += bit[pos - 1];
        return ans;
    }
    void update(int pos, int delta) { // pos in [0, n); 
        for (; pos < sz(bit); pos |= pos + 1) bit[pos] += delta;
    }
    void range_add(int l, int r, int delta) {
        update(l, delta);
        update(r + 1, -delta);
    }
};

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);

    int n, m; cin >> n >> m;
    vi a(n);
    F0R (i, n) cin >> a[i];

    ll need = 0;
    BIT count(m + 1), over(m + 1), start(m + 1);
    FOR (i, 1, n - 1) {
        if (a[i] > a[i - 1]) {
            start.range_add(a[i - 1] + 1, a[i], a[i - 1]);
            count.range_add(a[i - 1] + 1, a[i], 1);
        } else {
            start.range_add(a[i - 1] + 1, m, a[i - 1]);
            start.range_add(1, a[i], a[i - 1]);
            count.range_add(a[i - 1] + 1, m, 1);
            count.range_add(1, a[i], 1);
            over.range_add(1, a[i], 1);
        }
        need += (a[i] - a[i - 1] + m) % m;
    }

    ll best = 0;
    FOR (i, 1, m) {
        ll val = (i - 1) * count.query(i) + m * over.query(i) - start.query(i);
        best = max(best, val);
    }
    cout << (need - best) << endl;

    return 0;
}
