#include <bits/stdc++.h>
using namespace std;

int n, k;
vector<string> g;
array<bool, 5> used;
array<int, 5> sizes;
array<array<bool, 5>, 5> covered;

pair<int, int> get_next(int r, int c) {
    int nr = r;
    int nc = c + 1;
    if (nc == n) {
        nr = r + 1;
        nc = 0;
    }
    return {nr, nc};
}

int64_t go(int r, int c) {
    int64_t res = 0;
    if (r == n) {
        bool all_used = true;
        for (int i = 0; i < k; i++) {
            all_used &= used[i];
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (g[i][j] == 'O') {
                    all_used &= covered[i][j];
                }
            }
        }
        return all_used;
    }
    auto [nr, nc] = get_next(r, c);
    if (g[r][c] == 'X' || covered[r][c]) {
        return go(nr, nc);
    }
    
    for (int i = 0; i < k; i++) {
        if (used[i]) continue;
        
        used[i] = true;
        
        // horizontal
        bool hori_ok = false;
        if (c + sizes[i] <= n) {
            hori_ok = true;
            for (int j = 0; j < sizes[i]; j++) {
                if (g[r][c + j] == 'X' || covered[r][c + j]) {
                    hori_ok = false;
                }
            }
        }
        string save(5, '.');
        if (hori_ok) {
            for (int j = 0; j < sizes[i]; j++) {
                save[j] = g[r][c + j];
                g[r][c + j] = 'O';
                covered[r][c + j] = true;
            }
            res += go(nr, nc);
            for (int j = 0; j < sizes[i]; j++) {
                g[r][c + j] = save[j];
                covered[r][c + j] = false;
            }
        }
        
        if (sizes[i] == 1) {
            used[i] = false;
            continue;
        }
        
        bool vert_ok = false;
        if (r + sizes[i] <= n) {
            vert_ok = true;
            for (int j = 0; j < sizes[i]; j++) {
                if (g[r + j][c] == 'X' || covered[r + j][c]) {
                    vert_ok = false;
                }
            }
        }
        if (vert_ok) {
            for (int j = 0; j < sizes[i]; j++) {
                save[j] = g[r + j][c];
                g[r + j][c] = 'O';
                covered[r + j][c] = true;
            }
            res += go(nr, nc);
            for (int j = 0; j < sizes[i]; j++) {
                g[r + j][c] = save[j];
                covered[r + j][c] = false;
            }
        }
        used[i] = false;
    }
    res += go(nr, nc);
    
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> n >> k;
    g.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> g[i];
    }
    for (int i = 0; i < k; i++) {
        cin >> sizes[i];
        used[i] = false;
    }
    
    int64_t ways = go(0, 0);
    cout << ways << '\n';
    
    return 0;
}
