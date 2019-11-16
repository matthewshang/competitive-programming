#include "bits/stdc++.h"

using namespace std;

using ll = long long;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    string s; cin >> s;

    if (s.size() == 1) {
        int n = s[0] - '0';
        cout << ((n % 8) ? -1 : n) << endl;
        return 0;
    } else if (s.size() == 2) {
        int a = s[0] - '0', b = s[1] - '0';
        if (a > b) swap(a, b);
        if (a != 0) {
            int n = 10 * a + b;
            if (n % 8 == 0) {
                cout << n << endl;
                return 0;
            }
        }
        swap(a, b);
        int n = 10 * a + b;
        cout << ((n % 8) ? -1 : n) << endl;
        return 0;
    }

    array<int, 10> digit{};
    for (int i = 0; i < s.size(); i++)
        digit[s[i] - '0']++;

    int a = 0, b = 0, c = 0;
    const string INF = {(char)('9' + 1)};
    string ans = INF;
    while (100 * a + 10 * b + c < 1000) {
        array<int, 10> tmp = digit;
        tmp[a]--; tmp[b]--; tmp[c]--;
        if (!(tmp[a] < 0 || tmp[b] < 0 || tmp[c] < 0)) {
            string t = "";
            for (int d = 0; d < 10; d++)
                for (int i = 0; i < tmp[d]; i++)
                    t += (char)('0' + d);
            sort(t.begin(), t.end());
            t += (char)('0' + a);
            t += (char)('0' + b); 
            t += (char)('0' + c);

            if (t.size() && t[0] == '0') {
                int p = 0;
                while (p < t.size() && t[p] == '0') p++;
                t[0] = t[p]; t[p] = '0';
            }
            int l = t.size();
            int n = 100 * (t[l - 3] - '0') + 10 * (t[l - 2] - '0') + (t[l - 1] - '0');
            if (n % 8 == 0) ans = min(ans, t);
        }

        c += 8;
        if (c > 9) b++, c -= 10;
        if (b > 9) a++, b -= 10;
    }

    if (ans == INF) cout << "-1\n";
    else cout << ans << endl;

    return 0;
}
