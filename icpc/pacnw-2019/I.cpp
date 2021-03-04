#include "bits/stdc++.h"

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N; cin >> N;
    vector<string> words(N);
    vector<bool> par(N);
    for (int i = 0; i < N; i++) {
        cin >> words[i];

        int invs = 0;
        for (int j = 0; j < int(words[i].size()); j++) {
            for (int k = j + 1; k < int(words[i].size()); k++) {
                if (words[i][j] > words[i][k]) {
                    invs++;
                }
            }
        }
        par[i] = invs % 2 == 0;
    }

    vector<vector<int>> g(N);
    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            int diff = 0;
            for (int k = 0; k < int(words[i].size()); k++) {
                if (words[i][k] != words[j][k]) {
                    diff++;
                }
            }
            if (diff == 2) {
                g[i].push_back(j);
                g[j].push_back(i);
            }
        }
    }

    vector<int> mt(N, -1);
    vector<bool> used(N);
    function<bool(int)> dfs = [&](int v) -> bool {
        if (used[v]) {
            return false;
        }
        used[v] = true;
        for (int to : g[v]) {
            if (mt[to] == -1 || dfs(mt[to])) {
                mt[to] = v;
                return true;
            }
        }
        return false;
    };

    int max_matching = 0;
    for (int v = 0; v < N; v++) {
        if (par[v]) {
            fill(used.begin(), used.end(), false);
            if (dfs(v)) {
                max_matching++;
            }
        }
    }
    cout << (N - max_matching) << '\n';

    return 0;
}