#include "bits/stdc++.h"

using namespace std;
using ll = long long;

void pr(int x) { cout << x; }
void pr(ll x) { cout << x; }
void pr(size_t x) { cout << x; }
void pr(const char* s) { cout << s; }
void pr(string& s) { cout << s; }
void pr(bool x) { cout << (x ? "true" : "false"); }

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

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    int n, k; cin >> n >> k;
    map<int, int> count;
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        count[x]++;
    }

    vector<int> v(count.size());
    vector<int> sz(count.size());
    int i = 0;
    for (auto [x, c] : count) {
        v[i++] = c;
        sz[i - 1] = x;

        if (c >= k) {
            cout << "0\n";
            return 0;
        }
    }
    int m = count.size();
    vector<int> g(m);
    for (int i = 0; i < m - 1; i++) {
        g[i] = sz[i + 1] - sz[i];
    }

    vector<ll> pre(m + 1);
    pre[0] = 0;
    for (int i = 0; i < m; i++) {
        pre[i + 1] = pre[i] + v[i];
    }
    vector<ll> R(m), L(m);
    L[0] = 0; L[1] = 0;
    for (int i = 2; i < m; i++) {
        L[i] = g[i - 2] * pre[i - 1] + L[i - 1];
    }
    R[m - 1] = 0; R[m - 2] = 0;
    for (int i = m - 3; i >= 0; i--) {
        R[i] = g[i + 1] * (pre[m] - pre[i + 2]) + R[i + 1];
    }

    dbg(v);
    dbg(sz);
    dbg(g);
    dbg(pre);
    dbg(L);
    dbg(R);

    ll ans = 1LL << 60;
    for (int i = 0; i < m; i++) {
        ll need = k - v[i];
        if (need <= 0) ans = 0;
        ll cost = 0;
        
        cost += L[i] + (i > 0 ? g[i - 1] * min(need, pre[i]) : 0);
        need -= min(need, pre[i]);
        if (need > 0) {
            cost += R[i] + g[i] * min(need, pre[m] - pre[i + 1]);
        }
        ans = min(ans, cost);

        cost = 0; need = k - v[i];
        cost += R[i] + g[i] * min(need, pre[m] - pre[i + 1]);
        need -= min(need, pre[m] - pre[i + 1]);
        if (need > 0) {
            cost += L[i] + (i > 0 ? g[i - 1] * min(need, pre[i]) : 0);
        }
        ans = min(ans, cost);
    }

    cout << ans << endl;

    return 0;
}
