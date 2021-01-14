#include "bits/stdc++.h"

using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int n; cin >> n;
    vector<int> pos(n + 1);
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        pos[x] = i;
    }
    pos[0] = n + 1;

    int rounds = 0;
    for (int p = 1; p <= n; p++) {
        rounds += pos[p] < pos[p - 1];
    }
    cout << rounds << '\n';

    return 0;
}