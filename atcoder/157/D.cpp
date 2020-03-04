#include "bits/stdc++.h"
using namespace std;

int main() {
  int n, m, k; cin >> n >> m >> k;
  vector<vector<int>> adj(n + 1);
  vector<int> bad(n + 1);
  for (int i = 0; i < m; i++) {
    int u, v; cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  
  vector<int> color(n + 1);
  vector<int> sz;
  vector<bool> vis(n + 1, false);
  function<int(int, int)> dfs = [&] (int u, int c) -> int {
    color[u] = c;
    vis[u] = true;
    int ans = 1;
    for (int x : adj[u]) if (!vis[x]) {
      ans += dfs(x, c);
    }
    return ans;
  };
  int current_color = 0;
  for (int i = 1; i <= n; i++) {
    if (!vis[i]) {
      int num = dfs(i, current_color++);
      sz.push_back(num);
    }
  }
  
  for (int i = 0; i < k; i++) {
    int u, v; cin >> u >> v;
    if (color[u] == color[v]) {
      bad[u]++; bad[v]++;
    }
  }
  
  for (int i = 1; i <= n; i++) {
    int ans = sz[color[i]] - 1 - adj[i].size() - bad[i];
    cout << ans << " ";
  }
  cout << endl;
  return 0;
}

