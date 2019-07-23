#include "bits/stdc++.h"
 
using namespace std;
 
int main() {
    int n; cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
 
    sort(a.begin(), a.end());
    for (int i = n - 1; i >= 0; i--) {
        int u = (i + 1) % n;
        int v = (i - 1 + n) % n;
        if (a[u] + a[v] > a[i]) {
            cout << "YES\n";
            for (int x : a) cout << x << " ";
            return 0;
        }
        int tmp = a[i];
        a[i] = a[v];
        a[v] = tmp;
    }
    cout << "NO\n";
    return 0;
}
