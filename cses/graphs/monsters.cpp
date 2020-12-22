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

const int D[4][2] = {{ 1, 0 }, { -1, 0 }, { 0, 1 }, { 0, -1 }};

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);

    int n, m; cin >> n >> m;
    vector<string> g(n);
    for (int i = 0; i < n; i++) {
        cin >> g[i];
    }

    int Ax, Ay;
    queue<pii> q;
    vector<vector<int>> dist(n, vector<int>(m, 1e9));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (g[i][j] == 'A') {
                Ax = i;
                Ay = j;
            } else if (g[i][j] == 'M') {
                q.push({ i, j });
                dist[i][j] = 0;
            }
        }
    }

    while (!q.empty()) {
        auto [i, j] = q.front(); q.pop();
        for (int d = 0; d < 4; d++) {
            int ii = i + D[d][0];
            int jj = j + D[d][1];
            if (ii >= 0 && ii < n && jj >= 0 && jj < m && g[ii][jj] != '#' && dist[i][j] + 1 < dist[ii][jj]) {
                dist[ii][jj] = dist[i][j] + 1;
                q.push({ ii, jj });
            }
        }
    }

    vector<vector<pair<int, int>>> last(n, vector<pair<int, int>>(m, { -1, -1 }));
    vector<vector<int>> out(n, vector<int>(m, 1e9));
    q.push({ Ax, Ay });
    out[Ax][Ay] = 0;
    while (!q.empty()) {
        auto [i, j] = q.front(); q.pop();
        for (int d = 0; d < 4; d++) {
            int ii = i + D[d][0];
            int jj = j + D[d][1];
            if (ii >= 0 && ii < n && jj >= 0 && jj < m && g[ii][jj] != '#' && out[i][j] + 1 < out[ii][jj]) {
                last[ii][jj] = { i, j };
                out[ii][jj] = out[i][j] + 1;
                q.push({ ii, jj });
            }
        }
    }

    auto answer = [&](int i, int j) {
        string path;
        while (g[i][j] != 'A') {
            int ii = last[i][j].first;
            int jj = last[i][j].second;
            if (ii < i) {
                path += 'D';
            } else if (ii > i) {
                path += 'U';
            } else if (jj < j) {
                path += 'R';
            } else {
                path += 'L';
            }
            i = ii;
            j = jj;
        }
        reverse(path.begin(), path.end());
        cout << "YES" << nl;
        cout << path.size() << nl;
        cout << path << nl;
        exit(0);
    };

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if ((i == 0 || i == n - 1 || j == 0 || j == m - 1) && out[i][j] < dist[i][j]) {
                answer(i, j);
            }
        }
    }

    cout << "NO" << nl;

    return 0;
}
