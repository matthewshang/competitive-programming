#include "bits/stdc++.h"
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int K, N; cin >> K >> N;
    vector<int> cnt(K + 1);
    for (int i = 0; i < N; i++) {
        int S; cin >> S;
        cnt[S]++;
    }

    auto check = [&]() -> bool {
        for (int i = 1; i <= K - 1; i++) {
            if (cnt[i] != cnt[i + 1]) {
                return false;
            }
        }
        return true;
    };

    for (int add = 1; add <= K; add++) {
        cnt[add]++;
        if (check()) {
            cout << '+' << add << '\n';
            return 0;
        }
        cnt[add]--;
    }

    for (int sub = 1; sub <= K; sub++) {
        cnt[sub]--;
        if (check()) {
            cout << '-' << sub << '\n';
            return 0;
        }
        cnt[sub]++;
    }

    for (int add = 1; add <= K; add++) {
        cnt[add]++;
        for (int sub = 1; sub <= K; sub++) {
            cnt[sub]--;
            if (check()) {
                cout << '-' << sub << " +" << add << '\n';
                return 0;
            }
            cnt[sub]++;
        }
        cnt[add]--;
    }
    cout << "*\n";

    return 0;
}