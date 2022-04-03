#include <bits/stdc++.h>
using namespace std;

/* Date: 2022-03-20
 * Source: PACNW 2022
 * Notes: Try all 7 positions to cut of the first group.
 */

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        int n = s.size();

        bool any = false;
        for (int pre = 0; pre <= min(6, n); pre++) {
            set<char> seen;
            for (int i = 0; i < pre; i++) {
                seen.insert(s[i]);
            }
            if ((int)seen.size() != pre) {
                continue;
            }

            bool ok = true;
            for (int i = pre; i < n; i += 7) {
                seen.clear();
                int len = min(7, n - i);
                for (int j = 0; j < len; j++) {
                    seen.insert(s[i + j]);
                }
                if ((int)seen.size() != len) {
                    ok = false;
                }
            }
            any |= ok;
        }
        cout << any << "\n";
    }

    return 0;
}