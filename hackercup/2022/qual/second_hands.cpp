#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    for (int tc = 1; tc <= T; tc++) {
        int N, K;
        cin >> N >> K;
        vector<int> count(101);
        for (int i = 0; i < N; i++) {
            int S;
            cin >> S;
            count[S]++;
        }

        cout << "Case #" << tc << ": "; 
        if (K * 2 < N || *max_element(count.begin(), count.end()) > 2) {
            cout << "NO\n";
        } else {
            cout << "YES\n";
        }
    }

    return 0;
}