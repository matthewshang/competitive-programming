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

struct Seg {
    int n;
    vector<ll> seg;
    Seg(int n) : n(n), seg(4 * n) {}
    void update(int pos, ll val, int idx, int L, int R) {
        if (L == R) {
            seg[idx] = max(seg[idx], val);
        } else {
            int M = (L + R) / 2;
            if (pos <= M)
                update(pos, val, idx * 2, L, M);
            else
                update(pos, val, idx * 2 + 1, M + 1, R);
            seg[idx] = max(seg[idx * 2], seg[idx * 2 + 1]);
        }
    }
    void update(int pos, ll val) {
        update(pos, val, 1, 0, n - 1);
    }
    ll query(int lo, int hi, int idx, int L, int R) {
        if (lo > hi) return 0;
        if (L == lo && hi == R) return seg[idx];
        int M = (L + R) / 2;
        return max(query(lo, min(hi, M), idx * 2, L, M), 
               query(max(lo, M + 1), hi, idx * 2 + 1, M + 1, R));
    }
    ll query(int lo, int hi) {
        return query(lo, hi, 1, 0, n - 1);
    }
};

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);

    int n; cin >> n;
    vector<int> a(n);
    vector<int> b(n);
    vector<int> p(n);
    vector<int> cmpr;
    for (int i = 0; i < n; i++) {
        cin >> a[i] >> b[i] >> p[i];
        cmpr.push_back(a[i]);
        cmpr.push_back(b[i]);
    }
    sort(all(cmpr));
    cmpr.resize(unique(all(cmpr)) - cmpr.begin());
    for (int i = 0; i < n; i++) {
        a[i] = lower_bound(all(cmpr), a[i]) - cmpr.begin() + 1;
        b[i] = lower_bound(all(cmpr), b[i]) - cmpr.begin() + 1;
    }

    vector<pii> ord(n);
    for (int i = 0; i < n; i++) {
        ord[i] = { b[i], i };
    }
    sort(all(ord));

    int X = cmpr.size();
    Seg dp(X + 1);
    for (int i = 0; i < n; i++) {
        int j = ord[i].second;
        dp.update(b[j], dp.query(0, a[j] - 1) + p[j]);
    }
    cout << dp.query(0, X) << nl;

    return 0;
}
