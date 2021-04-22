#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N; cin >> N;
    int M = 0;
    vector<int> d;
    while (N) {
        d.push_back(N % 2);
        N /= 2;
    }
    reverse(d.begin(), d.end());
    for (int i = 0; i < d.size(); i++) {
        M += d[i] * (1 << i);
    }
    cout << M << '\n';

    return 0;
}
