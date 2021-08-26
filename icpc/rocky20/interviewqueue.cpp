#include "bits/stdc++.h"

using namespace std;

/* Date: 2021-03-30
 * Source: Rocky Mountains 2020
 */

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N; cin >> N;
    vector<int> v(N);
    for (int i = 0; i < N; i++) {
        cin >> v[i];
    }

    vector<int> l(N);
    iota(l.begin(), l.end(), -1);
    vector<int> r(N);
    iota(r.begin(), r.end(), 1);
    r[N - 1] = -1;

    auto will_leave = [&](int i) -> bool {
        if (l[i] != -1 && v[l[i]] > v[i]) return true;
        if (r[i] != -1 && v[r[i]] > v[i]) return true;
        return false;
    };

    vector<int> todo;
    vector<bool> out(N);
    int head = 0;
    for (int i = 0; i < N; i++) {
        if (will_leave(i)) {
            todo.push_back(i);
            out[i] = true;
        }
    }

    vector<vector<int>> left;
    while (head < int(todo.size())) {
        int tail = todo.size();
        for (int j = head; j < tail; j++) {
            int i = todo[j];
            if (l[i] != -1) {
                r[l[i]] = r[i];
            }
            if (r[i] != -1) {
                l[r[i]] = l[i];
            }
        }

        vector<int> order;
        for (; head < tail; head++) {
            int i = todo[head];
            order.push_back(v[i]);
            if (l[i] != -1 && !out[l[i]] && will_leave(l[i])) {
                out[l[i]] = true;
                todo.push_back(l[i]);
            } 
            if (r[i] != -1 && !out[r[i]] && will_leave(r[i])) {
                out[r[i]] = true;
                todo.push_back(r[i]);
            }
        }
        left.push_back(order);
    }

    cout << left.size() << '\n';
    for (const auto& who : left) {
        for (int x : who) {
            cout << x << ' ';
        }
        cout << '\n';
    }
    for (int i = 0; i < N; i++) {
        if (!out[i]) {
            cout << v[i] << ' ';
        }
    }
    cout << '\n';

    return 0;
}