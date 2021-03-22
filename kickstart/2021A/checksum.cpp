#include "bits/stdc++.h"

using namespace std;

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
    for (int i = 0; i < int(v.size()); i++)
        res += char('0' + v[i]);
    res += "}"; return res; 
}
template <size_t SZ> string to_string(bitset<SZ> b) { 
    string res = "";
    for (int i = 0; i < int(SZ); i++)
        res += char('0' + b[i]);
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
    return "(" + to_string(p.first) + ", " + to_string(p.second) + ")"; 
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
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T; cin >> T;
    for (int tc = 1; tc <= T; tc++) {
        int N; cin >> N;
        vector<vector<int>> A(N, vector<int>(N));
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                cin >> A[i][j];
            }
        }
        vector<vector<int>> B(N, vector<int>(N));
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                cin >> B[i][j];
            }
        }
        vector<int> R(N);
        for (int i = 0; i < N; i++) {
            cin >> R[i];
        }
        vector<int> C(N);
        for (int i = 0; i < N; i++) {
            cin >> C[i];
        }

        vector<array<int, 3>> edges;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (A[i][j] == -1) {
                    edges.push_back({ B[i][j], i, N + j });
                }
            }
        }
        sort(edges.begin(), edges.end());
        reverse(edges.begin(), edges.end());

        vector<int> par(N * 2);
        iota(par.begin(), par.end(), 0);
        vector<int> sz(N * 2, 1);
        function<int(int)> find = [&](int x) -> int {
            if (par[x] != x) par[x] = find(par[x]);
            return par[x];
        };

        auto join = [&](int a, int b) -> bool {
            int u = find(a);
            int v = find(b);
            if (u == v) {
                return false;
            }
            if (sz[u] < sz[v]) {
                swap(u, v);
            }
            par[v] = u;
            sz[u] += sz[v];
            return true;
        };

        long long cost = 0;
        for (auto [w, u, v] : edges) {
            if (!join(u, v)) {
                cost += w;
            }
        }
        cout << "Case #" << tc << ": " << cost << '\n';
    }

    return 0;
}