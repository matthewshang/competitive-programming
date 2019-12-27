#include "bits/stdc++.h"

using namespace std;
using ll = long long;

void setIO(string s) {
    freopen((s + ".in").c_str(), "r", stdin);
    #ifndef TESTING
    freopen((s + ".out").c_str(), "w", stdout);
    #endif
}

void pr(int x) { cout << x; }
void pr(ll x) { cout << x; }
void pr(size_t x) { cout << x; }
void pr(const char* s) { cout << s; }
void pr(string& s) { cout << s; }

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

void solve() {
    ll a, b; cin >> a >> b;
    if (a == b) {
        cout << 0 << endl;
        return;
    }
    if (a > b) swap(a, b);
    ll n = (ll)ceil((sqrt(8.0 * (b - a)) - 1) / 2);
    while ((a + b + n * (n + 1) / 2) % 2 == 1)
        n++;
    cout << n << endl;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    int t; cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
