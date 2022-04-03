#include <bits/stdc++.h>
using namespace std;

/* Date: 2022-04-02
 * Source: Code Jam 2022 Qualification
 */

int main() {
    int tests;
    cin >> tests;

    for (int test = 1; test <= tests; test++) {
        int r, c;
        cin >> r >> c;

        cout << "Case #" << test << ":\n";
        for (int i = 0; i < 2 * r + 1; i++) {
            for (int j = 0; j < 2 * c + 1; j++) {
                if (i % 2 == 0) {
                    if (i == 0 && j < 2) cout << '.';
                    else if (j % 2 == 0) cout << '+';
                    else cout << '-';
                } else {
                    if ((i == 1 && j == 0) || j % 2 == 1) cout << '.';
                    else cout << '|';
                }
            }
            cout << '\n';
        }
    }
    
    return 0;
}