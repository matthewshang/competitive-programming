struct BIT { // Operation must be reversible
    vector<int> bit; int n;
    BIT(int n) { this->n = n + 1; bit.assign(n + 1, 0); } 
    int query(int i) { // [0, n)
        int ans = 0;
        for (++i; i > 0; i -= i & -i) ans += bit[i];
        return ans;
    }
    int query(int l, int r) { // [l, r]
        return query(r) - query(l - 1);
    }
    void update(int i, int val) { // [0, n)
        for (++i; i < n; i += i & -i) bit[i] += val;
    }
};
