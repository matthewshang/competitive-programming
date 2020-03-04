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

    int board[3][3];
    bool mark[3][3];
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cin >> board[i][j];
            mark[i][j] = false;
        }
    }

    int n; cin >> n;
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        for (int u = 0; u < 3; u++) {
            for (int v = 0; v < 3; v++) {
                if (board[u][v] == x) mark[u][v] = true;
            }
        }
    }

    bool ans = false;
    ans |= mark[0][0] && mark[1][1] && mark[2][2];
    ans |= mark[2][0] && mark[1][1] && mark[0][2];
    for (int i = 0; i < 3; i++) {
        ans |= mark[i][0] && mark[i][1] && mark[i][2];
        ans |= mark[0][i] && mark[1][i] && mark[2][i];
    }
    cout << (ans ? "Yes" : "No") << endl;

    return 0;
}
