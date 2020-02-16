#include "bits/stdc++.h"

using namespace std;
using ll = long long;

void pr(int x) { cout << x; }
void pr(ll x) { cout << x; }
void pr(size_t x) { cout << x; }
void pr(const char* s) { cout << s; }
void pr(string& s) { cout << s; }
void pr(const string& s) { cout << s; }
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
        int n; cin >> n;
        string s; cin >> s;
        vector<int> a(n);

        auto solve = [&](char skip, char take) {
            int p = 0;
            while (p < s.size()) {
                while (p < s.size() && s[p] == skip)
                    p++;
                int q = p;
                while (q < s.size() && s[q] == take)
                    q++;
                reverse(a.begin() + p, a.begin() + q + 1);
                p = q;
            }
            for (int x : a) cout << x << " ";
            cout << endl;
        };
        for (int i = 0; i < n; i++)
            a[i] = n - i;
        solve('>', '<');

        for (int i = 0; i < n; i++)
            a[i] = i + 1;
        solve('<', '>');
    }
    return 0;
}
