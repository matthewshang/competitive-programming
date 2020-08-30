struct BIT { // Operation must be reversible
    vector<ll> bit;
    BIT(int n) : bit(n) {}
    ll query(int pos) { // sum from [0, pos]
        ll ans = 0;
        for (pos++; pos > 0; pos &= pos - 1) ans += bit[pos - 1];
        return ans;
    }
    ll query(int l, int r) { // sum from [l, r]
        return query(r) - query(l - 1);
    }
    void update(int pos, int delta) { // a[pos] += delta; 
        for (; pos < sz(bit); pos |= pos + 1) bit[pos] += delta;
    }
};
