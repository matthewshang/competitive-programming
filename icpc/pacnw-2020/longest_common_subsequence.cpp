#include "bits/stdc++.h"

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k; cin >> n >> k;
    vector<string> s(n);
    vector<vector<int>> pos(n, vector<int>(k));
    for (int i = 0; i < n; i++) {
        cin >> s[i];
        for (int j = 0; j < k; j++) {
            pos[i][s[i][j] - 'A'] = j;
        }
    }

    vector<vector<int>> adj(k);
    for (int i = 0; i < k; i++) {
        for (int j = i + 1; j < k; j++) {
            int before = 0;
            for (int l = 0; l < n; l++) {
                if (pos[l][i] < pos[l][j]) {
                    before++;
                }
            }

            if (before == n) {
                adj[i].push_back(j);
            } else if (before == 0) {
                adj[j].push_back(i);
            }
        }
    }

    vector<int> indeg(k);
    vector<vector<int>> rev(k);
    for (int i = 0; i < k; i++) {
        for (int to : adj[i]) {
            indeg[to]++;
            rev[to].push_back(i);
        }
    }
    queue<int> q;
    for (int i = 0; i < k; i++) {
        if (indeg[i] == 0) {
            q.push(i);
        }
    }

    vector<int> ord;
    while (!q.empty()) {
        int v = q.front();
        ord.push_back(v);
        q.pop();
        for (int to : adj[v]) {
            indeg[to]--;
            if (indeg[to] == 0) {
                q.push(to);
            }
        }
    }

    vector<int> dist(k);
    for (int v : ord) {
        dist[v] = 1;
        for (int from : rev[v]) {
            dist[v] = max(dist[v], dist[from] + 1);
        }
    }

    cout << *max_element(dist.begin(), dist.end()) << '\n';

    return 0;
}
