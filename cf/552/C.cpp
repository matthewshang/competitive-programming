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
    ll w, m; cin >> w >> m;
    vll dig;
    ll p = 1;
    vll pre({1});
    while (p * w <= m) {
        p *= w;
        pre.pb(p);
    }
    pre.pb(p * w);

    ll m_ = m;
    while (p > 0) {
        ll d = m_ / p;
        dig.pb(d);
        m_ = m_ - d * p;
        p /= w;
    }
    reverse(all(dig));
    dig.pb(0);
    bool ok = true;
    F0R (i, sz(dig) - 1) {
        if (dig[i] == 0 || dig[i] == 1) continue;
        ll need = pre[i + 1] - dig[i] * pre[i];
        bool found = false;
        F0R (j, sz(pre)) {
            if (need == pre[j]) {
                found = true;
                break;
            }
        }
        if (found) {
            dig[i + 1] += 1;
            int j = i + 1;
            while (dig[j] == w) {
                dig[j] = 0;
                dig[j + 1] += 1;
                j++;
            }
        } else {
            ok = false;
            break;
        }
    }
    cout << (ok ? "YES" : "NO") << endl;
    return 0;
}