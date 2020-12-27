#include "bits/stdc++.h"

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k; cin >> n >> k;

    multiset<int> low, high;
    long long low_sum = 0;
    long long high_sum = 0;

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
            low_sum += *it;
            high_sum -= *it;
            low.insert(*it);
            high.erase(it);
        }
        while (low.size() > high.size() + 1) {
            auto it = prev(low.end());
            low_sum -= *it;
            high_sum += *it;
            high.insert(*it);
            low.erase(it);
        }
    };

    auto insert = [&](int x) {
        if (x <= median()) {
            low.insert(x);
            low_sum += x;
        } else {
            high.insert(x);
            high_sum += x;
        }
    };

    auto erase = [&](int x) {
        if (x <= median()) {
            low.erase(low.find(x));
            low_sum -= x;
        } else {
            high.erase(high.find(x));
            high_sum -= x;
        }
    };

    auto cost = [&]() -> long long {
        long long m = median();
        return m * (long long)low.size() - low_sum + high_sum - m * (long long)high.size();
    };

    vector<int> x(n);
    for (int i = 0; i < n; i++) {
        cin >> x[i];
    }

    for (int i = 0; i < k; i++) {
        insert(x[i]);
    }
    bal();
    cout << cost() << ' ';

    for (int i = 0; i < n - k; i++) {
        insert(x[k + i]);
        erase(x[i]);
        bal();
        cout << cost() << ' ';
    }
    cout << '\n';
}
