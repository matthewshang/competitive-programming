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

    int n; cin >> n;
    vi x(n), y(n);
    F0R (i, n) cin >> x[i] >> y[i];
    ll ans = (ll)n * (n - 1) * (n - 2) / 6;
    ll rem = 0;
    map<pii, int> dir;
    F0R (i, n) {
        dir.clear();
        F0R (j, n) {
            if (i == j) continue;
            int dx = x[j] - x[i];
            int dy = y[j] - y[i];
            int g = abs(__gcd(dx, dy));
            dir[{dx / g, dy / g}] += 1;
            dir[{-dx / g, -dy / g}] += 1;
        }
        for (auto p : dir) {
            rem += ((ll)p.S * (p.S - 1)) / 2;
        }
    }
    ans -= rem / 6;
    cout << ans << endl;

    return 0;
}