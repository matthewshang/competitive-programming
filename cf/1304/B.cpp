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
    int n, m; cin >> n >> m;
    vector<string> s(n);
    for (int i = 0; i < n; i++)
        cin >> s[i];

    set<string> st;
    for (int i = 0; i < n; i++)
        st.insert(s[i]);
    
    string accum = "";
    string mx = "";
    for (int i = 0; i < n; i++) {
        bool ok = true;
        for (int j = 0; j < s[i].size() / 2; j++) {
            if (s[i][j] != s[i][s[i].size() - j - 1]) {
                ok = false;
                break;
            }
        }
        if (!ok) {
            string t = s[i];
            reverse(t.begin(), t.end());
            if (st.count(t)) {
                accum += s[i];
                st.erase(s[i]);
                st.erase(t);
            }
        } else if (mx.size() < s[i].size()) {
            mx = s[i];
        }
    }

    string rev = accum;
    reverse(rev.begin(), rev.end());
    string ans = accum + mx + rev;
    cout << ans.size() << endl;
    cout << ans << endl;
    return 0;
}
