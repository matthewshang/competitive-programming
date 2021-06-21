#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int64_t n;
    cin >> n;
    int64_t count = 0;
    for (int i = 1; i <= 50; i++) {
        int64_t m = 1LL << i;
        count += (m / 2) * (n / m);
        count += max(int64_t(0), n % m - m / 2 + 1);
    }
    cout << count << '\n';

    return 0;
}
