#include "bits/stdc++.h"

using namespace std;

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

template <typename F>
int first_true(int low, int high, F pred) {
    while (low < high) {
        int mid = low + (high - low) / 2;
        if (pred(mid)) {
            high = mid;
        } else {
            low = mid + 1;
        }
    }
    return low;
}

template <typename F>
int last_true(int low, int high, F pred) {
    while (low < high) {
        int mid = low + (high - low + 1) / 2;
        if (pred(mid)) {
            low = mid;
        } else {
            high = mid - 1;
        }
    }
    return low;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T; cin >> T;
    for (int tc = 1; tc <= T; tc++) {
        int N, K; cin >> N >> K;
        vector<int> C(N);
        for (int i = 0; i < N; i++) {
            cin >> C[i];
        }
        vector<int> D(N);
        for (int i = 0; i < N; i++) {
            cin >> D[i];
        }

        RMQ cm(C);
        RMQ dm(D);

        long long ans = 0;
        for (int i = 0; i < N; i++) {
            int l = first_true(0, i, [&](int pos) {
                return pos == i || cm.query(pos, i - 1) < C[i];
            });
            int l_low = first_true(l, i, [&](int pos) {
                return dm.query(pos, i) <= C[i] + K;
            });
            int l_high = last_true(l - 1, i, [&](int pos) {
                return dm.query(pos, i) >= C[i] - K;
            });

            int r = last_true(i, N - 1, [&](int pos) {
                return cm.query(i, pos) <= C[i]; 
            });
            int r_low = first_true(i, r + 1, [&](int pos) {
                return dm.query(i, pos) >= C[i] - K;
            });
            int r_high = last_true(i, r, [&](int pos) {
                return dm.query(i, pos) <= C[i] + K;
            });

            if (abs(dm.query(l_low, r_high) - C[i]) > K) {
                continue;
            }

            ans += (long long)(r_high - i + 1) * (i - l_low + 1);
            ans -= (long long)(r_low - i) * (i - l_high);
        }
        cout << "Case #" << tc << ": " << ans << '\n';
    }

    return 0;
}