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
        adj[a - 1].pb(b - 1);
    }

    vi color(n, 0);
    int start, end;
    function<bool(int)> Dfs = [&](int u) -> bool {
        color[u] = 1;
        for (int x : adj[u]) {
            if (color[x] == 1) {
                start = x;
                end = u;
                return true;
            } else if (color[x] == 0) {
                if (Dfs(x))
                    return true;
            }
        }
        color[u] = 2;
        return false;
    };

    vi ans;
    function<bool(int)> Dfs2 = [&](int u) {
        for (int x : adj[u]) {
            if (x == end) {
                ans.pb(x);
                ans.pb(u);
                return true;
            }
            if (Dfs2(x)) {
                ans.pb(u);
                return true;
            }
        }
        return false;
    };

    F0R (i, n) {
        if (color[i] == 0 && Dfs(i)) {
            ans.pb(start);
            Dfs2(start);
            reverse(all(ans));
            cout << sz(ans) << nl;
            for (int x : ans)
                cout << (x + 1) << " ";
            cout << nl;
            return 0;
        }
    }
    cout << "IMPOSSIBLE\n";

    return 0;
}
