#include "bits/stdc++.h"
using namespace std;

const int N = 100;
const int Q = 10000;

int solve(vector<string>& c) {
    vector<int> D(Q);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < Q; j++) {
            if (c[i][j] == '1') {
                D[j]++;
            }
        }
    }

    const int HARD = 10;
    vector<int> hard_count(N);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < Q; j++) {
            if (c[i][j] == '1' && D[j] <= HARD) {
                hard_count[i]++;
            }
        }
    }
    return max_element(hard_count.begin(), hard_count.end()) - hard_count.begin();
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<string> choices(N);
    int T, P; cin >> T >> P;
    for (int tc = 1; tc <= T; tc++) {
        for (int i = 0; i < N; i++) {
            cin >> choices[i];
        }
        cout << "Case #" << tc << ": " << solve(choices) << '\n';
    }
    
    return 0;
}
