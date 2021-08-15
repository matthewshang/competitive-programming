#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    vector<int> b(n);
    vector<int> period(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i] >> b[i];
        period[i] = abs(a[i] - b[i]) * 2;
    }

    while (m--) {
        int x, y, t;
        cin >> x >> y >> t;

        int count = 0;
        for (int i = 0; i < n; i++) {
            int time = t % period[i];
            int pos;
            if (time < period[i] / 2) {
                if (a[i] < b[i]) {
                    pos = a[i] + time;
                } else {
                    pos = a[i] - time;
                }
            } else {
                time -= period[i] / 2;
                if (a[i] < b[i]) {
                    pos = b[i] - time;
                } else {
                    pos = b[i] + time;
                }
            }
            if (x <= pos && pos <= y) {
                count++;
            }
        }
        cout << count << '\n';
    }

    return 0;
}