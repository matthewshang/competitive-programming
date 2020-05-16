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

    int n, m; cin >> n >> m;
    vector<array<int, 3>> edges(m);
    F0R (i, m) {
        int a, b, c; cin >> a >> b >> c;
        edges[i] = {a, b, c};
    }

    vll dist(n + 1, 0);
    vi prev(n + 1, -1);
    int changed = -1;
    F0R (i, n) {
        changed = -1;
        for (auto [u, v, w] : edges) {
            if (dist[u] != INF && dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                prev[v] = u;
                changed = u;
            }
        }
    }

    if (changed == -1) {
        cout << "NO\n";
    } else {
        set<int> seen;
        int cur = changed;
        while (seen.find(cur) == seen.end()) {
            seen.insert(cur);
            cur = prev[cur];
        }
        vi ans = {cur};
        cur = prev[cur];
        while (cur != ans[0]) {
            ans.pb(cur);
            cur = prev[cur];
        }
        ans.pb(ans[0]);
        cout << "YES\n";
        RFOR (i, sz(ans) - 1, 0) cout << ans[i] << " ";
        cout << endl;
    }

    return 0;
}