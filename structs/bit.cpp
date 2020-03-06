// Operation must be reversible
struct BIT {
    vector<int> bit;
    int n;

    BIT(int n) {
        this->n = n + 1;
        bit.assign(n + 1, 0);
    }

    // 0 <= i < n
    int query(int i) {
        int ans = 0;
        for (++i; i > 0; i -= i & -i) ans += bit[i];
        return ans;
    }
    
    // inclusive [l, r]
    int query(int l, int r) {
        return query(r) - query(l - 1);
    }

    // 0 <= i < n
    void upd(int i, int val) {
        for (++i; i < n; i += i & -i) bit[i] += val;
    }
};
