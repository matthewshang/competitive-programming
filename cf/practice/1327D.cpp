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
    while (T--) {
        int n; cin >> n;
        vi p(n + 1), c(n + 1);
        F0R (i, n) cin >> p[i + 1];
        F0R (i, n) cin >> c[i + 1];

        int ans = 1e9;
        vb vis(n + 1, false);
        FOR (i, 1, n) {
            if (vis[i]) continue;
            if (i == p[i]) {
                ans = 1;
                break;
            }
            vi cyc = { i, p[i] };
            while (p[cyc.back()] != i) {
                cyc.pb(p[cyc.back()]);
            }
            for (int x : cyc)
                vis[x] = true;

            auto Try = [&](vi& v, int d) -> bool {
                F0R (j, d) {
                    bool ok = true;
                    int base = c[v[j]];
                    int k = j + d;
                    while (k < sz(v)) {
                        if (c[v[k]] != base) {
                            ok = false;
                            break;
                        }
                        k += d;
                    }
                    if (ok)
                        return true;
                }
                return false;
            };

            for (int D = 1; D <= sqrt(sz(cyc)); D++) {
                if (sz(cyc) % D != 0) continue;
                if (Try(cyc, D)) {
                    ans = min(ans, D);
                } else if (Try(cyc, sz(cyc) / D)) {
                    ans = min(ans, sz(cyc) / D);
                }
            }
        }

        cout << ans << nl;
    }
    return 0;
}
