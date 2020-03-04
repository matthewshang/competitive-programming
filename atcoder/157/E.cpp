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

// Operation must be reversible
template <typename T>
struct BIT {
    vector<T> bit;
    int n;

    BIT(int n) {
        this->n = n + 1;
        bit.assign(n + 1, 0);
    }

    // 0 <= i < n
    T query(int i) {
        int ans = 0;
        for (++i; i > 0; i -= i & -i) ans += bit[i];
        return ans;
    }
    
    // inclusive
    T query(int l, int r) {
        return query(r) - query(l - 1);
    }

    // 0 <= i < n
    void upd(int i, T val) {
        for (++i; i < n; i += i & -i) bit[i] += val;
    }
};

int main() {
    ios::sync_with_stdio(0); cin.tie(0);


    int n; cin >> n;
    string s; cin >> s;
    vector<BIT<int>> B(26, BIT<int>(n));
    for (int i = 0; i < n; i++) {
        B[s[i] - 'a'].upd(i, 1);
    }

    int qq; cin >> qq;
    while (qq--) {
        int t; cin >> t;
        if (t == 1) {
            int i; cin >> i; i--;
            char c; cin >> c;
            B[s[i] - 'a'].upd(i, -1);
            B[c - 'a'].upd(i, 1);
            s[i] = c;

        } else {
            int l, r; cin >> l >> r;
            int ans = 0;
            for (int i = 0; i < 26; i++) {
                ans += B[i].query(l - 1, r - 1) > 0;
            }
            cout << ans << endl;
        }
    }



    return 0;
}
