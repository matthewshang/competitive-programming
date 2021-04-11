#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin >> n;
    vector<bool> seen(201);
    int mx = 0;
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        mx = max(mx, x);
        seen[x] = true;
    }

    if (mx == n) {
        cout << "good job\n";
    } else {
        for (int i = 1; i <= mx; i++) {
            if (!seen[i]) {
                cout << i << '\n';
            }
        }
    }

    return 0;
}