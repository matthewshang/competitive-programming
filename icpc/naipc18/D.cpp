#include <bits/stdc++.h>
using namespace std;

// Greedy, just take the smallest from sorted unused and ordered used.

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    vector<int> p(m);
    set<int> all;
    for (int i = 1; i <= n; i++) {
        all.insert(i);
    }
    for (int i = 0; i < m; i++) {
        cin >> p[i];
        all.erase(p[i]);
    }
    reverse(p.begin(), p.end());

    for (int i = 0; i < n; i++) {
        if (p.empty()) {
            cout << *all.begin() << '\n';
            all.erase(all.begin());
        } else if (all.empty()) {
            cout << p.back() << '\n';
            p.pop_back();
        } else {
            if (p.back() < *all.begin()) {
                cout << p.back() << '\n';
                p.pop_back();
            } else {
                cout << *all.begin() << '\n';
                all.erase(all.begin());
            }
        }
    }

    return 0;
}