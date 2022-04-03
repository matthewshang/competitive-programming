#include <bits/stdc++.h>
using namespace std;

/* Date: 2022-03-20
 * Source: PACNW 2022
 */

int main() {
    int capacity, m;
    cin >> capacity >> m;
    vector<int> t(m);
    for (int i = 0; i < m; i++) {
        cin >> t[i];
    }

    vector<int> take(m);
    while (capacity > 0 && accumulate(t.begin(), t.end(), 0) > 0) {
        for (int i = 0; capacity > 0 && i < m; i++) {
            if (t[i] == 0) continue;
            t[i]--;
            take[i]++;
            capacity--;
        }
    }

    for (int i = 0; i < m; i++) {
        cout << take[i] << "\n";
    }
    return 0;
}