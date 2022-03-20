#include <bits/stdc++.h>
using namespace std;

/* Date: 2022-03-19
 * Source: Kick Start Round A 2022
 * Notes: Greedy
 */

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int test_cases;
    cin >> test_cases;
    for (int test = 1; test <= test_cases; test++) {
        string s, t;
        cin >> s >> t;

        reverse(s.begin(), s.end());
        reverse(t.begin(), t.end());
        int rem = 0;
        while (!s.empty() && !t.empty()) {
            if (s.back() == t.back()) {
                s.pop_back();
                t.pop_back();
            } else {
                t.pop_back();
                rem++;
            }
        }

        if (!s.empty()) {
            cout << "Case #" << test << ": " << "IMPOSSIBLE" << "\n";
        } else {
            rem += t.size();
            cout << "Case #" << test << ": " << rem << "\n";
        }
    }

    return 0;
}