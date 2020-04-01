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

    // int n, m; cin >> n >> m;
    // int a[n][m];
    // for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) cin >> a[i][j];

    // int dp[n + 1][m + 1];
    // for (int i = 0; i <= n; i++)
    //     for (int j = 0; j <= m; j++)
    //         dp[i][j] = 0;
    // dp[0][1] = a[0][0];
    // for (int i = 1; i <= n; i++) {
    //     for (int j = 1; j <= m; j++) {
    //         dp[i][j] = max(dp[i - 1][j] & a[i - 1][j - 1], dp[i][j - 1] & a[i - 1][j - 1]);
    //         cout << dp[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    // cout << dp[n][m] << endl;
    int d; cin >> d;
    cout << "3 3\n";
    int a[3][3];
    a[0][0] = (1 << 18) - 1;
    a[0][1] = d;
    a[0][2] = 0;
    a[1][0] = 1 << 17;
    a[1][1] = (1 << 18) - 1;
    a[1][2] = (1 << 18) - 1;
    a[2][0] = 0;
    a[2][1] = (1 << 18) - 1;
    a[2][2] = d;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
