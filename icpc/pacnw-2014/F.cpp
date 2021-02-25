#include "bits/stdc++.h"

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    constexpr int MOD = 1e9 + 9;

    const auto has_attacking = [](int mask, int m, int w) -> bool {
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < w; j++) {
                for (int x = 0; x < m; x++) {
                    for (int y = 0; y < w; y++) {
                        if ((abs(i - x) == 1 && abs(j - y) == 2) 
                            || (abs(i - x) == 2 && abs(j - y) == 1)) {
                            bool on1 = mask & (1 << (j * m + i));
                            bool on2 = mask & (1 << (y * m + x));
                            if (on1 && on2) {
                                return true;
                            }
                        }
                    }
                }
            }
        }
        return false;
    };

    const auto can_move = [&](int from, int to, int m) -> bool {
        if ((from & ((1 << m) - 1)) != (to >> m))
            return false;
        int mask = ((from >> m) << (2 * m)) | to;
        return !has_attacking(mask, m, 3);
    };

    array<vector<vector<int>>, 5> mat;
    array<vector<int>, 5> start;
    for (int m = 1; m <= 4; m++) {
        int sz = 1 << (2 * m);
        mat[m] = vector<vector<int>>(sz, vector<int>(sz));
        start[m] = vector<int>(sz);
        for (int from = 0; from < sz; from++) {
            for (int to = 0; to < sz; to++) {
                mat[m][from][to] = can_move(from, to, m);
            }
            start[m][from] = !has_attacking(from, m, 2);
        }
    }

    const auto matmul = [&](vector<vector<int>>& a, vector<vector<int>>& b) -> vector<vector<int>> {
        int n = a.size();
        vector<vector<int>> c(n, vector<int>(n));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                for (int k = 0; k < n; k++) {
                    c[i][j] = (c[i][j] + (long long)a[i][k] * b[k][j] % MOD) % MOD;
                }
            }
        }
        return c;
    };

    const auto vecmul = [&](vector<vector<int>>& a, vector<int>& v) -> vector<int> {
        int n = a.size();
        vector<int> x(n);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                x[i] = (x[i] + (long long)a[i][j] * v[j] % MOD) % MOD;
            }
        }
        return x;
    };

    const auto binpow = [&](vector<vector<int>> a, int p) -> vector<vector<int>> {
        vector<vector<int>> x(a.size(), vector<int>(a.size()));
        for (int i = 0; i < int(a.size()); i++)
            x[i][i] = 1;
        while (p > 0) {
            if (p % 2 == 1) {
                x = matmul(x, a);
            }
            a = matmul(a, a);
            p /= 2;
        }
        return x;
    };

    int T; cin >> T;
    while (T--) {
        int M, N; cin >> M >> N;
        if (N < 3) {
            int res = 0;
            for (int mask = 0; mask < (1 << (N * M)); mask++) {
                res += !has_attacking(mask, M, N);
            }
            cout << res << '\n';
        } else {
            vector<vector<int>> tran = binpow(mat[M], N - 2);
            vector<int> v = vecmul(tran, start[M]);
            int res = 0;
            for (int i = 0; i < int(v.size()); i++) {
                res = (res + v[i]) % MOD;
            }
            cout << res << '\n';
        }
    }

    return 0;
}