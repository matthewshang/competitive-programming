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

    int n; cin >> n;
    vector<int> x(n);
    for (int i = 0; i < n; i++) {
        cin >> x[i];
    }

    vector<vector<ll>> dp(n, vector<ll>(n));
    vector<vector<int>> take(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        dp[i][i] = x[i];
        take[i][i] = i;
    }
    for (int i = 0; i < n - 1; i++) {
        dp[i][i + 1] = max(x[i], x[i + 1]);
        take[i][i + 1] = x[i] > x[i + 1] ? i : i + 1;
    }
    for (int l = 2; l < n; l++) {
        for (int i = 0; i < n - l; i++) {
            ll tl = 0;
            {
                // take x[i]
                int L = (take[i + 1][i + l] == i + 1) ? i + 2 : i + 1;
                int R = (take[i + 1][i + l] == i + l) ? i + l - 1 : i + l;
                tl = x[i] + dp[L][R];
            }
            ll tr = 0;
            {
                // take x[i + l]
                int L = (take[i][i + l - 1] == i) ? i + 1 : i;
                int R = (take[i][i + l - 1] == i + l - 1) ? i + l - 2 : i + l - 1;
                tr = x[i + l] + dp[L][R];
            }
            dp[i][i + l] = max(tl, tr);
            take[i][i + l] = tl > tr ? i : i + l;
        }
    }
    cout << dp[0][n - 1] << nl;

    return 0;
}
