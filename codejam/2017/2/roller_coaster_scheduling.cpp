#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using vi = vector<int>;
using vb = vector<bool>;
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

#define FOR(i, a, b) for (int i = (a); i <= (b); ++i)
#define F0R(i, a) for (int i = 0; i < (a); ++i)
#define RFOR(i, a, b) for (int i = (a); i >= (b); --i)

const char nl = '\n';
const ll MOD = 1e9 + 7;
const ll INF = 1e18;

void solve() {
    int n, c, m; cin >> n >> c >> m;
    vi p(m), b(m);
    F0R (i, m) {
        cin >> p[i] >> b[i];
        p[i]--; b[i]--;
    }
    vvi posi(n);
    F0R (i, m) {
        posi[p[i]].pb(b[i]);
    }

    auto Calc = [&](int rides) -> int {
        vi av(c, rides);
        queue<int> q;
        int promoted = 0;
        RFOR (i, n - 1, 0) {
            int tickets = rides;
            F0R (j, sz(posi[i])) {
                int cust = posi[i][j];
                if (av[cust] > 0 && tickets > 0) {
                    av[cust]--;
                    tickets--;
                } else {
                    q.push(cust);
                }
            }
            while (tickets > 0 && !q.empty()) {
                int cust = q.front(); q.pop();
                if (av[cust] == 0) return -1;
                av[cust]--;
                tickets--;
                promoted++;
            }
        }
        if (sz(q)) return -1;
        return promoted;
    };

    int lo = 1, hi = m;
    while (lo < hi) {
        int mi = lo + (hi - lo) / 2;
        if (Calc(mi) != -1) {
            hi = mi;
        } else {
            lo = mi + 1;
        }
    }

    cout << lo << " " << Calc(lo) << endl;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);

    int T; cin >> T;
    FOR (t, 1, T) {
        cout << "Case #" << t << ": ";
        solve();
    }

    return 0;
}
