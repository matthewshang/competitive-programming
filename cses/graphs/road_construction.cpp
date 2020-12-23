#include "bits/stdc++.h"

using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);

    int n, m; cin >> n >> m;

    vector<int> par(n + 1);
    iota(par.begin(), par.end(), 0);
    vector<int> sz(n + 1, 1);
    int num_components = n;
    int largest = 1;

    function<int(int)> find = [&](int x) -> int {
        if (par[x] == x) {
            return x;
        }
        return par[x] = find(par[x]);
    };

    auto join = [&](int a, int b) {
        int u = find(a);
        int v = find(b);
        if (u != v) {
            if (sz[u] < sz[v]) {
                swap(u, v);
            }
            par[v] = u;
            sz[u] += sz[v];
            num_components--;
            largest = max(largest, sz[u]);
        }
    };

    for (int e = 0; e < m; e++) {
        int a, b; cin >> a >> b;
        join(a, b);
        cout << num_components << " " << largest << '\n';
    }

    return 0;
}