#include "bits/stdc++.h"

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T, N, M; cin >> T >> N >> M;
    auto query = [&](int num_blades) -> int {
        for (int i = 0; i < 18; i++) {
            cout << num_blades << ' ';
        }
        cout << endl;

        int sum = 0;
        for (int i = 0; i < 18; i++) {
            int x; cin >> x;
            if (x == -1) {
                exit(0);
            }
            sum += x;
        }
        return sum % num_blades;
    };

    array<int, 6> queries{5, 7, 11, 13, 17, 18};

    for (int tc = 1; tc <= T; tc++) {
        array<int, 6> ans{};
        for (int i = 0; i < 6; i++) {
            ans[i] = query(queries[i]);
        }

        for (int G = 1; G <= M; G++) {
            bool ok = true;
            for (int i = 0; i < 6; i++) {
                if (G % queries[i] != ans[i]) {
                    ok = false;
                    break;
                }
            }

            if (ok) {
                cout << G << endl;
                int res; cin >> res;
                if (res == -1) {
                    return 0;
                } else {
                    break;
                }
            }
        }
    }

    return 0;
}