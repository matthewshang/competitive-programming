#include "bits/stdc++.h"
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    array<int, 31> stops{};
    stops[1] = 1;
    for (int i = 2; i <= 30; i++) {
        stops[i] = stops[i - 1] * 2 + 1;
    }

    int T; cin >> T;
    while (T--) {
        int k; cin >> k;
        cout << stops[k] << '\n';
    }
}