#include <bits/stdc++.h>
using namespace std;

constexpr int64_t INF = 1e15;

struct node {
    int64_t sum, pre, suf, sas;
    node() : sum{0}, pre{0}, suf{0}, sas{0} {}
    explicit node(int64_t x) : sum{x}, pre{max((int64_t)0, x)}, suf{pre}, sas{pre} {}
};

struct segtree {
    int n;
    vector<node> seg;

    segtree(const vector<int>& a) : n(a.size()), seg(4 * n) {
        build(a, 1, 0, n - 1);
    }

    void build(const vector<int>& a, int v, int l, int r) {
        if (l == r) {
            seg[v] = node(a[l]);
        } else {
            int m = (l + r) / 2;
            build(a, v * 2, l, m);
            build(a, v * 2 + 1, m + 1, r);
            seg[v] = merge(seg[v * 2], seg[v * 2 + 1]);
        }
    }

    node merge(const node& l, const node& r) {
        node res;
        res.sum = l.sum + r.sum;
        res.pre = max(l.pre, l.sum + r.pre);
        res.suf = max(r.suf, r.sum + l.suf);
        res.sas = max({ l.sas, r.sas, l.suf + r.pre });
        return res;
    }

    void update(int pos, int val, int v, int l, int r) {
        if (l == r) {
            seg[v] = node(val);
            return;
        }

        int m = (l + r) / 2;
        if (pos <= m) {
            update(pos, val, v * 2, l, m);
        } else {
            update(pos, val, v * 2 + 1, m + 1, r);
        }
        seg[v] = merge(seg[v * 2], seg[v * 2 + 1]);
    }

    void update(int pos, int val) {
        update(pos, val, 1, 0, n - 1);
    }

    node query(int lo, int hi, int v, int l, int r) {
        if (r < lo || hi < l) {
            return node();
        }
        if (lo <= l && r <= hi) {
            return seg[v];
        }
        int m = (l + r) / 2;
        node left = query(lo, hi, v * 2, l, m);
        node right = query(lo, hi, v * 2 + 1, m + 1, r);
        return merge(left, right);
    }

    int64_t query(int lo, int hi) {
        return query(lo, hi, 1, 0, n - 1).sas;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    segtree seg(a);
    while (q--) {
        int k, x;
        cin >> k >> x;
        seg.update(k - 1, x);
        cout << seg.query(0, n - 1) << '\n';
    }

    return 0;
}