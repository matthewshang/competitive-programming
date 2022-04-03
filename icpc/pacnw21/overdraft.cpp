#include <bits/stdc++.h>
using namespace std;

/* Date: 2022-03-20
 * Source: PACNW 2022
 */

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    int balance = 0;
    int start = 0;
    for (int i = 0; i < n; i++) {
        int t;
        cin >> t;
        balance += t;
        start = max(start, -balance);
    }
    cout << start << "\n";

    return 0;
}