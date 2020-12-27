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


int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);

    const ll MOD = 1e9 + 7;
    using mat = array<array<ll, 6>, 6>;

    auto mul = [&](mat a, mat b) -> mat {
        mat c{};
        for (int i = 0; i < sz(a); i++) {
            for (int j = 0; j < sz(a); j++) {
                for (int k = 0; k < sz(a); k++) {
                    c[i][j] = (c[i][j] + a[i][k] * b[k][j] % MOD) % MOD;
                }
            }
        }
        return c;
    };
    auto binpow = [&](mat a, ll k) -> mat {
        mat x{};
        for (int i = 0; i < sz(x); i++) {
            x[i][i] = 1;
        }
        while (k) {
            if (k % 2) x = mul(x, a); 
            a = mul(a, a);
            k /= 2;
        }
        return x;
    };

    ll n; cin >> n;
    array<int, 6> v = {{ 32, 16, 8, 4, 2, 1 }};
    if (n <= 6) {
        cout << v[6 - n] << nl;
    } else {
        mat m{};
        for (int i = 0; i < 6; i++) {
            m[0][i] = 1;
        }
        for (int i = 0; i < 5; i++) {
            m[i + 1][i] = 1;
        }
        m = binpow(m, n - 6);

        ll res = 0;
        for (int i = 0; i < 6; i++) {
            res = (res + m[0][i] * v[i] % MOD) % MOD;
        }
        cout << res << nl;
    }

    return 0;
}
