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

void setIO(string s) {
    freopen((s + ".in").c_str(), "r", stdin);
    freopen((s + ".out").c_str(), "w", stdout);
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    #ifndef LOCAL
    setIO("fortmoo");
    #endif

    int n, m; cin >> n >> m;
    vector<string> g(n);
    F0R (i, n) cin >> g[i];
    
    vvi pre_col(m, vi(n + 1));
    F0R (j, m) {
        F0R (i, n) {
            pre_col[j][i + 1] += pre_col[j][i];
            if (g[i][j] == 'X') {
                pre_col[j][i + 1]++;
            }
        }
    }

    auto check_col = [&](int c, int r1, int r2) -> bool {
        return pre_col[c][r2 + 1] - pre_col[c][r1] == 0;
    };

    int max_area = 0;
    F0R (row_top, n) {
        FOR (row_bot, row_top, n) {
            int last_col = -1;
            F0R (col, m) {
                if (g[row_bot][col] == 'X' || g[row_top][col] == 'X') {
                    last_col = -1;
                } else {
                    if (check_col(col, row_top, row_bot)) {
                        if (last_col == -1) {
                            last_col = col;
                        }
                        int area = (row_bot - row_top + 1) * (col - last_col + 1);
                        max_area = max(max_area, area);
                    }
                }
            }
        }
    }
    cout << max_area << nl;

    return 0;
}
