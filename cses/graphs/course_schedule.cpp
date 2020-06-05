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
    vi indeg(n, 0);
    F0R (i, m) {
        int a, b; cin >> a >> b;
        adj[a - 1].pb(b - 1);
        indeg[b - 1]++;
    }

    queue<int> q;
    vi ans;
    F0R (i, n) {
        if (indeg[i] == 0)
            q.push(i);
    }

    while (!q.empty()) {
        int u = q.front(); q.pop();
        ans.pb(u);
        for (int x : adj[u]) {
            indeg[x]--;
            if (indeg[x] == 0)
                q.push(x);
        }
    }

    if (sz(ans) != n) {
        cout << "IMPOSSIBLE" << nl;
    } else {
        F0R (i, n)
            cout << (ans[i] + 1) << " ";
        cout << nl;
    }
    return 0;
}
