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

void solve() {
    int n; cin >> n;
    vector<int> a(n); for (int& x : a) cin >> x;
    int U = 0, L = 2e9;
    for (int i = 0; i < n; i++) {
        if (a[i] == -1) {
            if (i > 0 && a[i - 1] != -1) {
                U = max(U, a[i - 1]);
                L = min(L, a[i - 1]);
            }
            if (i < n - 1 && a[i + 1] != -1) {
                U = max(U, a[i + 1]);
                L = min(L, a[i + 1]);
            }
        }
    }
    int k = (U + L) / 2;
    int m = 0;
    for (int i = 0; i < n - 1; i++) {
        int x = (a[i] == -1) ? k : a[i];
        int y = (a[i + 1] == -1) ? k : a[i + 1];
        m = max(m, abs(x - y));
    }
    cout << m << " " << k << endl;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    int t; cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
