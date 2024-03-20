#include <bits/stdc++.h>
using namespace std;

const int64_t MOD = 1e9 + 7;
const int64_t MOD2 = 998244353;
const int64_t BASE = 1000003;
const int64_t BASE2 = 1000777;

int64_t modpow(int64_t a, int64_t b, int64_t mod) {
    int64_t x = 1, y = a;
    while (b > 0) {
        if (b % 2 == 1) x = x * y % mod;
        y = y * y % mod;
        b /= 2;
    }
    return x;
}

int64_t modsub(int64_t a, int64_t b, int64_t mod) {
    a = (a - b) % mod;
    if (a < 0) a += mod;
    return a;
}

struct segtree {
    int n;
    vector<array<int64_t, 2>> seg;

    segtree(int n) : n{n}, seg(4 * n) {}

    void build(const vector<int>& arr, int v, int l, int r) {
        if (l == r) {
            seg[v] = {modpow(BASE, arr[l], MOD), modpow(BASE2, arr[l], MOD2)};
        } else {
            int m = (l + r) / 2;
            build(arr, v * 2, l, m);
            build(arr, v * 2 + 1, m + 1, r);
            seg[v] = {(seg[v * 2][0] + seg[v * 2 + 1][0]) % MOD,
                      (seg[v * 2][1] + seg[v * 2 + 1][1]) % MOD};
        }
    }

    void build(const vector<int>& arr) {
        build(arr, 1, 0, n - 1);
    }

    array<int64_t, 2> query(int v, int l, int r, int lo, int hi) {
        if (r < lo || l > hi) {
            return {0, 0};
        }

        if (lo <= l && r <= hi) {
            return seg[v];
        }

        int m = (l + r) / 2;
        auto left = query(v * 2, l, m, lo, hi);
        auto right = query(v * 2 + 1, m + 1, r, lo, hi);
        return {(left[0] + right[0]) % MOD, (left[1] + right[1]) % MOD};
    }

    array<int64_t, 2> query(int lo, int hi) {
        return query(1, 0, n - 1, lo, hi);
    }

    void update(int v, int l, int r, int pos, int val) {
        if (l == r) {
            seg[v] = {modpow(BASE, val, MOD), modpow(BASE2, val, MOD2)};
        } else {
            int m = (l + r) / 2;
            if (pos <= m) update(v * 2, l, m, pos, val);
            else update(v * 2 + 1, m + 1, r, pos, val);
            seg[v] = {(seg[v * 2][0] + seg[v * 2 + 1][0]) % MOD,
                      (seg[v * 2][1] + seg[v * 2 + 1][1]) % MOD};
        }
    }

    void update(int pos, int val) {
        update(1, 0, n - 1, pos, val);
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    set<array<int64_t, 2>> single_powers;
    for (int p = 1; p <= 1e6; p++) {
        array<int64_t, 2> P = {modpow(BASE, p, MOD), modpow(BASE2, p, MOD2)};
        if (p <= 10) {
            // cout << "x^" << p << "=" << P[0] << ", " << P[1] << endl;
        }
        single_powers.insert(P);
    }

    int T;
    cin >> T;
    for (int tc = 1; tc <= T; tc++) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        segtree seg(n);
        seg.build(a);

        int q;
        cin >> q;
        int ans = 0;
        for (int qu = 1; qu <= q; qu++) {
            int type;
            cin >> type;
            if (type == 1) {
                int x, y;
                cin >> x >> y;
                seg.update(x - 1, y);
                a[x - 1] = y;
            } else {
                int l, r;
                cin >> l >> r;
                if ((r - l + 1) % 2 == 0) {
                    continue;
                }
                l--; r--;
                int mid = (l + r) / 2;
                auto try_split = [&](int m) -> bool {
                    if (l == r) return true;
                    if (m < l || m > r) return false;
                    auto left = seg.query(l, m);
                    auto right = seg.query(m + 1, r);
                    array<int64_t, 2> rl = {modsub(left[0], right[0], MOD), modsub(left[1], right[1], MOD2)};
                    array<int64_t, 2> lr = {modsub(right[0], left[0], MOD), modsub(right[1], left[1], MOD2)};
                    // cout << rl[0] << ", " << rl[1] << " or " << lr[0] << ", " << lr[1] << endl;
                    return single_powers.find(rl) != single_powers.end() ||
                           single_powers.find(lr) != single_powers.end();
                };
                // for (int i = l; i <= r; i++) {
                //     cout << a[i] << " ";
                // }
                // cout << endl;
                if (try_split(mid) || try_split(mid - 1)) {
                    // cout << "query " << qu << " is ok" << endl;
                    ans++;
                } else {
                    // cout << "query " << qu << " is bad" << endl;
                }
            }
        }
        cout << "Case #" << tc << ": " << ans << "\n";
    }

    return 0;
}