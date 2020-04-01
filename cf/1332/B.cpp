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
        int n; cin >> n;
        vector<int> a(n); for (int& x : a) cin >> x;

        vector<int> ps = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31};
        vector<int> c(n, -1);
        int col = 0;
        for (int p = 0; p < 11; p++) {
            bool mod = false;
            for (int i = 0; i < n; i++) {
                if (c[i] == -1 && a[i] % ps[p] == 0) {
                    c[i] = col;
                    mod = true;
                }
            }
            if (mod) col++;
        }

        cout << col << endl;
        for (int i = 0; i < n; i++) {
            cout << (c[i] + 1) << " ";
        }
        cout << endl;
    }

    return 0;
}
