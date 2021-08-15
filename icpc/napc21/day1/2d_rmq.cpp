#include <bits/stdc++.h>
using namespace std;

// row layer, row offset, col layer, col offset
int st[11][1000][11][1000];

void init(vector<vector<int>> v) {
    const int n = v.size();
    const int m = v[0].size();
    const int row_layers = __lg(n);
    const int col_layers = __lg(m);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            st[0][i][0][j] = v[i][j];
        }

        for (int cl = 0; cl < col_layers; cl++) {
            int col_layer_size = m - (1 << (cl + 1)) + 1;
            for (int j = 0; j < col_layer_size; j++) {
                st[0][i][cl + 1][j] = min(st[0][i][cl][j], st[0][i][cl][j + (1 << cl)]);
            }
        }
    }

    for (int rl = 0; rl < row_layers; rl++) {
        int row_layer_size = n - (1 << (rl + 1)) + 1;
        for (int i = 0; i < row_layer_size; i++) {
            for (int j = 0; j < m; j++) {
                st[rl + 1][i][0][j] = min(st[rl][i][0][j], st[rl][i + (1 << rl)][0][j]);
            }

            for (int cl = 0; cl < col_layers; cl++) {
                int col_layer_size = m - (1 << (cl + 1)) + 1;
                for (int j = 0; j < col_layer_size; j++) {
                    st[rl + 1][i][cl + 1][j] = min(st[rl][i][cl + 1][j], st[rl][i + (1 << rl)][cl + 1][j]);
                }
            }
        }
    }
}

int query(int lo_r, int hi_r, int lo_c, int hi_c) {
    int rl = __lg(hi_r - lo_r + 1);
    int cl = __lg(hi_c - lo_c + 1);
    return min(
        min(st[rl][lo_r][cl][lo_c], st[rl][hi_r - (1 << rl) + 1][cl][hi_c - (1 << cl) + 1]),
        min(st[rl][lo_r][cl][hi_c - (1 << cl) + 1], st[rl][hi_r - (1 << rl) + 1][cl][lo_c]));
}