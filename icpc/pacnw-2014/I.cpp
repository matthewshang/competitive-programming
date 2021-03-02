#include "bits/stdc++.h"

using namespace std;

constexpr int BIG = 1e9;

struct lazy_seg {
    int n;
    vector<int> mini, maxi, lazy;
    lazy_seg(int n) : n(n), mini(4 * n), maxi(4 * n), lazy(4 * n) {}

    void push(int v, int l, int r) {
        if (lazy[v] != 0) {
            mini[v] += lazy[v];
            maxi[v] += lazy[v];
            if (l != r) {
                lazy[v * 2] += lazy[v];
                lazy[v * 2 + 1] += lazy[v];
            }
            lazy[v] = 0;
        }
    }

    void range_update(int lo, int hi, int inc, int v, int l, int r) {
        push(v, l, r);
        if (hi < l || lo > r) return;
        if (lo <= l && r <= hi) {
            lazy[v] += inc;
            push(v, l, r);
        } else {
            int m = (l + r) / 2;
            range_update(lo, hi, inc, v * 2, l, m);
            range_update(lo, hi, inc, v * 2 + 1, m + 1, r);
            mini[v] = min(mini[v * 2], mini[v * 2 + 1]);
            maxi[v] = max(maxi[v * 2], maxi[v * 2 + 1]);
        }
    }

    void range_update(int lo, int hi, int inc) {
        range_update(lo, hi, inc, 1, 0, n - 1);
    }

    pair<int, int> range_query(int lo, int hi, int v, int l, int r) {
        push(v, l, r);
        if (hi < l || lo > r) return { BIG, 0 };
        if (lo <= l && r <= hi) return { mini[v], maxi[v] };
        int m = (l + r) / 2;

        pair<int, int> left = range_query(lo, hi, v * 2, l, m);
        pair<int, int> right = range_query(lo, hi, v * 2 + 1, m + 1, r);
        return { min(left.first, right.first), max(left.second, right.second) };
    }

    pair<int, int> range_query(int lo, int hi) {
        return range_query(lo, hi, 1, 0, n - 1);
    }
};


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T; cin >> T;
    while (T--) {
        int N; cin >> N;
        vector<vector<int>> adj(N + 1);
        for (int i = 2; i <= N; i++) {
            int par; cin >> par;
            adj[par].push_back(i);
            adj[i].push_back(par);
        }

        vector<int> tin(N + 1);
        vector<int> tout(N + 1);
        int timer = 0;
        function<void(int, int)> dfs = [&](int v, int p) {
            tin[v] = timer++;
            for (int to : adj[v]) {
                if (to != p) {
                    dfs(to, v);
                }
            }
            tout[v] = timer - 1;
        };
        dfs(1, 1);

        lazy_seg seg(N + 1);
        for (int i = 1; i <= N; i++) {
            int sal; cin >> sal;
            seg.range_update(tin[i], tin[i], sal);
        }

        int Q; cin >> Q;
        while (Q--) {
            char type; cin >> type;
            if (type == 'R') {
                int v, amount; cin >> v >> amount;
                seg.range_update(tin[v], tout[v], amount);
            } else {
                int v; cin >> v;
                auto [mini, maxi] = seg.range_query(tin[v], tout[v]);
                cout << (maxi - mini) << '\n';
            }
        }
    }

    return 0;
}