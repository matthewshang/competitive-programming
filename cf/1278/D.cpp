#include "bits/stdc++.h"

using namespace std;
using ll = long long;

void pr(bool x) { cout << (x ? "true" : "false"); }
void pr(int x) { cout << x; }
void pr(ll x) { cout << x; }
void pr(size_t x) { cout << x; }
void pr(const char* s) { cout << s; }
void pr(string& s) { cout << s; }

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

struct DSU {
    vector<int> par;
    vector<ll> sz;

    DSU(int s) {
        par.resize(s);
        sz.resize(s);
        for (int i = 0; i < s; i++) {
            par[i] = i;
            sz[i] = 1;
        }
    }

    int find(int x) {
        if (par[x] != x)
            par[x] = find(par[x]);
        return par[x];
    }

    bool unite(int x, int y) {
        int u = find(x), v = find(y);
        if (u == v) return false;
        if (sz[u] < sz[v]) swap(u, v);
        sz[u] += sz[v];
        par[v] = u;
        return true;
    }
};

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    int n; cin >> n;
    vector<pair<int, int>> ev;
    vector<pair<int, int>> s;
    for (int i = 0; i < n; i++) {
        int l, r; cin >> l >> r;
        ev.emplace_back(l, i);
        ev.emplace_back(r, i);
        s.emplace_back(l, r);
    }
    sort(ev.begin(), ev.end());

    DSU D(n);
    set<pair<int, int>> open;
    int m = 0;
    for (auto& it : ev) {
        if (m >= n) break;
        if (open.find(it) != open.end()) {
            open.erase(it);
        }
        else {
            int r = s[it.second].second;
            for (auto& x : open) {
                if (s[x.second].second > r) break;
                D.unite(x.second, it.second);
                m++;
                if (m >= n) break;
            }
            open.emplace(r, it.second);
        }
    }

    bool ok = true;
    for (int i = 0; i < n; i++) {
        if (D.find(i) != D.find(0)) {
            ok = false;
        }
    }
    cout << ((ok && m == n - 1) ? "YES" : "NO") << endl;

    return 0;
}
