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

// Source: Based on KACTL and bqi343
template <typename T>
struct Seg {
    const T ID = 0;
    T f(T a, T b) { return a + b; } // f should be associative
    vector<T> seg; int n;
    Seg(int _n) { 
        n = _n; seg.assign(2 * n, ID); 
    }
    void update(int pos, T val) {
        seg[pos += n] = val;
        int d = 1;
        for (pos /= 2; pos; pos /= 2) {
            if (d % 2) seg[pos] = seg[2 * pos] | seg[2 * pos + 1];
            else seg[pos] = seg[2 * pos] ^ seg[2 * pos + 1];
            d++;
        }
    }
    T query(int l, int r) { // interval [l, r]
        T ra = ID, rb = ID;
        int d = 1;
        for (l += n, r += n + 1; l < r; l /= 2, r /= 2) {
            if (l & 1) ra = d % 2 ? ra | seg[l++] : ra ^ seg[l++];
            if (r & 1) rb = d % 2 ? seg[--r] | rb : seg[--r] ^ rb;
            d++;
        }
        return d % 2 ? ra | rb : ra ^ rb;
    }
};

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int depth, m; cin >> depth >> m;
    int n = 1 << depth;
    Seg<int> S(n);
    for (int i = 0; i < n; i++) {
        int a; cin >> a;
        S.update(i, a);
    }

    for (int i = 0; i < m; i++) {
        int p, b; cin >> p >> b;
        S.update(p - 1, b);
        cout << S.query(0, n - 1) << endl;
    }
    return 0;
}
