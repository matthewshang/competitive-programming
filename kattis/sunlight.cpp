#include "bits/stdc++.h"

using namespace std;

struct pt {
    int64_t x, y;
};

bool cw(const pt& a, const pt& b, const pt& c) {
    return a.x * (b.y - c.y) + b.x * (c.y - a.y) + c.x * (a.y - b.y) < 0;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N; cin >> N;
    vector<pt> a(N);
    for (int i = 0; i < N; i++) {
        cin >> a[i].x >> a[i].y;
    }

    vector<double> sun(N);

    const double PI = acos(-1);
    auto convex_hull = [&]() {
        sun[0] += 0.5;
        vector<pt> up;
        up.push_back(a[0]);
        for (int i = 1; i < N; i++) {
            while (up.size() >= 2 && !cw(up[up.size() - 2], up[up.size() - 1], a[i])) {
                up.pop_back();
            }
            if (up.back().y > a[i].y) {
                double theta = atan(double(a[i].x - up.back().x) / (up.back().y - a[i].y));
                sun[i] += theta / PI;
            } else {
                sun[i] += 0.5;
            }
            up.push_back(a[i]);
        }
    };

    convex_hull();

    int64_t mx = 0;
    for (int i = 0; i < N; i++) {
        mx = max(mx, a[i].x);
    }
    mx++;
    for (int i = 0; i < N; i++) {
        a[i].x = mx - a[i].x;
    }
    reverse(a.begin(), a.end());
    reverse(sun.begin(), sun.end());
    convex_hull();
    reverse(sun.begin(), sun.end());

    for (int i = 0; i < N; i++) {
        cout << fixed << setprecision(4) << (sun[i] * 12.0) << '\n';
    }

    return 0;
}