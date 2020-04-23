#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using vi = vector<int>;
using vvi = vector<vector<int>>;
using vl = vector<long long>;
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
    vi v(n);
    F0R (i, n) cin >> v[i];
    vvi adj(n);
    F0R (i, n - 1) {
        int a, b; cin >> a >> b;
        adj[a-1].pb(b-1); adj[b-1].pb(a-1);
    }
    vi pos(n), end(n);
    BIT B(n);
    int ord = 0;
    function<void(int, int)> dfs = [&](int u, int p) {
        pos[u] = ord++;
        B.update(pos[u], v[u]);
        for (int x : adj[u]) if (x != p) dfs(x, u);
        end[u] = ord;
    };
    dfs(0, -1);

    while (q--) {
        int type; cin >> type;
        if (type == 1) {
            int s, x; cin >> s >> x;
            int u = pos[s - 1];
            B.update(u, x - B.query(u, u));
        } else {
            int s; cin >> s;
            cout << B.query(pos[s - 1], end[s - 1] - 1) << '\n';
        }
    }

    return 0;
}
