#include <bits/stdc++.h>
using namespace std;

struct edge {
    int d, i, j;
    bool operator<(const edge& e) {
        return d < e.d;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    vector<int> x(N);
    vector<int> y(N);
    for (int i = 0; i < N; i++) {
        cin >> x[i] >> y[i];
    }

    vector<edge> edges;
    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            edges.push_back({ abs(x[i] - x[j]) + abs(y[i] - y[j]), i, j });
        }
    }
    sort(edges.begin(), edges.end());

    vector<int> par(N);
    iota(par.begin(), par.end(), 0);
    function<int(int)> find = [&](int x) -> int {
        if (par[x] != x) par[x] = find(par[x]);
        return par[x];
    };

    int time = 0;
    for (const auto& e : edges) {
        int a = find(e.i);
        int b = find(e.j);
        if (a != b) {
            time += e.d;
            par[b] = a;
        }
    }
    cout << (time * 2) << '\n';

    return 0;
}
