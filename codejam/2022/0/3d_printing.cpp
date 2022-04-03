#include <bits/stdc++.h>
using namespace std;

/* Date: 2022-04-02
 * Source: Code Jam 2022 Qualification
 */

const int TARGET_INK = 1000000;

int main() {
    int tests;
    cin >> tests;

    for (int test = 1; test <= tests; test++) {
        array<int, 4> min_ink{};
        fill(min_ink.begin(), min_ink.end(), TARGET_INK);
        for (int p = 0; p < 3; p++) {
            for (int c = 0; c < 4; c++) {
                int ink;
                cin >> ink;
                min_ink[c] = min(min_ink[c], ink);
            }
        }
        
        cout << "Case #" << test << ":";
        int sum = accumulate(min_ink.begin(), min_ink.end(), 0);
        if (sum < TARGET_INK) {
            cout << " IMPOSSIBLE";
        } else {
            int surplus = sum - TARGET_INK;
            for (int c = 0; c < 4; c++) {
                int sub = min(min_ink[c], surplus);
                min_ink[c] -= sub;
                surplus -= sub;
                cout << " " << min_ink[c];
            }
        }
        cout << "\n";
    }
    
    return 0;
}