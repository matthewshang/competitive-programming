template <typename T>
struct RMQ {
    vector<vector<T>> st;

    RMQ(const vector<T>& v) {
        build(v);
    }

    void build(const vector<T>& v) {
        const int t = __lg(v.size());
        st.resize(t + 1);
        st[0].resize(v.size());
        for (int i = 0; i < int(v.size()); i++)
            st[0][i] = v[i];
        for (int l = 0; l < t; l++) {
            int m = int(v.size()) - (1 << (l + 1)) + 1;
            st[l + 1].resize(m);
            for (int i = 0; i < m; i++)
                st[l + 1][i] = max(st[l][i], st[l][i + (1 << l)]);
        }
    }

    T query(int l, int r) { // [l, r]
        int t = __lg(r - l + 1);
        return max(st[t][l], st[t][r - (1 << t) + 1]);
    }
};