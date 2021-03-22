#include "bits/stdc++.h"

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T; cin >> T;
    for (int tc = 1; tc <= T; tc++) {
        int n, k; cin >> n >> k;
        string s; cin >> s;

        int good = 0;
        for (int i = 0; i < n / 2; i++) {
            if (s[i] != s[n - i - 1]) {
                good++;
            }
        }

        cout << "Case #" << tc << ": " << abs(good - k) << '\n';
    }

    return 0;
}