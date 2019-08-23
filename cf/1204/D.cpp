#include "bits/stdc++.h"

using namespace std;

using ll = long long;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    string s; cin >> s;
    int n = s.size();
    vector<int> len, zero;
    int p = 0;
    while (p < n) {
        int q = p;
        int z = 0;
        bool done = false;
        while (q < n - 1 && s[q] <= s[q + 1]) {
            if (s[q] == '1') done = true;
            q++;
            if (!done) z++;
        }
        if (q >= n - 1 && s[n - 1] == '0') z++;

        len.push_back(q + 1 - p);
        zero.push_back(z);

        p = q + 1;
    }

//     for (int i = 0; i < len.size(); i++) {
//         cout << len[i] << ": " << zero[i] << endl;
//     }

    string ans = "";
    for (int i = 0; i < len.size(); i++) {
        int o = 0;
        int l = len[i];
        if (i < len.size() - 1) {
            o = max(0, min(zero[i + 1], l - 1));
        }
        for (int j = 0; j < l - o; j++)
            ans += '0';
        for (int j = 0; j < o; j++)
            ans += '1';
    }
    cout << ans << endl;

    return 0;
}
