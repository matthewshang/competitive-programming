#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> g(2 * n + 1);
    vector<int> in(2 * n + 1);
    vector<int> take(2 * n + 1, -1);
    for (int v = 1; v <= 2 * n; v++) {
        cin >> g[v];
        in[g[v]]++;
    }

    queue<int> todo;
    for (int v = 1; v <= 2 * n; v++) {
        if (in[v] == 0) todo.push(v);
    }

    auto process = [&]() {
        while (!todo.empty()) {
            int v = todo.front();
            todo.pop();
            take[v] = 1;
            int to = g[v];
            if (take[to] == -1) {
                take[to] = 0;
                in[g[to]]--;
                if (in[g[to]] == 0) {
                    todo.push(g[to]);
                }
            }
        }
    };

    process();

    for (int v = 1; v <= 2 * n; v++) {
        if (take[v] == -1) {
            todo.push(v);
            process();
        }
    }

    for (int v = 1; v <= 2 * n; v++) {
        if (take[v] == 1) {
            cout << v << ' ';
        }
    }
    cout << '\n';

    return 0;
}