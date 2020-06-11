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

    int n, m; cin >> n >> m;
    vvi adj(n);
    F0R (i, m) {
        int a, b; cin >> a >> b;
        a--; b--;
        adj[a].pb(b);
        adj[b].pb(a);
    }

    vi t(n);
    F0R (i, n)
        cin >> t[i];

    vpi chk(n);
    F0R (i, n)
        chk[i] = { t[i], i };
    sort(all(chk));

    vb vis(n, false);
    vb has(n);
    F0R (i, n) {
        int u = chk[i].S;
        vis[u] = true;
        if (sz(adj[u]) < t[u] - 1) {
            cout << -1 << nl;
            return 0;
        }
        fill(has.begin(), has.begin() + t[u], false);
        for (int x : adj[u]) {
            if (vis[x])
                has[t[x] - 1] = true;
        }
        bool ok = !has[t[u] - 1];
        if (ok) {
            F0R (i, t[u] - 1) {
                if (!has[i]) {
                    ok = false;
                    break;
                }
            }
        }
        if (!ok) {
            cout << -1 << nl;
            return 0;
        }
    }

    F0R (i, n)
        cout << (chk[i].S + 1) << " ";
    cout << nl;

    return 0;
}
