#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int D, R, T; cin >> D >> R >> T;
    for (int age = 0; age < 100; age++) {
        int big = age + D;
        int total = age * (age + 1) / 2 + big * (big + 1) / 2 - 9;
        if (total == R + T) {
            int rem = R - (big * (big + 1) / 2 - 6);
            cout << rem << '\n';
            break;
        }
    }

    return 0;
}
