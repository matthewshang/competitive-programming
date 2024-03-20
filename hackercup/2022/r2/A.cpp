#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    for (int tc = 1; tc <= T; tc++) {
        string s;
        cin >> s;
        int n = s.size();
        vector<array<int, 26>> pre(n + 1);
        for (int i = 0; i < n; i++) {
            pre[i + 1][s[i] - 'a']++;
            for (int j = 0; j < 26; j++) {
                pre[i + 1][j] += pre[i][j];
            }
        }

        int q;
        cin >> q;
        int ans = 0;
        while (q--) {
            int l, r;
            cin >> l >> r;
            if ((r - l + 1) % 2 == 0) continue;
            int mid = (l + r) / 2;

            auto try_split = [&](int m) -> bool {
                // cout << "split " << l << ", " << m << ", " << r << endl;
                auto left = pre[m];
                auto right = pre[r];
                for (int j = 0; j < 26; j++) {
                    left[j] -= pre[l - 1][j];
                    right[j] -= pre[m][j];
                }

                int uneq = 0;
                bool ok = true;
                for (int j = 0; j < 26; j++) {
                    int d = abs(left[j] - right[j]);
                    if (d > 1) {
                        // cout << (char('a' + j)) << " is " << d << endl;
                        ok = false;
                        break;
                    }
                    if (d == 1) {
                        uneq++;
                    }
                }
                ok &= uneq == 1;
                return ok;
            };
            bool ok = try_split(mid) || try_split(mid - 1);
            // cout << s.substr(l - 1, r - l + 1) << " is " << (ok) << endl; 
            ans += ok;
        }
        cout << "Case #" << tc << ": " << ans << "\n";
    }

    return 0;
}