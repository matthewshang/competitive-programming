#include "bits/stdc++.h"
using namespace std;

/* Date: 2022-01-28
 * Source: NAQ 2017
 */

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    while (n--) {
        int g;
        cin >> g;
        vector<int> p(g);
        for (int i = 0; i < g; i++) {
            cin >> p[i];
        }
        vector<int> s = p;
        sort(s.begin(), s.end());
        map<int, int> rev;
        for (int i = 0; i < g; i++) {
            rev[s[i]] = i;
        }

        for (int i = 1; i < g - 1; i++) {
            if (rev[p[i - 1]] + 1 != rev[p[i]] && rev[p[i]] + 1 != rev[p[i + 1]]) {
                cout << (i + 1) << '\n';
                break;
            }
        }
    }

    return 0;
}