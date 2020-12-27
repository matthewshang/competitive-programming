#include "bits/stdc++.h"

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k; cin >> n >> k;

    multiset<int> low, high;
    auto median = [&]() -> int {
        if (low.size() == 0) {
            return 0;
        } else {
            return *low.rbegin();
        }
    };

    auto bal = [&]() {
        while (low.size() < high.size()) {
            auto it = high.begin();
            low.insert(*it);
            high.erase(it);
        }
        while (low.size() > high.size() + 1) {
            auto it = prev(low.end());
            high.insert(*it);
            low.erase(it);
        }
    };

    auto insert = [&](int x) {
        if (x <= median()) {
            low.insert(x);
        } else {
            high.insert(x);
        }
    };

    auto erase = [&](int x) {
        if (x <= median()) {
            low.erase(low.find(x));
        } else {
            high.erase(high.find(x));
        }
    };

    vector<int> x(n);
    for (int i = 0; i < n; i++) {
        cin >> x[i];
    }

    for (int i = 0; i < k; i++) {
        insert(x[i]);
    }
    bal();
    cout << median() << ' ';

    for (int i = 0; i < n - k; i++) {
        insert(x[k + i]);
        erase(x[i]);
        bal();
        cout << median() << ' ';
    }
    cout << '\n';
}