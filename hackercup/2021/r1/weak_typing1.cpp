#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int T;
    cin >>  T;
    for (int tc = 1; tc <= T; tc++) {
        int n;
        cin >> n;
        string w;
        cin >> w;

        int swi = 0;
        char cur = '?';
        for (char c : w) {
            if (c == 'F') continue;
            if (c != cur) swi++;
            cur = c;
        }
        cout << "Case #" << tc << ": " << max(0, swi - 1) << '\n';
    }

    return 0;
}