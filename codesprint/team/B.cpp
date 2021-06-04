#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    int T;
    cin >> T;
    vector<int> t(N);
    for (int i = 0; i < N; i++) {
        cin >> t[i];
    }
    sort(t.begin(), t.end());
    
    for (int i = 1; i < N; i++) {
        if (T * i >= t[i]) {
            cout << "NO" << '\n';
            return 0;
        }
    }
    cout << "YES" << '\n';

    return 0;
}
