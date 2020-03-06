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

template <typename T1, typename T2>
void pr(pair<T1, T2>& p) {
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

    int n, p, k; cin >> n >> p >> k;
    pair<int, int> a[n]; 
    for (int i = 0; i < n; i++) {
        cin >> a[i].first;
        a[i].second = i;
    }
    sort(a, a + n, greater<pair<int, int>>());

    int s[n][p];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < p; j++)
            cin >> s[i][j];

    ll dp[n + 1][1 << p];
    for (ll i = 0; i <= n; i++)
        for (ll j = 0; j < (1 << p); j++)
            dp[i][j] = -1;
    dp[0][0] = 0;

    for (ll i = 1; i <= n; i++) {
        ll cur = a[i - 1].second;
        for (ll m = 0; m < (1 << p); m++) {
            int used = i - 1 - __builtin_popcount(m);
            // Add to audience
            if (dp[i - 1][m] != -1) {
                dp[i][m] = dp[i - 1][m] + (used < k ? a[i - 1].first : 0);
            }

            // Put in positions
            for (ll j = 0; j < p; j++) {
                ll val = dp[i - 1][m ^ (1 << j)];
                if ((m & (1 << j)) && (val != -1)) {
                    dp[i][m] = max(dp[i][m], val + s[cur][j]);
                }
            }
        }
    }

    cout << dp[n][(1 << p) - 1] << endl;

    return 0;
}
