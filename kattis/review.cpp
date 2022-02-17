#include <bits/stdc++.h>
using namespace std;

/* Date: 2022-02-17
 * Source: SWERC 2016
 * Summary: Process in increasing rank, breaking ties with lowest depth first.
 * Use fenwick + euler tour to quickly update/query subtrees.
 */

struct fenwick {
    vector<int64_t> a;
    fenwick(int n) : a(n) {}
    int64_t query(int pos) {
        int64_t ans = 0;
        for (pos++; pos > 0; pos &= pos - 1) ans += a[pos - 1];
        return ans;
    }
    int64_t query(int l, int r) {
        return query(r) - query(l - 1);
    }
    void update(int pos, int delta) {
        for (; pos < (int)a.size(); pos |= pos + 1) a[pos] += delta;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<vector<int>> adj(n);
    vector<int> r(n);
    vector<int> t(n);
    int root = 0;
    for (int i = 0; i < n; i++) {
        int p;
        cin >> p;
        if (p != -1) {
            adj[p - 1].push_back(i);
        } else {
            root = i;
        }
        cin >> r[i] >> t[i];
    }

    vector<int> in(n);
    vector<int> out(n);
    vector<int> depth(n);
    int timer = 0;
    auto tour = [&](auto&& tour, int v, int d) -> void {
        in[v] = timer++;
        depth[v] = d;
        for (int next : adj[v]) {
            tour(tour, next, d + 1);
        }
        out[v] = timer++;
    };
    tour(tour, root, 0);

    vector<array<int, 3>> order(n);
    for (int i = 0; i < n; i++) {
        order[i] = {r[i], depth[i], i};
    }
    sort(order.begin(), order.end());

    fenwick feed(2 * n);
    vector<int64_t> ans(n);
    for (auto [_, __, who] : order) {
        ans[who] = feed.query(in[who], out[who]);
        feed.update(in[who], t[who]);
    }
    
    for (auto time : ans) {
        cout << time << "\n";
    }

    return 0;
}