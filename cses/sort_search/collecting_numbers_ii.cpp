#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m; 
    cin >> n >> m;
    vector<int> x(n + 1);
    vector<int> pos(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> x[i];
        pos[x[i]] = i;
    }
    pos[0] = n + 1;

    int rounds = 0;
    for (int p = 1; p <= n; p++) {
        rounds += pos[p] < pos[p - 1];
    }

    while (m--) {
        int a, b;
        cin >> a >> b;

        set<int> check{x[a], x[a] + 1, x[b], x[b] + 1};
        for (int p : check) {
            rounds -= pos[p] < pos[p - 1];
        }
        swap(pos[x[a]], pos[x[b]]);
        swap(x[a], x[b]);
        for (int p : check) {
            rounds += pos[p] < pos[p - 1];
        }

        cout << rounds << '\n';
    }

    return 0;
}