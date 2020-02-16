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

const ll MD = 998244353;

ll power(ll a, ll b) {
    ll x = 1, y = a;
    while (b > 0) {
        if (b % 2) x = (x * y) % MD;
        y = (y * y) % MD;
        b /= 2;
    }
    return x % MD;
}

ll inv(ll n) {
    return power(n, MD - 2);
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    int n; cin >> n;
    vector<int> k(n);
    vector<int> a[n];
    map<int, int> c;
    for (int i = 0; i < n; i++) {
        cin >> k[i];
        for (int j = 0; j < k[i]; j++) {
            int x; cin >> x;
            a[i].push_back(x);
            c[x]++;
        }
    }

    ll ans = 0;
    for (int i = 0; i < n; i++) {
        ll p = 0;
        for (int j = 0; j < a[i].size(); j++) {
            p += c[a[i][j]] - 1;
        }
        p = (p * inv(k[i])) % MD;
        ans = (ans + p) % MD;
    }
    ans = (ans * inv(n)) % MD;
    ans = (ans * inv(n)) % MD;
    ans = (ans + inv(n)) % MD;
    cout << ans << endl;

    return 0;
}
