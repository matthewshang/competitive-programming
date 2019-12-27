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

void solve() {
    string p, h; cin >> p >> h;
    if (h.size() < p.size()) {
        cout << "NO" << endl;
        return;
    }
    for (int i = 0; i < h.size() - p.size() + 1; i++) {
        int count[26];
        for (int j = 0; j < 26; j++)
            count[j] = 0;
        for (int j = 0; j < p.size(); j++) {
            count[p[j] - 'a']++;
            count[h[i + j] - 'a']--;
        }
        bool good = true;
        for (int j = 0; j < 26; j++)
            if (count[j] != 0)
                good = false;
        if (good) {
            cout << "YES" << endl;
            return;
        }
    }
    cout << "NO" << endl;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    int t; cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
