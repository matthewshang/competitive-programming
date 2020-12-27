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

const long long MOD = 1e9 + 7;

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);

    int n, m; cin >> n >> m;
    vector<int> x(n + 1);
    for (int i = 0; i < n; i++) {
        cin >> x[i + 1];
    }

    int know = -1;
    for (int i = 1; i <= n; i++) {
        if (x[i] != 0) {
            know = i;
            break;
        }
    }

    vector<vector<long long>> dp(n + 2, vector<long long>(m + 2));
    if (know == -1) {
        for (int i = 1; i <= m; i++) {
            dp[1][i] = 1;
        }
        know = 1;
    } else {
        dp[know][x[know]] = 1;
    }

    for (int i = know; i < n; i++) {
        if (x[i + 1] == 0) {
            for (int j = 1; j <= m; j++) {
                dp[i + 1][j] = dp[i][j - 1] + dp[i][j] + dp[i][j + 1];
                dp[i + 1][j] %= MOD;
            }
        } else {
            for (int j = -1; j <= 1; j++) {
                dp[i + 1][x[i + 1]] += dp[i][x[i + 1] + j];
            }
            dp[i + 1][x[i + 1]] %= MOD;
        }
    }
    for (int i = know; i >= 1; i--) {
        if (x[i - 1] == 0) {
            for (int j = 1; j <= m; j++) {
                dp[i - 1][j] = dp[i][j - 1] + dp[i][j] + dp[i][j + 1];
                dp[i - 1][j] %= MOD;
            }
        } else {
            for (int j = -1; j <= 1; j++) {
                dp[i - 1][x[i - 1]] += dp[i][x[i - 1] + j];
            }
            dp[i - 1][x[i - 1]] %= MOD;
        }
    }

    long long L = 1;
    if (know != 1 || n == 1) {
        L = 0;
        for (int i = 1; i <= m; i++) {
            L = (L + dp[1][i]) % MOD;
        }
    }
    long long R = 1;
    if (know != n) {
        R = 0;
        for (int i = 1; i <= m; i++) {
            R = (R + dp[n][i]) % MOD;
        }
    }
    long long res = (L * R) % MOD;
    cout << res << nl;

    return 0;
}
