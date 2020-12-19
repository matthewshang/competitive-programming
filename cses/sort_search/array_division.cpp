#include "bits/stdc++.h"

using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);

    int n, k; cin >> n >> k;
    vector<int> x(n);
    for (int i = 0; i < n; i++) {
        cin >> x[i];
    }

    auto ok = [&](long long max_sum) -> bool {
        int subs = 1;
        long long cur_sum = 0;
        for (int i = 0; i < n; i++) {
            if (x[i] > max_sum) {
                return false;
            }
            if (cur_sum + x[i] > max_sum) {
                subs++;
                cur_sum = 0;
            }
            cur_sum += x[i];
        }
        return subs <= k;
    };

    long long low = 1;
    long long high = 1e15;
    while (low < high) {
        long long mid = low + (high - low) / 2;
        if (ok(mid)) {
            high = mid;
        } else {
            low = mid + 1;
        }
    }

    cout << low << '\n';
}