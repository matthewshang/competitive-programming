template<int size>
struct BIT {
    int n;
    int b[size + 1];

    BIT(int _n) : n(_n) {
        for (int i = 0; i < n + 1; ++i) b[i] = 0;
    }

    void update(int i, int v) {
        i++;
        for (; i <= n; i += i&-i)
            b[i] += v;
    }

    int query(int i) {
        i++;
        int s = 0;
        for (; i > 0; i -= i&-i)
            s += b[i];
        return s;
    }
};
