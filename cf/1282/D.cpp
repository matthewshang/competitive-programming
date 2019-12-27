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

int query(string& s) {
    cout << s << endl;
    int ans; cin >> ans;
    if (ans == 0 || ans == -1) {
        exit(0);
    }
    return ans;
}

int query(const char* s) {
    cout << s << endl;
    int ans; cin >> ans;
    if (ans == 0 || ans == -1) {
        exit(0);
    }
    return ans;
}

int main() {
    string as = "", bs = "";
    for (int i = 0; i < 300; i++) {
        as += 'a';
        bs += 'b';
    }

    int p = query(as), q = query(bs);
    // p = 300 - n + #b
    // q = 300 - n + #a
    // p + q = 600 - n => n = 600 - p - q
    // #b = p - 300 + n, #a = q - 300 + n
    int n = 600 - p - q;
    int bn = p - 300 + n;

    string s = "";
    for (int i = 0; i < n; i++)
        s += 'a';

    vector<bool> b(n);
    for (int i = 0; i < n - 1; i++) {
        s[i] = 'b';
        b[i] = (query(s) < bn);
        s[i] = 'a';
    }

    int total = 0;
    for (int i = 0; i < n - 1; i++)
        total += b[i];
    if (total != bn)
        b[n - 1] = true;

    for (int i = 0; i < n; i++)
        s[i] = b[i] ? 'b' : 'a';

    cout << s << endl;

    return 0;
}
