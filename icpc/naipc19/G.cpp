#include <bits/stdc++.h>
using namespace std;

// Do some standard sweep lazy segtree stuff.

struct event {
    int x, y1, y2;
    bool open;

    bool operator<(const event& e) const {
        return x < e.x;
    }
};

struct lazy_seg {
    int n;
    vector<int> seg, lazy;
    lazy_seg(int n) : n(n), seg(4 * n), lazy(4 * n) {}
    void push(int v) {
        seg[v * 2] += lazy[v];
        lazy[v * 2] += lazy[v];
        seg[v * 2 + 1] += lazy[v];
        lazy[v * 2 + 1] += lazy[v];
        lazy[v] = 0;
    }
    void range_update(int lo, int hi, int inc, int v, int l, int r) {
        if (hi < l || lo > r) return;
        if (lo <= l && r <= hi) {
            seg[v] += inc;
            lazy[v] += inc;
        } else {
            push(v);
            int m = (l + r) / 2;
            range_update(lo, hi, inc, v * 2, l, m);
            range_update(lo, hi, inc, v * 2 + 1, m + 1, r);
            seg[v] = max(seg[v * 2], seg[v * 2 + 1]);
        }
    }
    void range_update(int lo, int hi, int inc) {
        range_update(lo, hi, inc, 1, 0, n - 1);
    }
    int range_query(int lo, int hi, int v, int l, int r) {
        if (hi < l || lo > r) return 0;
        if (lo <= l && r <= hi) return seg[v];
        push(v);
        int m = (l + r) / 2;
        return max(range_query(lo, hi, v * 2, l, m), range_query(lo, hi, v * 2 + 1, m + 1, r));
    }
    int range_query(int lo, int hi) {
        return range_query(lo, hi, 1, 0, n - 1);
    }
};


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    auto ans = [](int x) {
        cout << x << '\n';
        exit(0);
    };

    int n;
    cin >> n;
    vector<event> evs;
    vector<int> cmp;
    for (int i = 0; i < n; i++) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        cmp.push_back(y1);
        cmp.push_back(y2);
        evs.push_back({ x1, y1, y2, true });
        evs.push_back({ x2, y1, y2, false });
    }
    sort(cmp.begin(), cmp.end());
    for (auto& e : evs) {
        e.y1 = lower_bound(cmp.begin(), cmp.end(), e.y1) - cmp.begin();
        e.y2 = lower_bound(cmp.begin(), cmp.end(), e.y2) - cmp.begin();
    }

    lazy_seg seg(2 * n);
    sort(evs.begin(), evs.end());
    for (const auto& e : evs) {
        if (e.open) {
            if (seg.range_query(e.y1, e.y2) > 0) {
                ans(1);
            }
            seg.range_update(e.y1, e.y1, 1);
            seg.range_update(e.y2, e.y2, 1);
        } else {
            seg.range_update(e.y1, e.y1, -1);
            seg.range_update(e.y2, e.y2, -1);
            if (seg.range_query(e.y1, e.y2) > 0) {
                ans(1);
            }
        }
    }
    ans(0);

    return 0;
}