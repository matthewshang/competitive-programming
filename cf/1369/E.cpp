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
    vi w(n + 1);
    F0R (i, n) cin >> w[i + 1];
    vpi fav(m);
    vi so_far(n + 1);
    F0R (i, m) {
        cin >> fav[i].F >> fav[i].S;
        so_far[fav[i].F]++;
        so_far[fav[i].S]++;
    }

    vector<vpi> has(n + 1);
    F0R (i, m) {
        has[fav[i].F].pb({ fav[i].S, i });
        has[fav[i].S].pb({ fav[i].F, i });
    }

    queue<int> q;
    vb used_fr(m, false);
    vb used_fo(n + 1, false);
    vi ord;
    FOR (i, 1, n) if (so_far[i] <= w[i]) q.push(i);
    while (sz(q)) {
        int f = q.front(); q.pop();
        if (used_fo[f]) continue;
        used_fo[f] = true;

        for (auto [other, idx] : has[f]) if (!used_fr[idx]) {
            ord.pb(idx + 1);
            used_fr[idx] = true;
            so_far[other]--;
            if (so_far[other] <= w[other] && !used_fo[other]) {
                q.push(other);
            }
        }
    }
    reverse(all(ord));

    if (sz(ord) == m) {
        cout << "ALIVE" << nl;
        for (int fr : ord)
            cout << fr << " ";
        cout << nl;
    } else {
        cout << "DEAD" << nl;
    }

    return 0;
}
