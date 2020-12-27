#include "bits/stdc++.h"

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin >> n;
    long long total_time = 0;
    long long max_time = 0;
    for (int i = 0; i < n; i++) {
        int t; cin >> t;
        total_time += t;
        if (t > max_time) {
            max_time = t;
        }
    }
    cout << max(2 * max_time, total_time) << '\n';

    return 0;
}