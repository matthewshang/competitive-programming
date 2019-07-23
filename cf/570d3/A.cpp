#include "bits/stdc++.h"

using namespace std;

using ll = long long;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin >> n;

    while (true) {
        int s = n / 1000 + (n % 1000) / 100 + (n % 100) / 10 + (n % 10);
        if (s % 4 == 0) {
            cout << n << endl;
            break;
        }
        n++;
    }

    return 0;
}
