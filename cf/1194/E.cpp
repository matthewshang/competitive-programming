#pragma GCC target("avx,avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")

#include "bits/stdc++.h"

using namespace std;

using ll = long long;

const int MX = 5000;
int n;
int lines[MX][4];
bool vert[MX];
// vector<int> adj[MX];

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 4; j++) cin >> lines[i][j];
        vert[i] = lines[i][0] == lines[i][2];
        if (vert[i] && lines[i][1] > lines[i][3]) swap(lines[i][1], lines[i][3]);
        if (!vert[i] && lines[i][0] > lines[i][2]) swap(lines[i][0], lines[i][2]);
    }

    vector<bitset<5000>> adj(5000, bitset<5000>(0));

    int edges = 0;
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (vert[i] == vert[j]) continue;
            if (vert[i] && lines[i][0] >= lines[j][0] && lines[i][0] <= lines[j][2] &&
                           lines[j][1] >= lines[i][1] && lines[j][1] <= lines[i][3]) {
                adj[i].set(j); adj[j].set(i);
                edges++;
            }
            if (vert[j] && lines[j][0] >= lines[i][0] && lines[j][0] <= lines[i][2] &&
                           lines[i][1] >= lines[j][1] && lines[i][1] <= lines[j][3]) {
                adj[i].set(j); adj[j].set(i);
                edges++;
            }
        }
    }

    // for (int i = 0; i < n; i++) {
    //     cout << i << ": " << vert[i] << ": ";
    //     for (int x : adj[i]) cout << x << " ";
    //     cout << endl;
    // }

    int ans = 0;
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            int count = (adj[i] & adj[j]).count();
            ans += count * (count - 1) / 2;
        }
    }
    cout << ans / 2 << endl;
    return 0;
}
