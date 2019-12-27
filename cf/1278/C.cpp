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
    int n; cin >> n;
    vector<int> a(2 * n);
    for (int& x : a) {
        cin >> x;
        x = (x == 1) ? -1 : 1;
    }

    vector<int> l(n + 1), r(n + 1);
    int val = 0;
    for (int i = 0; i < 2 * n; i++)
        val += a[i];
    l[0] = r[0] = 0;
    for (int i = 0; i < n; i++) {
        l[i + 1] = l[i] + a[n - i - 1];
        r[i + 1] = r[i] + a[n + i];
    }

    map<int, int> idx;
    for (int i = 0; i <= n; i++) {
        int x = val - l[i];
        if (idx.find(x) == idx.end()) {
            idx[x] = i;
        } else {
            idx[x] = min(idx[x], i);
        }
    }

    int ans = 2 * n;
    for (int i = 0; i <= n; i++) {
        if (idx.find(r[i]) != idx.end()) {
            ans = min(ans, i + idx[r[i]]);
        }
    }
    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    int t; cin >> t;
    while (t--)
        solve();

    return 0;
}
