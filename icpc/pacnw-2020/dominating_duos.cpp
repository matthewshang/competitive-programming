#include <bits/stdc++.h>
using namespace std;

// Count bad pairs instead. The idea is that given any range [l,r], the maximum
// height splits the range into two. Any pair involving one from each side
// is bad. Additionally, a pair involving the left side of [l,m-1]
// and the max we just splitted by is bad because the max in [l,m-1] sits
// in between. Similar idea for the right side of [m+1,r].

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

template<class Fun>
class y_combinator_result {
    Fun fun_;
public:
    template<class T>
    explicit y_combinator_result(T &&fun): fun_(std::forward<T>(fun)) {}

    template<class ...Args>
    decltype(auto) operator()(Args &&...args) {
        return fun_(std::ref(*this), std::forward<Args>(args)...);
    }
};

template<class Fun>
decltype(auto) y_combinator(Fun &&fun) {
    return y_combinator_result<std::decay_t<Fun>>(std::forward<Fun>(fun));
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<pair<int, int>> d(n);
    for (int i = 0; i < n; i++) {
        cin >> d[i].first;
        d[i].second = i;
    }
    RMQ rmq(d);

    int64_t bad_pairs = y_combinator([&](auto solve, int l, int r) -> int64_t {
        int64_t res = 0;
        int m = rmq.query(l, r).second;
        res += (int64_t)(m - l) * (r - m);
        if (l < m) {
            res += solve(l, m - 1);
        }
        if (m < r) {
            res += solve(m + 1, r);
        }
        if (l != 0) {
            res += r - m;
        }
        if (r != n - 1) {
            res += m - l;
        }
        return res;
    })(0, n - 1);

    int64_t good_pairs = (int64_t)n * (n - 1) / 2 - bad_pairs;
    cout << good_pairs << '\n';

    return 0;
}
