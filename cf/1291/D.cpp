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
    string s; cin >> s;
    int n = s.size();
    int pre[n + 1][26];
    for (int j = 0; j < 26; j++)
        pre[0][j] = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < 26; j++) {
            pre[i][j] = pre[i - 1][j];
        }
        pre[i][s[i - 1] - 'a']++;
    }

    int q; cin >> q;
    while (q--) {
        int l, r; cin >> l >> r;
        l--; r--;
        bool ok;
        if (r - l == 0) {
            ok = true;
        } else if (s[l] != s[r]) {
            ok = true;
        } else {
            int unique = 0;
            for (int i = 0; i < 26; i++) {
                if (pre[r + 1][i] - pre[l][i] > 0)
                    unique++;
            }
            ok = unique >= 3;
        }
        cout << (ok ? "Yes" : "No") << endl;
    }


    return 0;
}
