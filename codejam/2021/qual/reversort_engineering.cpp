#include "bits/stdc++.h"
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T; cin >> T;
    for (int tc = 1; tc <= T; tc++) {
        int N, C; cin >> N >> C;
        if (C < N - 1 || C > N * (N - 1) / 2 + N - 1) {
            cout << "Case #" << tc << ": IMPOSSIBLE\n";
            continue;
        }

        vector<int> pos(N - 1, 1);
        pos[0] += C - (N - 1);
        for (int i = 0; i < N - 2; i++) {
            if (pos[i] > N - i) {
                pos[i + 1] += pos[i] - (N - i);
                pos[i] = N - i;
            }
        }

        vector<int> a(N);
        iota(a.begin(), a.end(), 1);
        for (int i = N - 2; i >= 0; i--) {
            reverse(a.begin() + i, a.begin() + pos[i] + i);
        }
        cout << "Case #" << tc << ":";
        for (int i = 0; i < N; i++) {
            cout << ' ' << a[i];
        }
        cout << '\n';
    }
    
    return 0;
}