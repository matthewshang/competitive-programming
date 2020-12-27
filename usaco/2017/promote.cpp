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

struct BIT { // Operation must be reversible
    vector<ll> bit;
    BIT(int n) : bit(n) {}
    ll query(int pos) { // sum from [0, pos]
        ll ans = 0;
        for (pos++; pos > 0; pos &= pos - 1) ans += bit[pos - 1];
        return ans;
    }
    ll query(int l, int r) { // sum from [l, r]
        return query(r) - query(l - 1);
    }
    void update(int pos, int delta) { // a[pos] += delta; 
        for (; pos < sz(bit); pos |= pos + 1) bit[pos] += delta;
    }
};

void setIO(string s) {
    freopen((s + ".in").c_str(), "r", stdin);
    freopen((s + ".out").c_str(), "w", stdout);
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
#ifndef LOCAL
    setIO("promote");
#endif

    int n; cin >> n;
    vi prof(n);
    F0R (i, n) cin >> prof[i];
    vi u = prof;
    sort(all(u));
    u.resize(unique(all(u)) - u.begin());
    F0R (i, n) {
        prof[i] = lower_bound(all(u), prof[i]) - u.begin();
    }

    vvi adj(n);
    F0R (i, n - 1) {
        int par; cin >> par; par--;
        adj[i + 1].pb(par);
        adj[par].pb(i + 1);
    }

    vpi pro;
    vector<array<int, 4>> queries;
    function<void(int, int)> dfs = [&](int v, int p) {
        int tin = sz(pro);
        pro.pb({ -prof[v], tin });
        trav (to, adj[v]) if (to != p) dfs(to, v);
        int tout = sz(pro) - 1;
        queries.pb({ -prof[v], tin, tout, v });
    };
    dfs(0, -1);
    sort(all(pro));
    sort(all(queries));

    vi res(n);
    BIT B(n);
    int j = 0;
    F0R (i, n) {
        int mx = queries[i][0];
        int L = queries[i][1];
        int R = queries[i][2];
        int v = queries[i][3];
        while (j < n && pro[j].F < mx) {
            B.update(pro[j].S, 1);
            j++;
        }
        res[v] = B.query(L + 1, R);
    }

    trav (ans, res) cout << ans << nl;

    return 0;
}
