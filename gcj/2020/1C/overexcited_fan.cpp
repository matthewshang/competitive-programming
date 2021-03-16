#include "bits/stdc++.h"

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T; cin >> T;
    for (int test_case = 1; test_case <= T; test_case++) {
        cout << "Case #" << test_case << ": ";
        []() {
            int X, Y; cin >> X >> Y;
            string M; cin >> M;

            int L = M.size();
            for (int t = 0; t <= L; t++) {
                if (abs(X) + abs(Y) <= t) {
                    cout << t << '\n';
                    return;
                }

                if (t < L) {
                    char d = M[t];
                    if (d == 'N') {
                        Y += 1;
                    } else if (d == 'S') {
                        Y -= 1;
                    } else if (d == 'E') {
                        X += 1;
                    } else {
                        X -= 1;
                    }
                }
            }
            cout << "IMPOSSIBLE\n";
        }();
    }
    
    return 0;
}