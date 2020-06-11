template <typename T>
struct RMQ {
    vector<vector<T>> st;
    void build(vector<T>& v) {
        int t = __lg(sz(v));
        st.resize(t + 1);
        st[0].resize(sz(v));
        F0R (i, sz(v)) st[0][i] = v[i];
        F0R (l, t) {
            int m = sz(v) - (1 << (l + 1)) + 1;
            st[l + 1].resize(m);
            F0R (i, m) st[l + 1][i] = min(st[l][i], st[l][i + (1 << l)]);
        }
    }
    T query(int l, int r) { // [l, r]
        int t = __lg(r - l + 1);
        return min(st[t][l], st[t][r - (1 << t) + 1]);
    }
};