#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    auto is_vowel = [](char c) -> bool {
        return c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U';
    };

    int T;
    cin >> T;
    for (int test_case = 1; test_case <= T; test_case++) {
        string S;
        cin >> S;
        int n = S.size();
        int min_cost = 2 * n;
        for (char end = 'A'; end <= 'Z'; end++) {
            int cost = 0;
            for (int i = 0; i < n; i++) {
                if (S[i] == end) continue;
                cost += is_vowel(S[i]) == is_vowel(end) ? 2 : 1;
            }
            min_cost = min(min_cost, cost);
        }
        cout << "Case #" << test_case << ": " << min_cost << '\n';
    }

    return 0;
}