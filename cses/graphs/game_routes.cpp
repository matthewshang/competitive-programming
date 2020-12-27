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
    vvi adj(n + 1);
    vi in(n + 1, 0);
    F0R (i, m) {
        int a, b; cin >> a >> b;
        adj[a].pb(b);
        in[b]++;
    }

    vi topo;
    {
        stack<int> s;
        FOR (i, 1, n) if (in[i] == 0) s.push(i);
        while (sz(s)) {
            int v = s.top(); s.pop();
            topo.pb(v);
            for (int to : adj[v]) {
                in[to]--;
                if (in[to] == 0) s.push(to);
            }
        }
    }

    vll dp(n + 1, 0);
    dp[1] = 1;
    F0R (i, n) {
        int v = topo[i];
        for (int to : adj[v]) {
            dp[to] = (dp[to] + dp[v]) % MOD;
        }
    }

    cout << dp[n] << nl;

    return 0;
}

