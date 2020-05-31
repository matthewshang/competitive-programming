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

const ll INV2 = 500000004;

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);

    ll n; cin >> n;
    ll s = (ll)floor(sqrt(n));
    ll ans = 0;
    FOR (i, 1, s - 1) {
        ll a = n / (ll)i;
        ll b = n / (ll)(i + 1) + 1;
        ll add = (a + b) % MOD;
        add = add * i % MOD * ((a - b + 1) % MOD) % MOD;
        add = add * INV2 % MOD;
        ans = (ans + add) % MOD;
    }
    FOR (i, 1, n / s) {
        ans = (ans + ((n / (ll)i) * i % MOD)) % MOD;
    }
    cout << ans << endl;
    return 0;
}
