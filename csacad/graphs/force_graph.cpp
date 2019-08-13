#include "bits/stdc++.h"

using namespace std;

using ll = long long;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    int n, m, f1, f2; cin >> n >> m >> f1 >> f2;
    vector<pair<int, int>> edges(m);
    for (auto& e : edges) cin >> e.first >> e.second;
    vector<pair<int, int>> pos(n);
    for (auto& p : pos) cin >> p.first >> p.second;

    vector<pair<ll, ll>> conn(n, {0, 0});
    vector<ll> sz(n, 0);
    for (auto& e : edges) {
        int u = e.first - 1, v = e.second - 1;
        conn[u].first += pos[v].first;
        conn[u].second += pos[v].second;
        conn[v].first += pos[u].first;
        conn[v].second += pos[u].second;

        sz[u]++; sz[v]++;
    }

    pair<ll, ll> total = {0, 0};
    for (auto& p : pos) {
        total.first += p.first;
        total.second += p.second;
    }

    for (int i = 0; i < n; i++) {
        pair<ll, ll> C = conn[i];
        pair<ll, ll> D = {total.first - C.first, total.second - C.second};
        ll M = sz[i], N = n - sz[i];
        ll x = pos[i].first, y = pos[i].second;
        pair<ll, ll> F = {f1 * C.first + f2 * D.first - f1 * M * x - f2 * N * x,
                          f1 * C.second + f2 * D.second - f1 * M * y - f2 * N * y};
        cout << -F.first << " " << -F.second << endl;
    }

    return 0;
}
