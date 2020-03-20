// Source: Based on KACTL and bqi343
template <typename T>
struct Seg {
    const T ID = 0;
    T f(T a, T b) { return a + b; } // f should be associative
    vector<T> seg; int n;
    Seg(int _n) { n = _n; seg.assign(2 * n, ID); }
    void update(int pos, T val) {
        seg[pos += n] = val;
        for (pos /= 2; pos; pos /= 2) 
            seg[pos] = f(seg[2 * pos], seg[2 * pos + 1]);
    }
    T query(int l, int r) { // interval [l, r]
        T ra = ID, rb = ID;
        for (l += n, r += n + 1; l < r; l /= 2, r /= 2) {
            if (l & 1) ra = f(ra, seg[l++]);
            if (r & 1) rb = f(seg[--r], rb);
        }
        return f(ra, rb);
    }
};