#include "bits/stdc++.h"

using namespace std;
using ll = long long;

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

    int t; cin >> t;
    while (t--) {
        int n, p, k; cin >> n >> p >> k;
        vector<int> a(n);
        for (int& x : a) cin >> x;
        sort(a.begin(), a.end());
        vector<int> dp(n + 1);
        vector<int> count(n + 1);
        dp[0] = 0;
        count[0] = 0;
        int ans = 0;
        for (int i = 1; i <= n; i++) {
            if (i >= k && (dp[i - k] + a[i - 1]) <= p) {
                count[i] = count[i - k] + k;
                dp[i] = dp[i - k] + a[i - 1];
            } 
            else if ((a[i - 1] + dp[i - 1]) <= p) {
                count[i] = count[i - 1] + 1;
                dp[i] = dp[i - 1] + a[i - 1];
            }
            else if (a[i - 1] <= p) {
                count[i] = 1;
                dp[i] = a[i - 1];
            }
            ans = max(ans, count[i]);
        }
        dbg(dp);
        dbg(count);
        cout << ans << endl;
    }

    return 0;
}
