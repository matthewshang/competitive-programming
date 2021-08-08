#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;

    unordered_map<char, int8_t> compress;
    vector<int8_t> seq(n);
    vector<vector<int16_t>> locs(k);
    for (int i = 0; i < n; i++) {
        if (auto it = compress.find(s[i]); it != compress.end()) {
            seq[i] = it->second;
        } else {
            seq[i] = compress.size();
            compress[s[i]] = compress.size();
        }
        locs[seq[i]].push_back(i);
    }

    vector<vector<int16_t>> pre(n + 1, vector<int16_t>(k));
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < k; j++) {
            pre[i][j] = pre[i - 1][j] + (seq[i - 1] == j);
        }
    }

    const int INF = 2 * n;
    vector<int16_t> dp(1 << k, INF);

    auto cost = [&](int watch_mask, int who) -> int {
        const auto& where = locs[who];
        const int L = where.size();
        int clicks = L;
        for (int i = 0; i < L - 1; i++) {
            int between = 0;
            for (int j = 0; j < k && between == 0; j++) {
                if (watch_mask & (1 << j)) continue;
                between += pre[where[i + 1] + 1][j] - pre[where[i]][j];
            }
            clicks -= between == 0;
        }
        return clicks;
    };

    dp[0] = 0;
    for (int mask = 1; mask < (1 << k); mask++) {
        for (int last = 0; last < k; last++) {
            if ((mask & (1 << last)) == 0) continue;
            int prev = mask - (1 << last);

            int16_t cur = dp[prev] + cost(mask, last);
            dp[mask] = min(dp[mask], cur);
        }
    }

    int all_mask = (1 << k) - 1;
    cout << dp[all_mask] << '\n';

    return 0;
}