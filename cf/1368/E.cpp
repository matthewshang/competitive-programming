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

void solve() {
    int n, m; cin >> n >> m;
    vvi adj(n);
    vi in(n, 0);
    F0R (i, m) {
        int x, y; cin >> x >> y;
        x--; y--;
        if (sz(adj[x]) && adj[x][0] == y)
            continue;
        adj[x].pb(y);
        in[y]++;
    }

    vi topo;
    {
        stack<int> s;
        F0R (i, n) if (in[i] == 0)
            s.push(i);
        while (!s.empty()) {
            int x = s.top(); s.pop();
            topo.pb(x);
            for (int next : adj[x]) {
                in[next]--;
                if (in[next] == 0)
                    s.push(next);
            }
        }
    }

    vi rem;
    vi depth(n, 0);
    F0R (i, n) {
        int u = topo[i];
        if (depth[u] == 2) {
            rem.pb(u);
        } else {
            for (int x : adj[u])
                depth[x] = max(depth[x], depth[u] + 1);
        }
    }

    cout << sz(rem) << nl;
    for (int x : rem)
        cout << (x + 1) << " ";
    cout << nl;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);

    int t; cin >> t;
    while (t--) solve();

    return 0;
}
