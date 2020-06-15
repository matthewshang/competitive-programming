#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using vi = vector<int>;
using vb = vector<bool>;
using vvi = vector<vector<int>>;
using vll = vector<long long>;
using vpi = vector<pair<int, int>>;
using pii = pair<int, int>;
using pll = pair<long long, long long>;

#define F first
#define S second
#define pb push_back
#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()

#define FOR(i, a, b) for (int i = (a); i <= (b); ++i)
#define F0R(i, a) for (int i = 0; i < (a); ++i)
#define RFOR(i, a, b) for (int i = (a); i >= (b); --i)

const char nl = '\n';
const ll MOD = 1e9 + 7;

void setIO(string s) {
    freopen((s + ".in").c_str(), "r", stdin);
    #ifndef TESTING
    freopen((s + ".out").c_str(), "w", stdout);
    #endif
}

struct DSU {
    vi par;
    vi sz;

    DSU(int n) {
        par.resize(n);
        sz.resize(n);
        for (int i = 0; i < n; i++) {
            par[i] = i;
            sz[i] = 1;
        }
    }

    int find(int x) {
        if (x == par[x]) return x;
        return par[x] = find(par[x]);
    }

    bool join(int u, int v) {
        int a = find(u), b = find(v);
        if (a == b) return false;
        if (sz[a] < sz[b]) swap(a, b);
        par[b] = a;
        sz[a] += sz[b];
        return true;
    }
};

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    setIO("mootube");

    int n, q; cin >> n >> q;
    vector<array<int, 3>> vid(n - 1);
    F0R (i, n - 1) {
        cin >> vid[i][0] >> vid[i][1] >> vid[i][2];
    }
    sort(all(vid), [](const array<int, 3>& a, const array<int, 3>& b) -> bool {
        return a[2] < b[2];
    });

    vector<array<int, 3>> qu(q);
    F0R (i, q) {
        cin >> qu[i][0] >> qu[i][1];
        qu[i][2] = i;
    }
    vi ans(q);
    sort(all(qu), [](const array<int, 3>& a, const array<int, 3>& b) -> bool {
        return a[0] < b[0];
    });

    DSU D(n + 1);

    while (sz(qu)) {
        int target = qu.back()[0];
        while (sz(vid) && vid.back()[2] >= target) {
            int u = vid.back()[0];
            int v = vid.back()[1];
            D.join(u, v);
            vid.pop_back();
        }
        while (qu.back()[0] == target) {
            int v = qu.back()[1];
            int idx = qu.back()[2];
            ans[idx] = D.sz[D.find(v)] - 1;
            qu.pop_back();
        }
    }

    F0R (i, q) cout << ans[i] << nl;

    return 0;
}
