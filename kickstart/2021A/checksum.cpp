#include "bits/stdc++.h"

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T; cin >> T;
    for (int tc = 1; tc <= T; tc++) {
        int N; cin >> N;
        vector<vector<int>> A(N, vector<int>(N));
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                cin >> A[i][j];
            }
        }
        vector<vector<int>> B(N, vector<int>(N));
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                cin >> B[i][j];
            }
        }
        vector<int> R(N);
        for (int i = 0; i < N; i++) {
            cin >> R[i];
        }
        vector<int> C(N);
        for (int i = 0; i < N; i++) {
            cin >> C[i];
        }

        vector<array<int, 3>> edges;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (A[i][j] == -1) {
                    edges.push_back({ B[i][j], i, N + j });
                }
            }
        }
        sort(edges.begin(), edges.end());
        reverse(edges.begin(), edges.end());

        vector<int> par(N * 2);
        iota(par.begin(), par.end(), 0);
        vector<int> sz(N * 2, 1);
        function<int(int)> find = [&](int x) -> int {
            if (par[x] != x) par[x] = find(par[x]);
            return par[x];
        };

        auto join = [&](int a, int b) -> bool {
            int u = find(a);
            int v = find(b);
            if (u == v) {
                return false;
            }
            if (sz[u] < sz[v]) {
                swap(u, v);
            }
            par[v] = u;
            sz[u] += sz[v];
            return true;
        };

        long long cost = 0;
        for (auto [w, u, v] : edges) {
            if (!join(u, v)) {
                cost += w;
            }
        }
        cout << "Case #" << tc << ": " << cost << '\n';
    }

    return 0;
}