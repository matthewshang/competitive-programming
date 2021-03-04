#include "bits/stdc++.h"

using namespace std;

struct lazy_seg {
    int n;
    vector<int> seg, lazy;
    lazy_seg(int n) : n(n), seg(4 * n), lazy(4 * n) {}
    void push(int v, int l, int r) {
        if (lazy[v] != 0) {
            if (l != r) {
                lazy[v * 2] += lazy[v];
                lazy[v * 2 + 1] += lazy[v];
            } else {
                seg[v] += lazy[v];
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
        }
    }
    void range_update(int lo, int hi, int inc) {
        range_update(lo, hi, inc, 1, 0, n - 1);
    }
    int point_query(int pos, int v, int l, int r) {
        push(v, l, r);
        if (l == r) return seg[v];
        int m = (l + r) / 2;
        if (pos <= m)
            return point_query(pos, v * 2, l, m);
        else
            return point_query(pos, v * 2 + 1, m + 1, r);
    }
    int point_query(int pos) {
        return point_query(pos, 1, 0, n - 1);
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k; cin >> n >> k;
    vector<int> x(n);
    for (int i = 0; i < n; i++) {
        cin >> x[i];
    }

    lazy_seg uni(n);
    set<int> seen;
    vector<int> last(k + 1, -1);
    for (int i = n - 1; i >= 0; i--) {
        seen.insert(x[i]);
        uni.range_update(i, i, seen.size());
        if (last[x[i]] == -1) {
            last[x[i]] = i;
        }
    }

    vector<int> ord(k);
    map<int, set<int>> count;
    set<int> ban;
    int l = 0;
    int r = 0;
    for (int i = k; i > 0; i--) {
        while (r < n && uni.point_query(r) == i) {
            if (ban.find(x[r]) == ban.end()) {
                count[x[r]].insert(r);
            }
            r++;
        }
        
        int pos = *count.begin()->second.begin();
        int who = count.begin()->first;
        ord[k - i] = who;

        while (l <= pos) {
            count[x[l]].erase(l);
            if (count[x[l]].empty()) {
                count.erase(x[l]);
            }
            l++;
        }
        count.erase(who);
        ban.insert(who);
        uni.range_update(0, last[who], -1);
    }

    for (int i = 0; i < k; i++) {
        cout << ord[i] << ' ';
    }
    cout << '\n';

    return 0;
}