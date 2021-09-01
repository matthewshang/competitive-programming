#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    for (int test_case = 1; test_case <= T; test_case++) {
        int N;
        cin >> N;
        vector<string> C(N);
        for (int i = 0; i < N; i++) {
            cin >> C[i];
        }

        vector<int> added_for_row(N);
        vector<int> added_for_col(N);
        vector<int> ways(N + 1);
        for (int row = 0; row < N; row++) {
            int added = 0;
            for (int col = 0; col < N; col++) {
                if (C[row][col] == 'O') {
                    added = -1;
                    break;
                } else if (C[row][col] == '.') {
                    added++;
                }
            }
            if (added != -1) {
                ways[added]++;
            }
            added_for_row[row] = added;
        }

        for (int col = 0; col < N; col++) {
            int added = 0;
            for (int row = 0; row < N; row++) {
                if (C[row][col] == 'O') {
                    added = -1;
                    break;
                } else if (C[row][col] == '.') {
                    added++;
                }
            }
            if (added != -1) {
                ways[added]++;
            }
            added_for_col[col] = added;
        }

        for (int row = 0; row < N; row++) {
            for (int col = 0; col < N; col++) {
                if (added_for_row[row] == 1 && added_for_col[col] == 1 && C[row][col] == '.') {
                    ways[1]--;
                }
            }
        }

        int min_xs = -1;
        for (int i = 1; i <= N; i++) {
            if (ways[i] > 0) {
                min_xs = i;
                break;
            }
        }
        cout << "Case #" << test_case << ": ";
        if (min_xs == -1) {
            cout << "Impossible\n";
        } else {
            cout << min_xs << " " << ways[min_xs] << '\n';
        }
    }

    return 0;
}