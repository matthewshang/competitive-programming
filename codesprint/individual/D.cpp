#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> c(n);
    for (int i = 0; i < n; i++) {
        cin >> c[i];
    }

    vector<vector<int>> rem(n);
    int pre = 0;
    for (int i = 0; i < n; i++) {
        pre = (pre + c[i]) % n;
        if (c[i] % n == 0) {
            cout << 1 << '\n';
            cout << (i + 1) << '\n';
            return 0;
        }
        if (pre == 0) {
            cout << (i + 1) << '\n';
            for (int j = 1; j <= i + 1; j++) {
                cout << j << ' ';
            }
            cout << '\n';
            return 0;
        }
        rem[pre].push_back(i + 1);
    }

    for (int i = 0; i < n; i++) {
        if (rem[i].size() >= 2) {
            int a = rem[i][0] + 1;
            int b = rem[i][1];
            cout << (b - a + 1) << '\n';
            for (int j = a; j <= b; j++) {
                cout << j << ' ';
            }
            cout << '\n';
            return 0;
        }
    }

    cout << -1 << '\n';

    return 0;
}
