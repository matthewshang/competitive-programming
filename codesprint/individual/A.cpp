#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;

        int s = 1;
        while (s * 7 % 10 != N % 10) {
            s++;
        }
        if (s * 7 > N) {
            cout << -1 << '\n';
        } else {
            cout << s << '\n';
        }
    }

    return 0;
}