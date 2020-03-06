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

    int tt; cin >> tt;
    while (tt--) {
        int n; cin >> n;
        string s; cin >> s;

        string ans = s;
        int best_k = 1;
        for (int k = 2; k <= n; k++) {
            string cur = s.substr(k - 1);
            string end = s.substr(0, k - 1);
            if ((n - k) % 2 == 0) {
                reverse(end.begin(), end.end());
            }
            cur += end;
            if (cur < ans) {
                ans = cur;
                best_k = k;
            }
        }
        cout << ans << endl << best_k << endl;
    }
    return 0;
}
