// Range Sum Queries II

#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using vi = vector<int>;
using pii = pair<int, int>;
using vpi = vector<pair<int, int>>;

#define f first
#define s second
#define pb push_back
#define mp make_pair
#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()

#define FOR(i, a, b) for (int i=(a); i <(b); i++)
#define F0R(i, a) for (int i=0; i < (a); i++)
#define RFOR(i, a, b) for (int i = (a); i >= b; i--)

// Source: KACTL
struct BIT { // Operation must be reversible
    vector<ll> bit;
    BIT(int n) : bit(n) {}
    ll query(int pos) { // pos in [0, n)
        ll ans = 0;
        for (; pos > 0; pos &= pos - 1) ans += bit[pos - 1];
        return ans;
    }
    ll query(int l, int r) { // [l, r]
        return query(r + 1) - query(l);
    }
    void update(int pos, int delta) { // pos in [0, n); 
        for (; pos < sz(bit); pos |= pos + 1) bit[pos] += delta;
    }
};

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    int n, q; cin >> n >> q;
    BIT B(n + 1);
    F0R (i, n) {
        int x; cin >> x;
        B.update(i + 1, x);
    }

    F0R (i, q) {
        int t, x, y; cin >> t >> x >> y;
        if (t == 1) {
            B.update(x, y - B.query(x, x));
        } else {
            cout << B.query(x, y) << endl;
        }
    }

    return 0;
}
