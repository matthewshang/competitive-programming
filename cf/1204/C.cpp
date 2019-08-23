#include "bits/stdc++.h"

using namespace std;

using ll = long long;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    int n; cin >> n;
    const int INF = 1 << 20;
    int dist[n][n];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            dist[i][j] = INF;
    for (int i = 0; i < n; i++) {
        string s; cin >> s;
        for (int j = 0; j < n; j++) {
            if (s[j] == '1') dist[i][j] = 1;
        }
    }
    for (int i = 0; i < n; i++)
        dist[i][i] = 0;
    for (int k = 0; k < n; k++)
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);

    int m; cin >> m;
    vector<int> p(m);
    for (int& x : p) cin >> x;
    vector<int> ans;
    ans.push_back(p[0]);
    for (int i = 1; i < m - 1; i++) {
        int a = ans.back();
        int b = p[i], c = p[i + 1];
        a--; b--; c--;
        if (dist[a][b] + dist[b][c] != dist[a][c])
            ans.push_back(p[i]);
    }
    ans.push_back(p[m - 1]);

    cout << ans.size() << endl;
    for (int x : ans) cout << x << " ";
    cout << endl;
    return 0;
}
