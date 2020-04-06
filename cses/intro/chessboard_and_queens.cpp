// Chessboard and Queens

#include "bits/stdc++.h"
using namespace std;

int main() {
    array<string, 8> g;
    for (int i = 0; i < 8; i++)
        cin >> g[i];
    
    vector<int> pos;
    for (int i = 0; i < 8; i++)
        pos.push_back(i);

    auto good = [&]() -> bool {
        for (int i = 0; i < 8; i++)
            if (g[i][pos[i]] == '*')
                return false;

        int count = 0;
        for (int i = 0; i < 8; i++) if (i == pos[i]) count++;
        if (count > 1) return false;
        count = 0;
        for (int i = 0; i < 8; i++) if (7 - i == pos[i]) count++;
        if (count > 1) return false;

        for (int i = 1; i < 7; i++) {
            count = 0;
            for (int j = 0; j < 8 - i; j++) if (i + j == pos[j]) count++;
            if (count > 1) return false;
            count = 0;
            for (int j = 0; j < 8 - i; j++) if (j == pos[i + j]) count++;
            if (count > 1) return false;
            count = 0;
            for (int j = 0; j < 8 - i; j++) if (j == pos[7 - i - j]) count++;
            if (count > 1) return false;
            count = 0;
            for (int j = 0; j < 8 - i; j++) if (i + j == pos[7 - j]) count++;
            if (count > 1) return false;
        }

        return true;
    };
    
    int ans = 0;
    do {
        if (good()) ans++;
    } while (next_permutation(pos.begin(), pos.end()));

    cout << ans << endl;
    return 0;
}