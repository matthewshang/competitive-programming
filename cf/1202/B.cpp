#include "bits/stdc++.h"

using namespace std;

using ll = long long;

int find(int x, int y, int d) {
    int ans = 100;
    for (int a = 0; a < 10; a++) {
        for (int b = 0; b < 10; b++) {
            if (d == 0 && b == 0 && a == 0) continue;
            if ((a * x + b * y) % 10 == (d + 10) % 10) {
                ans = min(ans, a + b);
            }
        }
    }
    return (ans == 100) ? -1 : ans;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    int pre[10][10][10];
    for (int x = 0; x < 10; x++) {
        for (int y = 0; y < 10; y++) {
            for (int d = 0; d < 10; d++) {
                pre[x][y][d] = find(x, y, d);
            }
        }
    }

    string s; cin >> s;
    int cnt[10];
    for (int i = 0; i < 10; i++) cnt[i] = 0;
    for (int i = 0; i < s.size() - 1; i++) {
        int d = (s[i + 1] - '0') - (s[i] - '0');
        d = (d + 10) % 10;
        cnt[d]++;
    }

    for (int x = 0; x < 10; x++) {
        for (int y = 0; y < 10; y++) {
            int val = 0;
            bool bad = false;
            for (int d = 0; d < 10; d++) {
                if (cnt[d] == 0) continue;
                int res = pre[x][y][d];
                if (res == -1) bad = true;
                val += cnt[d] * (res - 1);
            }
            
            if (bad) cout << "-1 ";
            else cout << val << " ";
        }
        cout << endl;
    }

    return 0;
}
