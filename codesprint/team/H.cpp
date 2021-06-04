#include <bits/stdc++.h>
using namespace std;

int go(int who, int n, int turn) {
    if (n == 0) {
        return 1 - who;
    }
    for (int i = 1; i <= turn; i++) {
        if (go(1 - who, n - i, turn + 1) == who) {
            return who;
        }
    }
    return 1 - who;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    bool A = true;
    int m = 1;
    for (int i = 2; m < N; i++) {
        A = false;
        m += i;
        if (N <= m) break;
        A = true;
        m += i;
        if (N <= m) break;
    }
    cout << (A ? "YES" : "NO") << '\n';

    return 0;
}
