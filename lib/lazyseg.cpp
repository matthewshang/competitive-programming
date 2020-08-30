struct lazy_seg {
    int n;
    vector<ll> seg, lazy;
    lazy_seg(int n) : n(n), seg(4 * n), lazy(4 * n) {}
    void push(int v, int l, int r) {
        // seg[v] += (r - l + 1) * lazy[v];
        seg[v] += lazy[v];
        if (l != r) F0R (i, 2) {
            lazy[v * 2 + i] += lazy[v];
        }
        lazy[v] = 0;
    }
    void range_update(int lo, int hi, int inc, int v, int l, int r) {
        push(v, l, r);
        if (hi < l || lo > r) return;
        if (lo <= l && r <= hi) {
            lazy[v] += inc;
            push(v, l, r);
        } else {
            int m = (l + r) / 2;
            range_update(lo, hi, inc, v * 2, l, m);
            range_update(lo, hi, inc, v * 2 + 1, m + 1, r);
            seg[v] = min(seg[v * 2], seg[v * 2 + 1]);
        }
    }
    void range_update(int lo, int hi, int inc) {
        range_update(lo, hi, inc, 1, 0, n - 1);
    }
    int point_query(int pos, int v, int l, int r) {
        if (l == r) return seg[v];
        push(v, l, r);
        int m = (l + r) / 2;
        if (pos <= m)
            return point_query(pos, v * 2, l, m);
        else
            return point_query(pos, v * 2 + 1, m + 1, r);
    }
    int point_query(int pos) {
        return point_query(pos, 1, 0, n - 1);
    }
    ll range_query(int lo, int hi, int v, int l, int r) {
        push(v, l, r);
        if (hi < l || lo > r) return INF;
        if (lo <= l && r <= hi) return seg[v];
        int m = (l + r) / 2;
        return min(range_query(lo, hi, v * 2, l, m), range_query(lo, hi, v * 2 + 1, m + 1, r));
    }
    ll range_query(int lo, int hi) {
        return range_query(lo, hi, 1, 0, n - 1);
    }
};
