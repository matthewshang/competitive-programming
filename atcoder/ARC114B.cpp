#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N; cin >> N;
    vector<int> f(N + 1);
    for (int i = 1; i <= N; i++) {
        cin >> f[i];
    }

    int cycles = 0;
    vector<int> vis(N + 1);
    function<void(int)> dfs = [&](int v) {
        vis[v] = 1;
        if (vis[f[v]] == 1) {
            cycles++;
        } else if (vis[f[v]] == 0) {
            dfs(f[v]);
        }
        vis[v] = 2;
    };
    
    for (int v = 1; v <= N; v++) {
        if (vis[v] == 0) {
            dfs(v);
        }
    }

    const int MOD = 998244353;
    int subsets = 1;
    for (int i = 0; i < cycles; i++) {
        subsets = subsets * 2 % MOD;
    }
    cout << (subsets - 1) << '\n';

    return 0;
}
