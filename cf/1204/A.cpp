#include "bits/stdc++.h"

using namespace std;

using ll = long long;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    string s; cin >> s;
    int e = s.size() - 1;
    int ones = 0;
    for (int i = 0; i < s.size(); i++)
        if (s[i] == '1') ones++;

    if (e % 2 == 0) {
        cout << ((ones > 1) ? (e / 2 + 1) : (e / 2)) << endl;
    } else {
        cout << e / 2 + 1 << endl;
    }

    return 0;
}
