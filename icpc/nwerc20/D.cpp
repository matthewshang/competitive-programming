#include <bits/stdc++.h>
using namespace std;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int rint(int a, int b) {
    return uniform_int_distribution<int>(a, b)(rng);
};

constexpr int MX = 1e6;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    auto query = [&](int x, int y) -> int64_t {
        cout << x << " " << y << endl;
        int64_t d;
        cin >> d;
        return d;
    };
    auto maybe = [&](int x, int y) -> bool {
        if (x < 0 || x > MX || y < 0 || y > MX) return false;
        return query(x, y) == 0;
    };

    for (int i = 0; i < n; i++) {
        int x = MX / 2 + rint(-10, 10);
        int y = MX / 2 + rint(-10, 10);
        int64_t d = query(x, y);
        for (int64_t j = 0; j * j <= d; j++) {
            int64_t a = d - j * j;
            int64_t s = sqrt(a);
            if (s * s == a) {
                if (maybe(x + j, y + s) || maybe(x + j, y - s) || maybe(x - j, y + s) || maybe(x - j, y - s)) {
                    break;
                }
            }
        }
    }

    return 0;
}
