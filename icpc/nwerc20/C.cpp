#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;
    int d, s;
    cin >> d >> s;
    int rem = n * d - k * s;
    if (rem < 0 || rem > 100 * (n - k)) {
        cout << "impossible" << '\n';
    } else {
        cout << fixed << setprecision(6);
        cout << (double(rem) / (n - k)) << '\n';
    }

    return 0;
}
