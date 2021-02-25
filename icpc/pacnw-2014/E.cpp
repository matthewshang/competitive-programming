#include "bits/stdc++.h"
 
using namespace std;
 
void solve() {
    string s; cin >> s;
    int n = s.size();
 
    bool peak = false;
    for (int i = 0; i < n - 1; i++) {
        if (s[i] < s[i + 1]) {
            if (peak) {
                cout << -1 << '\n';
                return;
            } 
        } else if (s[i] > s[i + 1]) {
            peak = true;
        }
    }
 
    vector<vector<vector<vector<long long>>>> dp(n + 1, vector<vector<vector<long long>>>(11, vector<vector<long long>>(2, vector<long long>(2, -1))));
    auto go = [&](auto& self, int pos, int last, bool limit, bool peaked) -> long long {
        if (pos == n) {
            return 1;
        }
        if (dp[pos][last][limit][peaked] != -1) {
            return dp[pos][last][limit][peaked];
        }
        int cur = s[pos] - '0';
        long long res = 0;
        for (int d = 0; d <= 9; d++) {
            if (limit && d > cur) {
                break;
            }
            if (peaked && d > last) {
                break;
            }
 
            bool next_limit = limit && d == cur;
            bool next_peaked = peaked || (d < last && pos > 0);
            res += self(self, pos + 1, d, next_limit, next_peaked);
        }
        dp[pos][last][limit][peaked] = res;
        return res;
    };
 
    // Subtract 1 for 0
    long long res = go(go, 0, 0, true, false) - 1;
    cout << res << '\n';
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    int T; cin >> T;
    while (T--) {
        solve();
    }
 
    return 0;
}