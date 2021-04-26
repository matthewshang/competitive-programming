#include <bits/stdc++.h>
using namespace std;

// Source: KACTL
// https://github.com/kth-competitive-programming/kactl/blob/master/content/strings/SuffixArray.h
struct SuffixArray {
	vector<int> sa, lcp;
	SuffixArray(string& s, int lim=256) { // or basic_string<int>
		int n = s.size() + 1, k = 0, a, b;
		vector<int> x(s.begin(), s.end()+1), y(n), ws(max(n, lim)), rank(n);
		sa = lcp = y, iota(sa.begin(), sa.end(), 0);
		for (int j = 0, p = 0; p < n; j = max(1, j * 2), lim = p) {
			p = j, iota(y.begin(), y.end(), n - j);
			for (int i = 0; i < n; i++) if (sa[i] >= j) y[p++] = sa[i] - j;
			fill(ws.begin(), ws.end(), 0);
			for(int i = 0; i < n; i++) ws[x[i]]++;
            for (int i = 1; i < lim; i++) ws[i] += ws[i - 1];
			for (int i = n; i--;) sa[--ws[x[y[i]]]] = y[i];
			swap(x, y), p = 1, x[sa[0]] = 0;
            for (int i = 1; i < n; i++) a = sa[i - 1], b = sa[i], x[b] =
				(y[a] == y[b] && y[a + j] == y[b + j]) ? p - 1 : p++;
		}
        for (int i = 1; i < n; i++) rank[sa[i]] = i;
		for (int i = 0, j; i < n - 1; lcp[rank[i++]] = k)
			for (k && k--, j = sa[rank[i] - 1]; s[i + k] == s[j + k]; k++);
	}
};

// Source: CP-algorithms
// https://cp-algorithms.com/data_structures/segment_tree.html#toc-tgt-12
struct Vertex {
    Vertex *l, *r;
    int sum;

    Vertex(int val) : l(nullptr), r(nullptr), sum(val) {}
    Vertex(Vertex *l, Vertex *r) : l(l), r(r), sum(0) {
        if (l) sum += l->sum;
        if (r) sum += r->sum;
    }
};

Vertex* build(int tl, int tr) {
    if (tl == tr)
        return new Vertex(0);
    int tm = (tl + tr) / 2;
    return new Vertex(build(tl, tm), build(tm+1, tr));
}

Vertex* update(Vertex* v, int tl, int tr, int pos) {
    if (tl == tr)
        return new Vertex(v->sum+1);
    int tm = (tl + tr) / 2;
    if (pos <= tm)
        return new Vertex(update(v->l, tl, tm, pos), v->r);
    else
        return new Vertex(v->l, update(v->r, tm+1, tr, pos));
}

int find_kth(Vertex* vl, Vertex *vr, int tl, int tr, int k) {
    if (tl == tr)
        return tl;
    int tm = (tl + tr) / 2, left_count = vr->l->sum - vl->l->sum;
    if (left_count >= k)
        return find_kth(vl->l, vr->l, tl, tm, k);
    return find_kth(vl->r, vr->r, tm+1, tr, k-left_count);
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s; cin >> s;
    int n = s.size();
    SuffixArray sa(s);
    vector<int>& suf_ids = sa.sa;
    suf_ids.erase(suf_ids.begin());

    int tl = 0, tr = n - 1;
    vector<Vertex*> roots;
    roots.push_back(build(tl, tr));
    for (int i = 0; i < suf_ids.size(); i++) {
        roots.push_back(update(roots.back(), tl, tr, suf_ids[i]));
    }

    // -1 = t < suffix starting from j
    //  0 = t = suffix starting from j
    // +1 = t > suffix starting from j
    auto cmp = [&](string& t, int j) -> int {
        int i = 0;
        while (i < int(t.size()) && j + i < n) {
            if (t[i] < s[j + i]) {
                return -1;
            } else if (t[i] > s[j + i]) {
                return 1;
            }
            i++;
        }
        if (i < int(t.size())) {
            // no more suffix.
            return 1;
        } else if (j + i < n) {
            return -1;
        } else {
            return 0;
        }
    };

    auto is_prefix = [&](string& t, int j) -> bool {
        int i = 0;
        while (i < int(t.size()) && j + i < n) {
            if (t[i] != s[j + i]) {
                return false;
            }
            i++;
        }
        return i == t.size();
    };

    int q; cin >> q;
    while (q--) {
        string t; cin >> t;
        int k; cin >> k;

        // First position such that t <= the suffix here
        int low = 0;
        int high = n - 1;
        while (low < high) {
            int mid = low + (high - low) / 2;
            if (cmp(t, suf_ids[mid]) > 0) {
                low = mid + 1;
            } else {
                high = mid;
            }
        }
        int first = low;

        if (!is_prefix(t, suf_ids[first])) {
            cout << -1 << '\n';
            continue;
        }

        // Last position such that t is a prefix
        low = first;
        high = n - 1;
        while (low < high) {
            int mid = low + (high - low + 1) / 2;
            if (is_prefix(t, suf_ids[mid])) {
                low = mid;
            } else {
                high = mid - 1;
            }
        }
        int last = low;

        if (last - first + 1 < k) {
            cout << -1 << '\n';
        } else {
            int who = find_kth(roots[first], roots[last + 1], tl, tr, k);
            cout << (1 + who) << '\n';
        }
    }

    return 0;
}

// 