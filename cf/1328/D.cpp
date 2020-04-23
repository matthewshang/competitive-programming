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

void solve() {
    int n; cin >> n;
    vector<int> t(n); for (int& x : t) cin >> x;

    bool same = true;
    for (int i = 1; i < n; i++) {
        if (t[i - 1] != t[i]) {
            same = false;
            break;
        }
    }

    if (same) {
        cout << "1\n";
        for (int i = 0; i < n; i++) {
            cout << "1 ";
        }
        cout << endl;
        return;
    }

    if (n % 2) {
        vector<int> c(n);
        c[0] = 1;
        bool flag = false;
        for (int i = 1; i < n - 1; i++) {
            int col = i % 2 + 1;
            if (t[i - 1] == t[i] && !flag) {
                c[i] = c[i - 1];
                flag = true;
            } else {
                c[i] = (c[i - 1]) % 2 + 1;
            }
        }
        int k;
        if (flag || t[n - 1] == t[n - 2]) {
            c[n - 1] = (c[0]) % 2 + 1;
            k = 2;
        } else if (t[n - 1] == t[0]) {
            c[n - 1] = (c[n - 2]) % 2 + 1;
            k = 2;
        } else {
            c[n - 1] = 3;
            k = 3;
        }

        cout << k << endl;
        for (int i = 0; i < n; i++) {
            cout << c[i] << " ";
        }
        cout << endl;
    } else {
        cout << "2\n";
        for (int i = 0; i < n; i++) {
            cout << (i % 2 + 1) << " ";
        }
        cout << endl;
    }
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    int q; cin >> q;
    while (q--) {
        solve();


    }

    return 0;
}
