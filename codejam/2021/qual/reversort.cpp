#include "bits/stdc++.h"
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T; cin >> T;
    for (int tc = 1; tc <= T; tc++) {
        int N; cin >> N;
        vector<int> L(N);
        for (int i = 0; i < N; i++) {
            cin >> L[i];
        }

        int cost = 0;
        for (int i = 0; i < N - 1; i++) {
            int j = min_element(L.begin() + i, L.end()) - L.begin();
            cost += j - i + 1;
            reverse(L.begin() + i, L.begin() + j + 1);
        }
        cout << "Case #" << tc << ": " << cost << '\n';
    }
    
    return 0;
}