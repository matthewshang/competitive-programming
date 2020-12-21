#include "bits/stdc++.h"

using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);

    int n, q; cin >> n >> q;

    int l = ceil(log2(1e9));
    vector<vector<int>> down(n + 1, vector<int>(l + 1));
    for (int v = 1; v <= n; v++) {
        cin >> down[v][0];
    }
    
    for (int i = 1; i <= l; i++) {
        for (int v = 1; v <= n; v++) {
            down[v][i] = down[down[v][i - 1]][i - 1];
        }
    }

    while (q--) {
        int x, k; cin >> x >> k;
        for (int i = l; i >= 0; i--) {
            if (k & (1 << i)) {
                x = down[x][i];
                k ^= 1 << i;
            }
        }
        cout << x << '\n';
    }
}