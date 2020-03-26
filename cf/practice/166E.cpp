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

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    const ll MOD = 1e9 + 7;

    auto add = [&](ll x, ll y) -> ll {
        return (x + y) % MOD;
    };

    auto sub = [&](ll x, ll y) -> ll {
        ll ans = (x - y) % MOD;
        if (ans < 0) ans += MOD;
        return ans;
    };

    int n; cin >> n;
    ll a[4] = {0, 0, 0, 1};

    for (int i = 0; i < n; i++) {
        ll sum = add(add(a[0], a[1]), add(a[2], a[3]));
        for (int j = 0; j < 4; j++)
            a[j] = sub(sum, a[j]);
    }
    cout << a[3] << endl;

    return 0;
}
