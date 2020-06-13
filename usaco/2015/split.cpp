#include "bits/stdc++.h"

using namespace std;

using ll = long long;
using pll = pair<ll, ll>;

namespace io {
    void set(string s) {
        freopen((s + ".in").c_str(), "r", stdin);
        #ifndef TESTING
        freopen((s + ".out").c_str(), "w", stdout);
        #endif
    }
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    io::set("split");

    int n; cin >> n;
    vector<pll> x(n);
    for (auto& p : x) cin >> p.first >> p.second;

    vector<pll> y = x;
    sort(x.begin(), x.end(), [](const pll& l, const pll& r) -> int {
            return l.first < r.first;
    });
    sort(y.begin(), y.end(), [](const pll& l, const pll& r) {
            return l.second < r.second;
    });
    
    vector<ll> U(n), D(n), L(n), R(n);
    ll maxx = y[0].first, minx = y[0].first, maxy = x[0].second, miny = x[0].second;
    for (int i = 0; i < n; i++) {
        maxx = max(maxx, y[i].first);
        minx = min(minx, y[i].first);
        maxy = max(maxy, x[i].second);
        miny = min(miny, x[i].second);
        D[i] = maxx - minx;
        L[i] = maxy - miny;
    }
    maxx = y[n - 1].first; minx = y[n - 1].first; 
    maxy = x[n - 1].second; miny = x[n - 1].second;
    for (int i = n - 1; i >= 0; i--) {
        maxx = max(maxx, y[i].first);
        minx = min(minx, y[i].first);
        maxy = max(maxy, x[i].second);
        miny = min(miny, x[i].second);
        U[i] = maxx - minx;
        R[i] = maxy - miny;
    }

    ll big = (ll)(x[n - 1].first - x[0].first) * (ll)(y[n - 1].second - y[0].second);
    ll ans = big;
    for (int i = 0; i < n - 1; i++) {
        ll lx = x[i].first - x[0].first;
        ll rx = x[n - 1].first - x[i + 1].first;
        ans = min(ans, L[i] * lx + R[i + 1] * rx);

        ll dy = y[i].second - y[0].second;
        ll uy = y[n - 1].second - y[i + 1].second;
        ans = min(ans, D[i] * dy + U[i + 1] * uy);
    }
    cout << (big - ans) << endl;

    return 0;
}
