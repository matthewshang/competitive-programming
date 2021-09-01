#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    for (int test_case = 1; test_case <= T; test_case++) {
        string S;
        cin >> S;
        int n = S.size();
        int K;
        cin >> K;

        constexpr int INF = 1e9;
        array<array<int, 26>, 26> g{};
        for (int i = 0; i < 26; i++) {
            for (int j = 0; j < 26; j++) {
                g[i][j] = INF;
            }
        }
        for (int i = 0; i < K; i++) {
            string E;
            cin >> E;
            g[E[0] - 'A'][E[1] - 'A'] = 1;
        }

        for (int k = 0; k < 26; k++) {
            for (int i = 0; i < 26; i++) {
                for (int j = 0; j < 26; j++) {
                    if (g[i][j] > g[i][k] + g[k][j]) {
                        g[i][j] = g[i][k] + g[k][j];
                    }
                }
            }
        }

        int min_time = INF;
        for (char end = 'A'; end <= 'Z'; end++) {
            int time = 0;
            for (int i = 0; i < n; i++) {
                if (S[i] == end) continue;
                int replacement_time = g[S[i] - 'A'][end - 'A'];
                if (replacement_time == INF) {
                    time = INF;
                    break;
                }
                time += replacement_time;
            }
            min_time = min(min_time, time);
        }
        if (min_time == INF) {
            min_time = -1;
        }
        cout << "Case #" << test_case << ": " << min_time << '\n';
    }

    return 0;
}