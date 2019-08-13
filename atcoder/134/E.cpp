#include "bits/stdc++.h"

using namespace std;

using ll = long long;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    int n; cin >> n;
    vector<int> a(n); for (int& x : a) cin >> x;

    multiset<int> s;
    s.insert(-INT_MAX);
    for (int i = 0; i < n; i++) {
        auto it = s.lower_bound(a[i]);
        if (it == s.begin()) {
            s.insert(a[i]);
        } else {
            it--;
            s.erase(it);
            s.insert(a[i]);
        }
    }
    cout << s.size() << endl;

    return 0;
}
