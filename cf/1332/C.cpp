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

    int t; cin >> t;
    while (t--) {
        int n, k; cin >> n >> k;
        string s; cin >> s;

        int d = n / k;

        int cnt[k][26];
        for (int i = 0; i < k; i++) {
            for (int j = 0; j < 26; j++) cnt[i][j] = 0;
            for (int j = i; j < n; j += k) {
                cnt[i][s[j] - 'a']++;
            }
        }

        int ans = 1e9;
        for (int i = 0; i < d; i++) {
            int cost = 0;
            for (int j = 0; j < k; j++) {
                int val = 1e9;
                for (int l = 0; l < 26; l++) {
                    val = min(val, d - cnt[j][l] + d - cnt[k - j - 1][l]);
                }
                cost += val;
            }
            ans = min(ans, cost / 2);
        }
        cout << ans << endl;
    }

    return 0;
}
