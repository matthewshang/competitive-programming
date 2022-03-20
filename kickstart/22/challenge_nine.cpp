#include <bits/stdc++.h>
using namespace std;

/* Date: 2022-03-19
 * Source: Kick Start Round A 2022
 * Notes: Insert right before first larger digit.
 */

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int cases;
    cin >> cases;
    for (int test = 1; test <= cases; test++) {
        string s;
        cin >> s;
        int n = s.size();

        int sum = 0;
        for (char d : s) {
            sum += (d - '0');
        }
        int need = (9 - (sum % 9)) % 9;
        char add = '0' + need;
        if (add == '0') {
            s.insert(1, "0");
        } else {
            bool added = false;
            for (int i = 0; i < n; i++) {
                if (s[i] > add) {
                    s.insert(i, 1, add);
                    added = true;
                    break;
                }
            } 
            if (!added) {
                s += add;
            }
        }
        
        cout << "Case #" << test << ": " << s << "\n";
    }

    return 0;
}