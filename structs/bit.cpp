// Source: KACTL
struct BIT { // Operation must be reversible
    vector<ll> bit;
    BIT(int n) : bit(n) {}
    ll query(int pos) { // pos in [0, n)
        ll ans = 0;
        for (; pos > 0; pos &= pos - 1) ans += bit[pos - 1];
        return ans;
    }
    ll query(int l, int r) { // [l, r]
        return query(r + 1) - query(l);
    }
    void update(int pos, int delta) { // pos in [0, n); 
        for (; pos < sz(bit); pos |= pos + 1) bit[pos] += delta;
    }
};