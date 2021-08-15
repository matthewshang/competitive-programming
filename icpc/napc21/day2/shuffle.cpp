#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    auto convert = [&](char c) -> int {
        if (c == '_') return 26;
        else return c - 'A';
    };

    int l = ceil(log2(2e9));
    vector<vector<int>> down(27, vector<int>(l + 1));
    for (int v = 0; v < 27; v++) {
        char c;
        cin >> c;
        down[v][0] = convert(c);
    }

    for (int i = 1; i <= l; i++) {
        for (int v = 0; v < 27; v++) {
            down[v][i] = down[down[v][i - 1]][i - 1];
        }
    }

    int N;
    cin >> N;
    string T;
    cin >> T;
    for (char c : T) {
        int v = convert(c);
        for (int i = l; i >= 0; i--) {
            if (N & (1 << i)) {
                v = down[v][i];
            }
        }

        if (v == 26) c = '_';
        else c = 'A' + v;
        cout << c;
    }
    cout << '\n';

    return 0;
}