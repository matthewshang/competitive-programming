#include "bits/stdc++.h"

using namespace std;

using ll = long long;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    int n, k; cin >> n >> k;

    if (k > n * n / 2) {
        cout << "0\n";
        return 0;
    }

    const ll MD = 1e9 + 7;
    ll dp[n + 1][n * n];
    dp[1][0] = 0;
    for (int i = 2; i <= n; i++) {
        for (int j = 0; j <= i * i / 2; j += 2) {

        }
    }


    vector<int> a;
    int C = n;
    for (int i = 1; i <= C; i++) a.push_back(i);
    do {
        int o = 0;
        for (int i = 1; i <= a.size(); i++) o += abs(i - a[i - 1]);
        for (int i : a) cout << i << " ";
        cout << ": " << o << ": ";
        for (int i = 1; i <= a.size(); i++) cout << abs(i - a[i - 1]) << " ";
        cout << endl;
    }
    while (next_permutation(a.begin(), a.end()));

    return 0;
}
