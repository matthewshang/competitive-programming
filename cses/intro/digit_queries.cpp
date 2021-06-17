#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int q;
    cin >> q;
    while (q--) {
        int64_t k;
        cin >> k;

        int64_t n = 1;
        int64_t s = 0;
        int l = 1;
        while (s + n * 9 * l < k) {
            s += n * 9 * l;
            n *= 10;
            l++;
        }

        k -= s;
        n += (k - 1) / l;
        for (int i = 0; i < l - 1 - (k - 1) % l; i++) {
            n /= 10;
        }
        cout << (n % 10) << '\n';
    }

    return 0;
}