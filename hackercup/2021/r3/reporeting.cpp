#include <bits/stdc++.h>
using namespace std;

/* Date: 2021-10-09
 * Source: FB Hacker Cup 2021 R3
 * Summary: Maintain a set of intervals. When inserting an interval, merge all
 * overlapping intervals.
 */

constexpr int MOD = 1e9 + 7;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    for (int tc = 1; tc <= T; tc++) {
        int n, m;
        cin >> n >> m;
        
        // pos, {-1, +1} = (close, open)
        set<pair<int, int>> intervals;
        intervals.insert({0, -1});
        intervals.insert({n + 1, 1});
        int ans = 1;
        int pairs = (int64_t(n) * (n - 1) / 2) % MOD;
        for (int e = 0; e < m; e++) {
            int a, b;
            cin >> a >> b;
            if (a > b) {
                swap(a, b);
            }

            auto it_a = intervals.lower_bound({a, -1});
            auto it_b = intervals.lower_bound({b, 2});

            int whole_start;
            if (it_a->second == -1) {
                --it_a;
                whole_start = it_a->first;
            } else {
                whole_start = a;
            }

            int whole_end;
            if (it_b->second == -1) {
                whole_end = it_b->first;
                ++it_b;
            } else {
                whole_end = b;
            }

            int remove = 0;
            int cur_start = whole_start;
            auto it = it_a;
            while (it != it_b) {
                if (it->second == -1) {
                    int len = it->first - cur_start + 1;
                    remove = (remove + int64_t(len) * (len - 1) / 2 % MOD) % MOD;
                } else {
                    cur_start = it->first;
                }
                it = intervals.erase(it);
            }

            intervals.insert({whole_start, 1});
            intervals.insert({whole_end, -1});
            int whole_len = whole_end - whole_start + 1;

            pairs = (pairs + int64_t(whole_len) * (whole_len - 1) / 2 % MOD) % MOD;
            pairs = (pairs - remove + MOD) % MOD;
            ans = int64_t(ans) * pairs % MOD;
        }

        cout << "Case #" << tc << ": " << ans << '\n';
    }

    return 0;
}