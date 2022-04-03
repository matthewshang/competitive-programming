#include <bits/stdc++.h>
using namespace std;

/* Date: 2022-03-20
 * Source: PACNW 2022
 */

int main() {
    string s, t;
    cin >> s >> t;

    int count = 1;
    for (int i = 0; i < 4; i++) {
        if (s[i] != t[i]) {
            count *= 2;
        }
    }
    cout << count << "\n";
    
    return 0;
}