struct fenwick {
    vector<int64_t> a;
    fenwick(int n) : a(n) {}
    int64_t query(int pos) {
        int64_t ans = 0;
        for (pos++; pos > 0; pos &= pos - 1) ans += a[pos - 1];
        return ans;
    }
    int64_t query(int l, int r) {
        return query(r) - query(l - 1);
    }
    void update(int pos, int delta) {
        for (; pos < (int)a.size(); pos |= pos + 1) a[pos] += delta;
    }
};
