#include "bits/stdc++.h"

using namespace std;

using ll = long long;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    int n; cin >> n;
    int score[4] = { 0, 3, 1, 2 };
    int max_s = score[n % 4];
    int max_a = 0;
    for (int a = 1; a <= 2; a++) {
        if (score[(n + a) % 4] > max_s) {
            max_s = score[(n + a) % 4];
            max_a = a;
        }
    }

    int mp[4] = { 3330, 2, 1 };
    cout << max_a << " " << (char)('A' + (mp[max_s])) << endl;

    return 0;
}
