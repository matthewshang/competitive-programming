#include <bits/stdc++.h>
using namespace std;

/* Date: 2022-03-20
 * Source: PACNW 2022
 */

int main() {
    int n, x, y;
    cin >> n >> x >> y;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        cout << (a * y / x) << "\n";
    }
    return 0;
}