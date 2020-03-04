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
    int n, m; cin >> n >> m;
    int d[n];
    for (int i = 0; i < n; i++)
        d[i] = -1;
    for (int i = 0; i < m; i++) {
        int s, c; cin >> s >> c;
        if (d[s - 1] != -1 && d[s - 1] != c) {
            cout << -1 << endl;
            return 0;
        }
        d[s - 1] = c;
    }

    if (n == 1) {
        cout << max(0, d[0]) << endl;
        return 0;
    }

    if (d[0] == 0) {
        cout << -1 << endl;
        return 0;
    }

    string ans = "";
    bool trail = true;
    for (int i = 0; i < n; i++) {
        if (d[i] != -1) {
            ans += to_string(d[i]);
            trail = false;
        } else if (trail) {
            ans += "1";
            trail = false;
        } else {
            ans += "0";
        }
    }
    cout << ans << endl;
    return 0;
}
