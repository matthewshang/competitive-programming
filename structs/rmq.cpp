template <typename T>
struct RMQ {
    vector<vector<T>> st;
    RMQ(vector<T>& v) {
        int k = 32 - __builtin_clz(sz(v) - 1);
        st.resize(sz(v), vector<T>(k));
        F0R (i, sz(v)) st[i][0] = v[i];
        FOR (j, 1, k + 1) 
            F0R (i, sz(v) - (1 << j) + 1)
                st[i][j] = min(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]);
    }

    T query(int l, int r) {
        int j = 31 - __builtin_clz(r - l); // equivalent to floor(log2(r-l+1))
        return min(st[l][j], st[r - (1 << j) + 1][j]);
    }
};