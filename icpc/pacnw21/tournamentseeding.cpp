#include <bits/stdc++.h>
using namespace std;

/* Date: 2022-03-20
 * Source: PACNW 2022
 * Notes: In the kth round, the best 2^(n-k) players are paired with the next
 * best 2^(n-k) players. Pair greedily and do it fast with binary search.
 */

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;
    int N = 1 << n;
    vector<int> r(N);
    for (int i = 0; i < N; i++) {
        cin >> r[i];
    }

    sort(r.begin(), r.end());
    int close = 0;
    for (int i = 1; i <= n; i++) {
        int lose = N - (1 << i);
        int win = lose + (1 << (i - 1));
        int low = lose;
        for (int j = win; j < N; j++) {
            int pos = lower_bound(r.begin() + low, r.begin() + win, r[j] - k) - r.begin();
            if (pos < win && r[pos] < r[j]) {
                close++;
                low = pos + 1;
            }
            if (low >= win) {
                break;
            }
        }
    }
    cout << close << "\n";

    return 0;
}