#include "bits/stdc++.h"

using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int T; cin >> T;
    for (int test_case = 1; test_case <= T; test_case++) {
        int R, C; cin >> R >> C;
        long long total = 0;
        vector<vector<int>> S(R, vector<int>(C));
        vector<vector<int>> right(R, vector<int>(C, -1));
        vector<vector<int>> left(R, vector<int>(C, -1));
        vector<vector<int>> up(R, vector<int>(C, -1));
        vector<vector<int>> down(R, vector<int>(C, -1));

        for (int i = 0; i < R; i++) {
            for (int j = 0; j < C; j++) {
                cin >> S[i][j];
                total += S[i][j];
                if (j > 0) left[i][j] = j - 1;
                if (j < C - 1) right[i][j] = j + 1;
                if (i > 0) down[i][j] = i - 1;
                if (i < R - 1) up[i][j] = i + 1;
            }
        }

        auto dead = [&](int i, int j) -> bool {
            int neighbors = 0;
            int skill = 0;
            if (left[i][j] != -1) {
                neighbors++;
                skill += S[i][left[i][j]];
            }
            if (right[i][j] != -1) {
                neighbors++;
                skill += S[i][right[i][j]];
            }
            if (down[i][j] != -1) {
                neighbors++;
                skill += S[down[i][j]][j];
            }
            if (up[i][j] != -1) {
                neighbors++;
                skill += S[up[i][j]][j];
            }
            return S[i][j] * neighbors < skill;
        };

        long long sum = total;
        vector<array<int, 2>> todo;
        for (int i = 0; i < R; i++) {
            for (int j = 0; j < C; j++) {
                if (dead(i, j)) {
                    todo.push_back({ i, j });
                }
            }
        }

        vector<vector<bool>> seen(R, vector<bool>(C, false));
        int start = 0;
        while (start < int(todo.size())) {
            int cur_end = todo.size();
            int eliminated = 0;
            vector<array<int, 2>> check;
            while (start < cur_end) {
                auto [i, j] = todo[start];
                start++;
                if (seen[i][j]) {
                    continue;
                }
                seen[i][j] = true;

                total -= S[i][j];
                eliminated++;
                if (left[i][j] != -1) {
                    right[i][left[i][j]] = right[i][j];
                    check.push_back({ i, left[i][j] });
                }
                if (right[i][j] != -1) {
                    left[i][right[i][j]] = left[i][j];
                    check.push_back({ i, right[i][j] });
                }
                if (down[i][j] != -1) {
                    up[down[i][j]][j] = up[i][j];
                    check.push_back({ down[i][j], j });
                }
                if (up[i][j] != -1) {
                    down[up[i][j]][j] = down[i][j];
                    check.push_back({ up[i][j], j });
                }
            }
            if (eliminated > 0) {
                sum += total;
            }

            for (auto [i, j] : check) {
                if (dead(i, j) && !seen[i][j]) {
                    todo.push_back({ i, j });
                }
            }
        }
        cout << "Case #" << test_case << ": " << sum << '\n';
    }

    return 0;
}