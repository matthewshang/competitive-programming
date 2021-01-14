#include "bits/stdc++.h"

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m; cin >> n >> m;

    vector<int> seg(4 * (n + 1));
    function<void(int, int, int, int, int)> upd = [&](int v, int l, int r, int pos, int val) {
        if (l == r) {
            seg[v] += val;
        } else {
            int m = (l + r) / 2;
            if (pos <= m)
                upd(2 * v, l, m, pos, val);
            else
                upd(2 * v + 1, m + 1, r, pos, val);
            seg[v] = max(seg[2 * v], seg[2 * v + 1]);
        }
    };

    function<int(int, int, int, int)> find_first = [&](int v, int l, int r, int val) -> int {
        if (seg[v] < val) {
            return 0;
        } else if (l == r) {
            return l;
        } else {
            int m = (l + r) / 2;
            int pos = find_first(2 * v, l, m, val);
            if (pos > 0)
                return pos;
            return find_first(2 * v + 1, m + 1, r, val);
        }
    };

    for (int i = 1; i <= n; i++) {
        int h; cin >> h;
        upd(1, 1, n, i, h);
    }

    while (m--) {
        int r; cin >> r;
        int pos = find_first(1, 1, n, r);
        cout << pos << ' ';
        if (pos != 0)
            upd(1, 1, n, pos, -r);
    }
    cout << '\n';
}