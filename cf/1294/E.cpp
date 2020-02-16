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
    int a[m][n];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[j][i];
        }
    }

    int off[n];
    int total = 0;
    for (int j = 0; j < m; j++) {
        for (int i = 0; i < n; i++) off[i] = 0;
        for (int i = 0; i < n; i++) {
            if ((a[j][i] - j - 1) % m == 0 && a[j][i] <= n * m) {
                int k = i - (a[j][i] - j - 1) / m;
                k = (k + n) % n;
                off[k]++;
            }
        }
        int ans = 1<<30;
        for (int i = 0; i < n; i++) {
            ans = min(ans, i + n - off[i]);
        }
        total += ans;
    }
    cout << total << endl;

    return 0;
}
