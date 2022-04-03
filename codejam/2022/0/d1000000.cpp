#include <bits/stdc++.h>
using namespace std;

/* Date: 2022-04-02
 * Source: Code Jam 2022 Qualification
 * Notes: Find the longest straight starting from 1 since a straight starting 
 * later can just be moved down.
 */

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tests;
    cin >> tests;
    
    for (int test = 1; test <= tests; test++) {
        int n;
        cin >> n;

        map<int, int> count;
        for (int i = 0; i < n; i++) {
            int s;
            cin >> s;
            count[s]++;
        }

        int balance = n;
        int length = 0;
        while (balance > 0) {
            length++;
            balance--;
            if (--count.begin()->second == 0) {
                count.erase(count.begin());
            }
            balance -= count[length];
            count.erase(length);
        }

        cout << "Case #" << test << ": " << length << "\n";
    }

    return 0;
}