#include <bits/stdc++.h>
using namespace std;

// Doubly linked list.

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> next(n + 1);
    vector<int> prev(n + 1);
    iota(next.begin(), next.end(), 1);
    iota(prev.begin(), prev.end(), -1);
    next[n] = 1;
    prev[1] = n;

    int cur = next[1];
    for (int i = 0; i < n; i++) {
        cout << cur << " ";
        int tmp = cur;
        cur = next[tmp];
        int prev_tmp = prev[tmp];
        int next_tmp = next[tmp];
        next[prev_tmp] = next_tmp;
        prev[next_tmp] = prev_tmp;
        cur = next[cur];
    }
    cout << '\n';

    return 0;
}
