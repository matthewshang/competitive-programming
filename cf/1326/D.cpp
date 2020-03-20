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
        string s; cin >> s;
        int n = s.size();

        int idx = 0;
        while (s[idx] == s[n - idx - 1] && idx < n - idx - 1) {
            idx++;
        }

        const ll MD = 998244353;
        const ll p = 197;

        vector<ll> ps(n + 1);
        ps[0] = 1;
        for (int i = 1; i <= n; i++) {
            ps[i] = (ps[i - 1] * p) % MD;
        }

        ll r = 0, rev_r = 0;
        int mx = 0;
        for (int i = idx; i < n - idx; i++) {
            ll mul = ((s[i] - 'a') * ps[i - idx]) % MD;
            r = (r + mul) % MD;
            rev_r = (rev_r * p) % MD;
            rev_r = (rev_r + s[i] - 'a') % MD;
            if (r == rev_r) {
                mx = i - idx + 1;
            }
        }

        ll l = 0, rev_l = 0;
        int mx2 = 0;
        for (int i = n - idx - 1; i >= idx; i--) {
            ll mul = ((s[i] - 'a') * ps[n - idx - 1 - i]) % MD;
            l = (l + mul) % MD;
            rev_l = (rev_l * p) % MD;
            rev_l = (rev_l + s[i] - 'a') % MD;
            if (l == rev_l) {
                mx2 = n - idx - i;
            }
        }
        dbg(idx, mx, mx2);

        string pre = "";
        for (int i = 0; i < idx; i++) {
            pre += s[i];
        }
        string ans = pre;
        if (mx >= mx2) {
            for (int i = idx; i < idx + mx; i++) {
                ans += s[i];
            }
        } else {
            for (int i = n - idx - 1; i > n - idx - 1 - mx2; i--) {
                ans += s[i];
            }
        }
        dbg(ans);
        reverse(pre.begin(), pre.end());
        ans += pre;
        cout << ans << endl;
    }

    return 0;
}
