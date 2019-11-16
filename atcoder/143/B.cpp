#include "bits/stdc++.h"
 
using namespace std;
 
int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin >> n;
    vector<int> a(n); for (int& x : a) cin >> x;
    int ans = 0;
    for (int i = 1; i < n; i++)
        for (int j = 0; j < i; j++)
            ans += a[i] * a[j];
    cout << ans << endl;
    return 0;
}
