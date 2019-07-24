#include "bits/stdc++.h"

using namespace std;

using ll = long long;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    int n, k; cin >> n >> k;
    vector<int> cnt(k, 0);
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        cnt[x - 1]++;
    }

    int odd = 0;
    for (int i = 0; i < k; i++) {
        odd += cnt[i] % 2;
    }

    cout << n - odd / 2 << endl;
    return 0;
}
