// Range Minimum Queries I

#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using vi = vector<int>;
using pii = pair<int, int>;
using vpi = vector<pair<int, int>>;

#define f first
#define s second
#define pb push_back
#define mp make_pair
#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()

#define FOR(i, a, b) for (int i=(a); i <(b); i++)
#define F0R(i, a) for (int i=0; i < (a); i++)
#define RFOR(i, a, b) for (int i = (a); i >= b; i--)

template <typename T>
struct RMQ {
    vector<vector<T>> st;
    RMQ(vector<T>& v) {
        int t = __lg(sz(v));
        st.resize(t + 1);
        st[0].resize(sz(v));
        F0R (i, sz(v)) st[0][i] = v[i];
        F0R (l, t) {
            int m = sz(v) - (1 << (l + 1)) + 1;
            st[l + 1].resize(m);
            F0R (i, m) st[l + 1][i] = min(st[l][i], st[l][i + (1 << l)]);
        }
    }
    T query(int l, int r) { // [l, r]
        int t = __lg(r - l + 1);
        return min(st[t][l], st[t][r - (1 << t) + 1]);
    }
};

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    int n, q; cin >> n >> q;
    vector<int> x(n);
    F0R (i, n) cin >> x[i];
    RMQ<int> R(x);

    F0R (i, q) {
        int a, b; cin >> a >> b;
        cout << R.query(a - 1, b - 1) << endl;
    }

    return 0;
}
