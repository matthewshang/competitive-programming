#include "bits/stdc++.h"

using namespace std;

using ll = long long;

const int MX = 5000;
int n;
int lines[MX][4];
bool vert[MX];
vector<int> adj[MX];

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 4; j++) cin >> lines[i][j];
        vert[i] = lines[i][0] == lines[i][2];
        if (vert[i] && lines[i][1] > lines[i][3]) swap(lines[i][1], lines[i][3]);
        if (!vert[i] && lines[i][0] > lines[i][2]) swap(lines[i][0], lines[i][2]);
    }

    int edges = 0;
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (vert[i] == vert[j]) continue;
            if (vert[i] && lines[i][0] >= lines[j][0] && lines[i][0] <= lines[j][2] &&
                           lines[j][1] >= lines[i][1] && lines[j][1] <= lines[i][3]) {
                adj[i].push_back(j); adj[j].push_back(i);
                edges++;
            }
            if (vert[j] && lines[j][0] >= lines[i][0] && lines[j][0] <= lines[i][2] &&
                           lines[i][1] >= lines[j][1] && lines[i][1] <= lines[j][3]) {
                adj[i].push_back(j); adj[j].push_back(i);
                edges++;
            }
        }
    }

    // for (int i = 0; i < n; i++) {
    //     cout << i << ": " << vert[i] << ": ";
    //     for (int x : adj[i]) cout << x << " ";
    //     cout << endl;
    // }

    for (int i = 0; i < n; i++) sort(adj[i].begin(), adj[i].end());

    int ans = 0;
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            int u = 0, v = 0;
            int count = 0;
            while (u < adj[i].size() && v < adj[j].size()) {
                if (adj[i][u] < adj[j][v]) {
                    u++;
                } else if (adj[i][u] > adj[j][v]) {
                    v++;
                } else {
                    u++; v++; count++;
                }
            }
            ans += count * (count - 1) / 2;
        }
    }
    cout << ans / 2 << endl;
    return 0;
}
