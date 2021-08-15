#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<char> sex(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> sex[i];
    }
    vector<vector<int>> g(n + 1);
    vector<int> rg(n + 1);
    vector<bool> dead(n + 1);

    int m;
    cin >> m;
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x;
        if (x < 0) {
            dead[-x] = true;
        } else {
            char child;
            cin >> y >> child;
            sex.push_back(child);
            g[y].push_back(g.size());
            rg.push_back(y);
            g.push_back({});
            dead.push_back(false);
        }
    }

    int k;
    cin >> k;
    vector<int> dna(g.size());
    vector<int> prop;
    int last = -1;
    bool all_same = true;
    int should = 0;
    for (int i = 0; i < k; i++) {
        int who;
        cin >> who >> dna[who];
        if (!dead[who]) {
            should = dna[who];
            if (last != -1 && last != dna[who]) {
                all_same = false;
            }
            last = dna[who];
        }
        prop.push_back(who);
    }

    if (!all_same) {
        cout << "NO\n";
        return 0;
    }

    auto mark = [&](int start) {
        queue<int> q{{start}};
        while (!q.empty()) {
            int v = q.front();
            q.pop();
            if (sex[v] == 'F') {
                for (int to : g[v]) {
                    if (dna[to] == 0) {
                        dna[to] = dna[v];
                        q.push(to);
                    }
                }
            }
            if (dna[rg[v]] == 0) {
                dna[rg[v]] = dna[v];
                q.push(rg[v]);
            }
        }
    };

    for (int start : prop) {
        mark(start);
    }

    for (int v = 1; v < int(g.size()); v++) {
        if (dead[v]) continue;
        if (dna[v] == 0) {
            if (should != 0) {
                cout << "POSSIBLY\n";
                return 0;
            }
            dna[v] = 1e9 + v;
            should = dna[v];
            mark(v);
        } else if (last != -1 && last != dna[v]) {
            cout << "NO\n";
            return 0;
        }
    }
    cout << "YES\n";

    return 0;
}