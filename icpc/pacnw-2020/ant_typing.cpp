#include "bits/stdc++.h"
using namespace std;

// Precompute distances in the input string and then try all permutations
// of 1..9 for the keyboard.

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    cin >> s;
    array<array<int, 10>, 10> count{};
    for (int i = 0; i < s.size() - 1; i++) {
        int a = s[i] - '0';
        int b = s[i + 1] - '0';
        count[a][b]++;
    }

    array<int, 9> p;
    int min_time = 1e9;
    iota(p.begin(), p.end(), 1);
    do {
        array<int, 10> pos;
        for (int i = 0; i < 9; i++) {
            pos[p[i]] = i;
        }

        int time = 0;
        for (int a = 1; a <= 9; a++) {
            for (int b = 1; b <= 9; b++) {
                time += (abs(pos[b] - pos[a]) + 1) * count[a][b];
            }
        }
        time += pos[s[0] - '0'] + 1;
        min_time = min(min_time, time);
    } while (next_permutation(p.begin(), p.end()));

    cout << min_time << '\n';
    return 0;
}