#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<array<int, 2>> moves;
    function<void(int, int, int, int)> go = [&](int d, int l, int m, int r) {
        if (d > 1) go(d - 1, l, r, m);
        moves.push_back({l, r});
        if (d > 1) go(d - 1, m, l, r);
    };
    go(n, 1, 2, 3);

    cout << moves.size() << '\n';
    for (auto [a, b] : moves) {
        cout << a << " " << b << '\n';
    }

    return 0;
}