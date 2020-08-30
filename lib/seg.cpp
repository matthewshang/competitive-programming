// Source: cp-algorithms
struct Seg {
    int n;
    vector<ll> seg;
    Seg(int n) : n(n), seg(4 * n) {}
    void update(int pos, int val, int idx, int L, int R) {
        if (L == R) {
            seg[idx] = val;
        } else {
            int M = (L + R) / 2;
            if (pos <= M)
                update(pos, val, idx * 2, L, M);
            else
                update(pos, val, idx * 2 + 1, M + 1, R);
            seg[idx] = seg[idx * 2] + seg[idx * 2 + 1];
        }
    }
    void update(int pos, int val) {
        update(pos, val, 1, 0, n - 1);
    }
    ll query(int lo, int hi, int idx, int L, int R) {
        if (lo > hi) return 0;
        if (L == lo && hi == R) return seg[idx];
        int M = (L + R) / 2;
        return query(lo, min(hi, M), idx * 2, L, M) + 
               query(max(lo, M + 1), hi, idx * 2 + 1, M + 1, R);
    }
    ll query(int lo, int hi) {
        return query(lo, hi, 1, 0, n - 1);
    }
};
