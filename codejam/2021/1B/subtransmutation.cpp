#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T; cin >> T;
    for (int tc = 1; tc <= T; tc++) {
        [&]() {
            int N, A, B; cin >> N >> A >> B;
            vector<int> U(N + 1);
            for (int i = 0; i < N; i++) {
                cin >> U[i + 1];
            }

            auto check = [&](int X) -> bool {
                vector<int> c(X + 1);
                c[X] = 1;
                for (int i = X; i >= 1; i--) {
                    int use = c[i];
                    if (i <= N) {
                        if (c[i] < U[i]) {
                            return false;
                        }
                        use = c[i] - U[i];
                    }
                    if (i - B >= 1) {
                        c[i - B] += use;
                    }
                    if (i - A >= 1) {
                        c[i - A] += use;
                    }
                    c[i] -= use;
                }
                for (int i = 1; i <= N; i++) {
                    if (c[i] < U[i]) {
                        return false;
                    }
                }
                return true;
            };
            
            auto precheck = [&](int X) -> bool {
                // solve X - n*A - m*B = i
                // solve X - i = n*A + m*B
                for (int i = 1; i <= N; i++) {
                    if (U[i] > 0 && (X - i) % gcd(A, B) != 0) {
                        return false;
                    }
                }
                return true;
            };

            int hi = 0;
            for (int i = 1; i < 5000; i++) {
                if (!precheck(i)) {
                    continue;
                }
                hi++;
                if (check(i)) {
                    cout << "HI " << hi << ' ' << i << endl;
                    cout << "Case #" << tc << ": " << i << '\n';
                    return;
                }
            }
            cout << "Case #" << tc << ": IMPOSSIBLE\n";
        }();
    }

    return 0;
}
