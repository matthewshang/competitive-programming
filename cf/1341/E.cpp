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
// const ll INF = 1e18;
const int INF = 2e9;

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);

    int n, m; cin >> n >> m;
    vi d(m);
    F0R (i, m) cin >> d[i];
    sort(all(d));
    int g, r; cin >> g >> r;
    vector<vpi> adj(m);
    FOR (i, 1, m - 1) {
        if (d[i] - d[i - 1] <= g) {
            adj[i].pb({d[i] - d[i - 1], i - 1});
            adj[i - 1].pb({d[i] - d[i - 1], i});
        }
    }

    deque<pii> q;
    vvi dist(m, vi(g, INF));
    q.push_front({0, 0});
    dist[0][0] = 0;
    while (!q.empty()) {
        auto [idx, used] = q.front(); q.pop_front();

        for (auto [cost, p] : adj[idx]) {
            if (used + cost > g) continue;
            int e = used + cost;
            if (e == g) {
                if (dist[p][0] > dist[idx][used] + 1) {
                    dist[p][0] = dist[idx][used] + 1;
                    q.push_back({p, 0});
                }
            } else {
                if (dist[p][e] > dist[idx][used]) {
                    dist[p][e] = dist[idx][used];
                    q.push_front({p, e});
                }
            }
        }
    }
    ll ans = 2e18;
    F0R (i, g) {
        if (dist[m - 1][i] == INF) continue;
        ll val = (ll)(r + g) * dist[m - 1][i] + i;
        if (i == 0)
            val -= r;
        ans = min(ans, val);
    }
    cout << (ans == 2e18 ? -1 : ans) << endl;
    return 0;
}