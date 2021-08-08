#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;
    vector<vector<string>> pref(n);
    for (int i = 0; i < n; i++) {
        int q;
        cin >> q;
        pref[i].resize(q);
        for (int j = 0; j < q; j++) {
            cin >> pref[i][j];
        }
        reverse(pref[i].begin(), pref[i].end());
    }

    int p;
    cin >> p;
    vector<string> rank(p);
    for (int i = 0; i < p; i++) {
        cin >> rank[i];
    }
    reverse(rank.begin(), rank.end());

    set<string> taken;
    vector<vector<string>> teams(n);
    for (int j = 0; j < k; j++) {
        for (int i = 0; i < n; i++) {
            while (!pref[i].empty()) {
                if (taken.find(pref[i].back()) != taken.end()) {
                    pref[i].pop_back();
                } else {
                    break;
                }
            }

            if (!pref[i].empty()) {
                teams[i].push_back(pref[i].back());
                taken.insert(pref[i].back());
                pref[i].pop_back();
            } else {
                while (taken.find(rank.back()) != taken.end()) {
                    rank.pop_back();
                }
                teams[i].push_back(rank.back());
                taken.insert(rank.back());
                rank.pop_back();
            }
        }
    }

    for (int i = 0; i < n; i++) {
        cout << teams[i][0];
        for (int j = 1; j < k; j++) {
            cout << ' ' << teams[i][j];
        }
        cout << '\n';
    }

    return 0;
}