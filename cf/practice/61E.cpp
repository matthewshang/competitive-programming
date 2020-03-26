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

template <typename T>
struct Seg {
    const T ID = 0; T f(T a, T b) { return a + b; };
    vector<int> seg; int n;
    Seg(int _n) { n = _n; seg.assign(2 * n, ID); }
    void update(int pos, T val) {
        seg[pos += n] = val;
        for (pos /= 2; pos; pos /= 2) 
            seg[pos] = f(seg[2 * pos], seg[2 * pos + 1]);
    }
    T query(int l, int r) {
        int ra = ID, rb = ID;
        for (l += n, r += n + 1; l < r; l /= 2, r /= 2) {
            if (l & 1) ra = f(ra, seg[l++]);
            if (r & 1) rb = f(seg[--r], rb);
        }
        return f(ra, rb);
    }
};

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    int n; cin >> n;
    vector<pair<int, int>> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i].first;
        a[i].second = i;
    }
    sort(a.begin(), a.end());
    vector<int> b(n);
    for (int i = 0; i < n; i++)
        b[a[i].second] = i;

    vector<int> lo(n), hi(n);
    Seg<int> L(n), R(n);
    for (int i = 0; i < n; i++) {
        lo[i] = L.query(b[i], n - 1);
        L.update(b[i], 1);
        hi[n - i - 1] = R.query(0, b[n - i - 1] - 1);
        R.update(b[n - i - 1], 1);
    }

    ll ans = 0;
    for (int i = 1; i < n - 1; i++) {
        ans += (ll)lo[i] * hi[i];
    }
    cout << ans << endl;

    return 0;
}
