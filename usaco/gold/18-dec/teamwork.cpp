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

template <typename T> 
void pr(T& v) {
    cout << "{";
    bool f = true; for (auto& x : v) cout << (!f ? ", " : ""), f = false, pr(x);
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

struct RMQ {
    vector<vector<int>> st;

    RMQ(vector<int>& v) {
        const int n = v.size();
        int k = (int)floor(log2(n)) + 1;
        st.resize(n, vector<int>(k));
        for (int i = 0; i < n; i++)
            st[i][0] = v[i];
        for (int j = 1; j <= k; j++)
            for (int i = 0; i + (1 << j) <= n; i++)
                st[i][j] = max(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]);
    }

    int query(int u, int v) {
        if (u > v) swap(u, v);
        int j = (int)floor(log2(v - u + 1));
        return max(st[u][j], st[v - (1 << j) + 1][j]);
    }
};

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    setIO("teamwork");

    int n, k; cin >> n >> k;
    vector<int> c(n); for (int& x : c) cin >> x;
    RMQ R(c);

    int pre[n + 1];
    pre[0] = 0;
    for (int i = 0; i < n; i++)
        pre[i + 1] = pre[i] + c[i];

    vector<int> dp(n + 1, 0);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < k && j <= i; j++) {
            int m = R.query(i - j, i);
            int sum = pre[i + 1] - pre[i - j];
            dp[i + 1] = max(dp[i + 1], dp[i - j] + m * (j + 1) - sum);
        }
    }

    cout << (dp[n] + pre[n]) << endl;

    return 0;
}
