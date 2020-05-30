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
// const ll INF = 1e18;
const int INF = 2e9;

const int MAXA = 200002;

ll power(ll a, ll b) {
    ll x = 1, y = a;
    while (b > 0) {
        if (b % 2) x *= y;
        y *= y;
        b /= 2;
    }
    return x;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);

    int n; cin >> n;
    vi a(n); 
    F0R (i, n) cin >> a[i];

    vi spf(MAXA);
    spf[1] = 1;
    for (int i = 2; i < MAXA; i++)
        spf[i] = i;
    for (int i = 4; i < MAXA; i += 2)
        spf[i] = 2;
    for (int i = 3; i * i < MAXA; i++) {
        if (spf[i] == i) {
            for (int j = i * i; j < MAXA; j += i) {
                if (spf[j] == j)
                    spf[j] = i;
            }
        }
    }

    vpi low(MAXA, { INF, INF });
    vi pres(MAXA, 0);
    F0R (i, n) {
        int x = a[i];
        map<int, int> count;
        while (x != 1) {
            count[spf[x]]++;
            x = x / spf[x];
        }
        for (auto [p, e] : count) {
            if (e < low[p].F) {
                low[p].S = low[p].F;
                low[p].F = e;
            } else if (e < low[p].S) {
                low[p].S = e;
            }
            pres[p]++;
        }
    }

    ll ans = 1;
    F0R (i, MAXA) {
        if (pres[i] == n) {
            ans *= power(i, low[i].S);
        } else if (pres[i] == n - 1) {
            ans *= power(i, low[i].F);
        }
    }
    cout << ans << endl;

    return 0;
}
