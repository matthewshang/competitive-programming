#include "bits/stdc++.h"

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin >> n;
    vector<int> code = {0};
    for (int i = 1; i <= n; i++) {
        for (int j = (int)code.size() - 1; j >= 0; j--) {
            code.push_back(code[j] + (1 << (i - 1)));
        }
    }

    for (int x : code) {
        for (int i = n - 1; i >= 0; i--) {
            cout << ((x & (1 << i)) >> i);
        }
        cout << '\n';
    }
}