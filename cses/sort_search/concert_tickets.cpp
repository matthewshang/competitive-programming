#include "bits/stdc++.h"

using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    int n, m; cin >> n >> m;
    multiset<int> prices;
    for (int i = 0; i < n; i++) {
        int h; cin >> h;
        prices.insert(h);
    }

    for (int i = 0; i < m; i++) {
        int max_price; cin >> max_price;
        auto it = prices.upper_bound(max_price);
        if (it == prices.begin()) {
            cout << -1 << '\n';
        } else {
            it = prev(it);
            cout << *it << '\n';
            prices.erase(it);
        }
    }

    return 0;
}
