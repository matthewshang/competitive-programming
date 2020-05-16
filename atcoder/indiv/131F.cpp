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

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);

    int n; cin >> n;
    vpi dot(n);
    F0R (i, n) cin >> dot[i].F >> dot[i].S;
    sort(all(dot));
    ll ans = 0;
    int last_x = 0;
    vll count(1e5 + 1, 0);
    vi tmp;
    F0R (i, n) {
        if (dot[i].F != last_x) {
            F0R (j, sz(tmp)) {
                count[tmp[j]] += j;
            }
            tmp.clear();
        }
        tmp.pb(dot[i].S);
        last_x = dot[i].F;
        ans += count[dot[i].S];
    }
    cout << ans << endl;
    return 0;
}
