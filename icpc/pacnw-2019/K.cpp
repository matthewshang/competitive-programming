#include "bits/stdc++.h"

using namespace std;

using u8 = unsigned char;

struct node {
    int l = -1, r = -1;
    u8 val, lazy;

    void increase(u8 x) {
        lazy += x;
    }

    u8 get() {
        return val + lazy;
    }
};

static const int MAX_NODES = 1e7;
static node d[MAX_NODES];
int nex = 0;

struct persistent_segtree {

    vector<int> versions;
    int n;

    persistent_segtree(int n) : n{n} {}

    int copy(int id) {
        d[nex] = d[id];
        return nex++;
    }

    u8 query(int id, int pos, int L, int R) {
        if (L == R) return d[id].get();
        int M = (L + R) / 2;
        if (pos <= M) {
            return d[id].lazy + query(d[id].l, pos, L, M);
        } else {
            return d[id].lazy + query(d[id].r, pos, M + 1, R);
        }
    }

    int update(int id, int lo, int hi, u8 v, int L, int R) {
        if (R < lo || hi < L) return id;
        int x = copy(id);
        if (lo <= L && R <= hi) {
            d[x].increase(v);
            return x;
        }

        int M = (L + R) / 2;
        d[x].l = update(d[x].l, lo, hi, v, L, M);
        d[x].r = update(d[x].r, lo, hi, v, M + 1, R);
        return x;
    }

    int build(const vector<u8>& ar, int L, int R) {
        int id = nex++;
        if (L == R) {
            if (L < int(ar.size())) {
                d[id].val = ar[L];
            }
            return id;
        }
        int M = (L + R) / 2;
        d[id].l = build(ar, L, M);
        d[id].r = build(ar, M + 1, R);
        return id;
    }

    int current_version() {
        return versions.size() - 1;
    }

    void update(int lo, int hi, u8 v) {
        versions.push_back(update(versions.back(), lo, hi, v, 0, n - 1));
    }

    u8 query(int time, int pos) {
        return query(versions[time], pos, 0, n - 1);
    }

    void build(const vector<u8>& ar) {
        versions.push_back(build(ar, 0, n - 1));
    }
};

struct entry {
    int data;
    int pos;
    int time;
};

struct cache {
    int n;
    vector<entry> seg;
    vector<bool> lazy;

    cache(int n) : n{n}, seg(n * 4), lazy(n * 4) {}

    void push(int v, int l, int r) {
        if (lazy[v]) {
            if (l != r) {
                lazy[v * 2] = lazy[v * 2 + 1] = true;
                seg[v * 2] = seg[v * 2 + 1] = seg[v];
            }
            lazy[v] = false;
        }
    }

    void load(entry e, int lo, int hi) {
        load(e, lo, hi, 1, 0, n - 1);
    }

    void load(entry e, int lo, int hi, int v, int l, int r) {
        if (r < lo || hi < l) return;
        if (lo <= l && r <= hi) {
            lazy[v] = true;
            seg[v] = e;
        } else {
            push(v, l, r);
            int m = (l + r) / 2;
            load(e, lo, hi, v * 2, l, m);
            load(e, lo, hi, v * 2 + 1, m + 1, r);
        }
    }

    entry get(int pos) {
        return get(pos, 1, 0, n - 1);
    }

    entry get(int pos, int v, int l, int r) {
        if (l == r) {
            return { seg[v].data, l - seg[v].pos, seg[v].time };
        } else {
            push(v, l, r);
            int m = (l + r) / 2;
            if (pos <= m) {
                return get(pos, v * 2, l, m);
            } else {
                return get(pos, v * 2 + 1, m + 1, r);
            }
        }
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, q; cin >> n >> m >> q;

    vector<persistent_segtree> data;
    for (int i = 0; i < m; i++) {
        int s; cin >> s;
        vector<u8> ar(s);
        for (int j = 0; j < s; j++) {
            int v; cin >> v;
            ar[j] = (u8)v;
        }
        data.emplace_back(s);
        data.back().build(ar);
    }

    cache cac(n);
    cac.load({ -1, 0, 0 }, 0, n - 1);
    while (q--) {
        int type; cin >> type;
        if (type == 1) {
            int i, p; cin >> i >> p;
            i--; p--;
            cac.load({ i, p, data[i].current_version() }, p, p + data[i].n - 1);

        } else if (type == 2) {
            int p; cin >> p;
            entry e = cac.get(p - 1);
            if (e.data == -1) {
                cout << 0 << '\n';
            } else {
                int b = data[e.data].query(e.time, e.pos);
                cout << b << '\n';
            }

        } else {
            int i, l, r; cin >> i >> l >> r;
            i--; l--; r--;
            data[i].update(l, r, 1);
        }
    }

    return 0;
}