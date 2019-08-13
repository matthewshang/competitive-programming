#include "bits/stdc++.h"

using namespace std;

using ll = long long;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    int n; cin >> n;
    vector<int> a(n + 1); 
    for (int i = 1; i <= n; i++) cin >> a[i];

    vector<int> b(n + 1, -1);
    for (int i = n; i > n / 2; i--) {
        b[i] = a[i];
    }

    for (int i = n / 2; i >= 1; i--) {
        int par = 0;
        for (int j = 2 * i; j <= n; j += i) {
            par += b[j];
        }
        b[i] = (a[i] + 2 - par % 2) % 2;
    }

    int m = 0;
    for (int i = 1; i <= n; i++) m += b[i];
    cout << m << endl;
    for (int i = 1; i <= n; i++)
        if (b[i] % 2 == 1) cout << i << " ";
    cout << endl;

    return 0;
}
