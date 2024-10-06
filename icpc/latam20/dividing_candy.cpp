#include <bits/stdc++.h>
using namespace std;

/* Date: 2022-02-19
 * Source: LATAM 2020
 * Summary: Can be properly split if the sum has two bits or is a power of two.
 */

constexpr int MAX_A = 100000;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> count(2 * MAX_A + 1);
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        count[a]++;
    }

    if (n == 1) {
        cout << "N" << "\n";
        return 0;
    }

    for (int i = 0; i <= 2 * MAX_A - 1; i++) {
        count[i + 1] += count[i] / 2;
        count[i] %= 2;
    }

    int64_t on = accumulate(count.begin(), count.end(), int64_t(0));
    bool ok = (on == 2) || (on == 1 && count[0] == 0);
    cout << (ok ? "Y" : "N") << "\n";

    return 0;
}