#include "bits/stdc++.h"

using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);

    int n; cin >> n;
    long long x; cin >> x;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    map<long long, pair<int, int>> pos;
    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            pos[a[i] + a[j]] = { i, j };
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            long long sum = a[i] + a[j];
            auto it = pos.find(x - sum);
            if (it != pos.end()) {
                auto p = it->second;
                if (p.first != i && p.first != j && p.second != i && p.second != j) {
                    cout << i << " " << j << " " << p.first << " " << p.second << '\n';
                    return 0;
                }
            }
        }
    }

    cout << "IMPOSSIBLE" << '\n';
    return 0;
}