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

    ll N; cin >> N;
    map<ll, ll> store;
    function<ll(ll)> F = [&](ll n) -> ll {
        if (n <= 1)
            return n;
        else if (n == 2)
            return 1;
        else if (n == 3)
            return 2;

        if (auto it = store.find(n); it != store.end())
            return it->second;

        ll val;
        if (n % 2) {
            ll P = F(n - 1);
            ll Q = F(n - 3);
            ll R = (P - Q + MOD) % MOD;
            val = (P + R) % MOD;
        } else {
            ll A = F(n / 2 + 1);
            ll B = F(n / 2 - 1);
            val = (A * A % MOD - B * B % MOD + MOD) % MOD;
        }
        store[n] = val;
        return val;
    };
    cout << F(N) << endl;
    return 0;
}
