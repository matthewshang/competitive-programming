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

bool solve() {
    int n, m; cin >> n >> m;
    vector<pair<int, pair<int, int>>> c(n);
    for (int i = 0; i < n; i++) {
        cin >> c[i].first >> c[i].second.first >> c[i].second.second;
    }

    int lo = m, hi = m;
    int t = 0;
    for (int i = 0; i < n; i++) {
        auto [nt, r] = c[i];
        hi += nt - t;
        lo -= nt - t;
        if (lo > r.second || hi < r.first)
            return false;
        hi = min(hi, r.second);
        lo = max(lo, r.first);
        t = nt;
    }
    return true;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    int q; cin >> q;
    while (q--) {
        cout << (solve() ? "YES" : "NO") << endl;
    }

    return 0;
}
