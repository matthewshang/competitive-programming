#include "bits/stdc++.h"
using namespace std;

using ll = long long;
using vi = vector<int>;
using vb = vector<bool>;
using vvi = vector<vector<int>>;
using vll = vector<long long>;
using vpi = vector<pair<int, int>>;
using pii = pair<int, int>;

#define F first
#define S second
#define pb push_back
#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define F0R(i, a) for (int i = 0; i < (a); ++i)
#define RFOR(i, a, b) for (int i = (a); i >= (b); --i)
#define trav(a, x) for (auto& a: x)

const char nl = '\n';

string to_string(char c) { 
    return string(1, c); 
}
string to_string(const char* s) { 
    return (string)s; 
}
string to_string(string s) { 
    return s; 
}
string to_string(bool b) { 
    return b ? "true" : "false"; 
}
string to_string(vector<bool> v) { 
    string res = "{"; 
    F0R (i, sz(v)) res += char('0' + v[i]); 
    res += "}"; return res; 
}
template <size_t SZ> string to_string(bitset<SZ> b) { 
    string res = ""; F0R (i, SZ) res += char('0' + b[i]); 
    return res; 
}
template<class A, class B> string to_string(pair<A, B> p);
template<class T> string to_string(T& v) {
    bool fst = 1; string res = "{";
    for (const auto& x: v) {
        if (!fst) res += ", ";
        fst = 0; res += to_string(x);
    }
    res += "}"; return res;
}
template<class A, class B> string to_string(pair<A, B> p) { 
    return "(" + to_string(p.F) + ", " + to_string(p.S) + ")"; 
}

void DBG() { cerr << "]" << endl; }
template<class H, class... T> void DBG(H h, T... t) {
	cerr << to_string(h); 
    if (sizeof...(t)) cerr << ", ";
	DBG(t...); 
}
#ifdef LOCAL
	#define dbg(...) cerr << "LINE(" << __LINE__ << ") -> [" << #__VA_ARGS__ << "]: [", DBG(__VA_ARGS__)
#else
	#define dbg(...) 0
#endif

struct lazy_seg {
    int n;
    vector<ll> seg, lazy;
    lazy_seg(int n) : n(n), seg(4 * n), lazy(4 * n) {}
    void push(int v, int l, int r) {
        // seg[v] += (r - l + 1) * lazy[v];
        seg[v] += lazy[v];
        if (l != r) F0R (i, 2) {
            lazy[v * 2 + i] += lazy[v];
        }
        lazy[v] = 0;
    }
    void range_update(int lo, int hi, int inc, int v, int l, int r) {
        push(v, l, r);
        if (hi < l || lo > r) return;
        if (lo <= l && r <= hi) {
            lazy[v] += inc;
            push(v, l, r);
        } else {
            int m = (l + r) / 2;
            range_update(lo, hi, inc, v * 2, l, m);
            range_update(lo, hi, inc, v * 2 + 1, m + 1, r);
            seg[v] = min(seg[v * 2], seg[v * 2 + 1]);
        }
    }
    void range_update(int lo, int hi, int inc) {
        range_update(lo, hi, inc, 1, 0, n - 1);
    }
    ll point_query(int pos, int v, int l, int r) {
        push(v, l, r);
        if (l == r) return seg[v];
        int m = (l + r) / 2;
        if (pos <= m)
            return point_query(pos, v * 2, l, m);
        else
            return point_query(pos, v * 2 + 1, m + 1, r);
    }
    ll point_query(int pos) {
        return point_query(pos, 1, 0, n - 1);
    }
};
int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);

    int n, q; cin >> n >> q;
    lazy_seg seg(n);
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        seg.range_update(i, i, x);
    }

    while (q--) {
        int t; cin >> t;
        if (t == 1) {
            int a, b, u; cin >> a >> b >> u;
            seg.range_update(a - 1, b - 1, u);
        } else {
            int k; cin >> k;
            cout << seg.point_query(k - 1) << nl;
        }
    }

    return 0;
}
