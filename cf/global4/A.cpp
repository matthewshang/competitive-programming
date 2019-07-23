#include "bits/stdc++.h"

using namespace std;

using ll = long long;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    int n; cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    int tot = 0, ali = a[0];
    for (int x : a) tot += x;
    vector<int> c;
    c.push_back(0);

    int i = 1;
    while (i < n) {
        if (ali > tot - ali) break;
        if (a[0] >= a[i] * 2) {
            c.push_back(i); ali += a[i];
        }
        i++;
    }

    if (ali <= tot - ali) {
        cout << 0 << endl;
    } else {
        cout << c.size() << endl;
        for (int x : c) cout << x + 1 << " ";
        cout << endl;
    }

    return 0;
}
