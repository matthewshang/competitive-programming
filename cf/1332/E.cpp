#include "bits/stdc++.h"

using namespace std;
using ll = long long;

void pr(int x) { cout << x; }
void pr(ll x) { cout << x; }
void pr(size_t x) { cout << x; }
void pr(const char* s) { cout << s; }
void pr(string& s) { cout << s; }
void pr(bool x) { cout << (x ? "true" : "false"); }

template <typename T1, typename T2>
void pr(const pair<T1, T2>& p) {
    pr("{ "); pr(p.first); pr(", "); pr(p.second); pr(" }");
}

template <typename T> 
void pr(T& v) {
    cout << "{";
    bool f = true; for (const auto& x : v) cout << (!f ? ", " : ""), f = false, pr(x);
    cout << "}";
}

void pd() { cout << "]" << endl; }

template <typename T, typename... U>
void pd(T first, U... rest) {
    pr(first); if (sizeof...(rest)) cout << ", "; pd(rest...);
}

#ifdef TESTING
#define dbg(x...) cout << "[" << #x << "] = [", pd(x)
#else
#define dbg(...)
#endif

const ll MOD = 998244353;

ll power(ll a, ll b) {
    ll x = 1, y = a;
    while (b > 0) {
        if (b % 2) x = (x * y) % MOD;
        y = (y * y) % MOD;
        b /= 2;
    }
    return (x % MOD);
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    ll n, m, L, R; cin >> n >> m >> L >> R;
    ll e = R / 2 - (L - 1) / 2;
    ll o = (R + 1) / 2 - L / 2;
    e %= MOD; o %= MOD;
    dbg(e, o);

    if (n * m % 2) {
        cout << power(e + o, n * m) << endl;
        return 0;
    }

    ll ans = power(e + o, n * m);
    ans = (ans + power(e - o, n * m)) % MOD;
    ans = (ans * power(2, MOD - 2)) % MOD;
    cout << ans << endl;

    return 0;
}
