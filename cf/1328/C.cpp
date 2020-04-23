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
        string x; cin >> x;
        string a = "", b = "";
        bool flag = false;
        for (int i = 0; i < n; i++) {
            if (x[i] == '2') {
                if (flag)
                    a += '0', b += '2';
                else
                    a += '1', b += '1';
            } else if (x[i] == '1') {
                if (flag) {
                    a += '0'; b += '1';
                } else {
                    a += '1'; b += '0';
                    flag = true;
                }
            } else {
                a += '0'; b += '0';
            }
        }
        cout << a << endl << b << endl;
    }

    return 0;
}
