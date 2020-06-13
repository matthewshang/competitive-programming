#include "bits/stdc++.h"

using namespace std;
using ll = long long;

void setIO(string s) {
    freopen((s + ".in").c_str(), "r", stdin);
    #ifndef TESTING
    freopen((s + ".out").c_str(), "w", stdout);
    #endif
}

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

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    setIO("cowmbat");

    int n, m, k; cin >> n >> m >> k;
    string s; cin >> s;
    int a[m][m];
    for (int i = 0; i < m; i++)
        for (int j = 0; j < m; j++)
            cin >> a[i][j];

    for (int l = 0; l < m; l++)
        for (int i = 0; i < m; i++)
            for (int j = 0; j < m; j++)
                a[i][j] = min(a[i][j], a[i][l] + a[l][j]);

    const int INF = 1e9;
    int dp[n][m];

    int pre[n + 1][m];
    for (int i = 0; i < m; i++) {
        int cost = 0;
        pre[0][i] = 0;
        for (int j = 0; j < n; j++) {
            int start = (int)(s[j] - 'a');
            cost += a[start][i];
            if (j < k) dp[j][i] = cost;
            else dp[j][i] = INF;

            pre[j + 1][i] = cost;
        }
    }

    for (int i = k; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int start = (int)(s[i] - 'a');
            dp[i][j] = min(dp[i][j], dp[i - 1][j] + a[start][j]);
            if (i >= 2 * k - 1) {
                for (int l = 0; l < m; l++)
                    dp[i][j] = min(dp[i][j], dp[i - k][l] + pre[i + 1][j] - pre[i - k + 1][j]);
            }
        }
    }

    int ans = INF;
    for (int i = 0; i < m; i++)
        ans = min(ans, dp[n - 1][i]);
    cout << ans << endl;

    return 0;
}
