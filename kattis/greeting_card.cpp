#include "bits/stdc++.h"
using namespace std;

/* Date: 2022-01-28
 * Source: NAQ 2017
 */

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<array<int, 2>> p(n);
    set<array<int, 2>> h;
    for (int i = 0; i < n; i++) {
        cin >> p[i][0] >> p[i][1];
        h.insert(p[i]);
    }

    int count = 0;
    for (int x = -2018; x <= 2018; x++) {
        for (int y = -2018; y <= 2018; y++) {
            if (x * x + y * y == 2018 * 2018) {
                for (int i = 0; i < n; i++) {
                    if (h.find({p[i][0] + x, p[i][1] + y}) != h.end()) {
                        count++;
                    }
                }
            }
        }
    }
    cout << (count / 2) << '\n';

    return 0;
}