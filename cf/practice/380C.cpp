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

struct BIT { // Operation must be reversible
    vector<int> bit; int n;
    BIT(int n) { this->n = n + 1; bit.assign(n + 1, 0); } 
    int query(int i) { // [0, n)
        int ans = 0;
        for (++i; i > 0; i -= i & -i) ans += bit[i];
        return ans;
    }
    int query(int l, int r) { // [l, r]
        return query(r) - query(l - 1);
    }
    void update(int i, int val) { // [0, n)
        for (++i; i < n; i += i & -i) bit[i] += val;
    }
};


int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    
    string s; cin >> s;
    int m; cin >> m;
    int n = s.size();

    vector<pair<pair<int, int>, int>> q(m);
    vector<int> ans(m);
    for (int i = 0; i < m; i++) {
        cin >> q[i].first.second >> q[i].first.first;
        q[i].second = i;
    }
    sort(q.begin(), q.end());

    stack<int> open;
    BIT B(n + 1);
    int pos = 1;
    for (int i = 0; i < m; i++) {
        auto [r, l] = q[i].first;
        while (pos <= r) {
            if (s[pos - 1] == '(') {
                open.push(pos);
            } else {
                if (!open.empty()) {
                    int p = open.top(); open.pop();
                    B.update(p, 1);
                }
            }
            pos++;
        }
        ans[q[i].second] = B.query(l, r) * 2;
    }

    for (int i = 0; i < m; i++) {
        cout << ans[i] << endl;
    }

    return 0;
}
