#include <bits/stdc++.h>
using namespace std;

const int64_t INF = 1e15;
struct node {
    int64_t pre, suf, sum, msa;
    node() {
        pre = suf = sum = msa = -INF;
    }
};

struct segtree {
    int n;
    vector<node> seg;

    segtree(int n) : n{n}, seg(4 * n) {}

    void build(const vector<int>& arr, int v, int l, int r) {
        if (l == r) {
            seg[v].sum = arr[l];
            seg[v].pre = arr[l];
            seg[v].suf = arr[l];
            seg[v].msa = arr[l];
        } else {
            int m = (l + r) / 2;
            build(arr, v * 2, l, m);
            build(arr, v * 2 + 1, m + 1, r);
            seg[v] = merge(seg[v * 2], seg[v * 2 + 1]);
        }
    }

    void build(const vector<int>& arr) {
        build(arr, 1, 0, n - 1);
    }

    node merge(node l, node r) {
        node d;
        d.pre = max(l.pre, l.sum + r.pre);
        d.suf = max(r.suf, r.sum + l.suf);
        d.sum = l.sum + r.sum;
        d.msa = max({ l.msa, r.msa, l.suf + r.pre });
        return d;
    }

    node query(int v, int l, int r, int lo, int hi) {
        if (r < lo || l > hi) {
            return node();
        }

        if (lo <= l && r <= hi) {
            return seg[v];
        }

        int m = (l + r) / 2;
        node left = query(v * 2, l, m, lo, hi);
        node right = query(v * 2 + 1, m + 1, r, lo, hi);
        return merge(left, right);
    }

    int64_t query(int lo, int hi) {
        return query(1, 0, n - 1, lo, hi).msa;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin >> n;
    vector<int> v(n);
    vector<int> d(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i] >> d[i];
    }

    vector<segtree> east(7, segtree(n - 1));
    vector<segtree> west(7, segtree(n - 1));
    for (int day = 0; day < 7; day++) {
        vector<int> val(n);
        for (int i = 0; i < n; i++) {
            val[i] = v[i];
            int j = (i + day) % 7;
            if (j == 1 || j == 5) {
                val[i] += d[i];
            } else if (j == 2 || j == 4) {
                val[i] += 2 * d[i];
            } else if (j == 3) {
                val[i] += 3 * d[i];
            }
        }
        vector<int> dif(n - 1);
        for (int i = 1; i < n; i++) {
            dif[i - 1] = val[i] - val[i - 1];
        }
        east[day].build(dif);

        for (int i = n - 1; i >= 0; i--) {
            val[i] = v[i];
            int j = (n - 1 - i + day) % 7;
            if (j == 1 || j == 5) {
                val[i] += d[i];
            } else if (j == 2 || j == 4) {
                val[i] += 2 * d[i];
            } else if (j == 3) {
                val[i] += 3 * d[i];
            }
        }
        for (int i = 1; i < n; i++) {
            dif[i - 1] = val[i - 1] - val[i];
        }
        west[day].build(dif);
    } 

    int q; cin >> q;
    while (q--) {
        int s, t; cin >> s >> t;
        s--; t--;
        int64_t max_dif;
        if (s < t) {
            int day = (7 - s % 7) % 7;
            max_dif = east[day].query(s, t - 1);
        } else {
            int day = (7 - (n - 1 - s) % 7) % 7;
            max_dif = west[day].query(t, s - 1);
        }
        cout << max(int64_t(0), max_dif) << '\n';
    }

    return 0;
}