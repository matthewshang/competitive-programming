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

    int T; cin >> T;
    FOR (tt, 1, T) {
        int n; cin >> n;
        string in, out; cin >> in >> out;

        vvi adj(n);
        F0R (i, n - 1) {
            if (out[i] == 'Y' && in[i + 1] == 'Y') {
                adj[i].pb(i + 1);
            }
            if (in[i] == 'Y' && out[i + 1] == 'Y') {
                adj[i + 1].pb(i);
            }
        }

        vector<string> P(n);
        F0R (i, n) {
            F0R (j, n) P[i] += 'N';
            P[i][i] = 'Y';
        }

        auto bfs = [&](int source) {
            vb vis(n, false);
            queue<int> q({source});
            while (sz(q)) {
                int cur = q.front(); q.pop();
                if (vis[cur]) continue;
                vis[cur] = true;
                P[source][cur] = 'Y';
                for (int to : adj[cur]) q.push(to);
            }
        };
        F0R (i, n) bfs(i);

        cout << "Case #" << tt << ":" << nl;
        F0R (i, n) {
            cout << P[i] << nl;
        }
    }
    return 0;
}
