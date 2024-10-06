#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int q;
    cin >> q;
    while (q--) {
        string s; cin >> s;
        int n = int(s.size());
        int k; cin >> k;

        if (k == 1) {
            cout << 0 << "\n";
        } else if (n == k) {
            int diff = 0;
            for (int i = 0; i < n / 2; i++) {
                diff += s[i] != s[n - 1 - i];
            }
            cout << diff << "\n";
        } else if (k % 2 == 0) {
            array<int, 26> count{};
            for (int i = 0; i < 26; i++) {
                count[i] = 0;
            }
            for (int i = 0; i < n; i++) {
                count[s[i] - 'a']++;
            }
            int most = 0;
            for (int i = 0; i < 26; i++) {
                if (count[i] > count[most]) {
                    most = i;
                }
            }
            cout << (n - count[most]) << '\n';
        } else {
            int best = n;
            for (char a = 'a'; a <= 'z'; a++) {
                for (char b = 'a'; b <= 'z'; b++) {
                    int cost = n;
                    for (int i = 0; i < n; i++) {
                        if (i % 2 == 0) {
                            cost -= a == s[i];
                        } else {
                            cost -= b == s[i];
                        }
                    }
                    if (cost < best) {
                        best = cost;
                    }
                }
            }
            cout << best << "\n";
        }
    }

    return 0;
}