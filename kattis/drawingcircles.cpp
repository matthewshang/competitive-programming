#include <bits/stdc++.h>
using namespace std;

using Float = double;
constexpr Float EPS = 1e-9;
const Float PI = acos(-1);

// Source: https://cp-algorithms.com/geometry/circle-line-intersection.html
bool circle_line(Float r, Float a, Float b, Float c, pair<pair<Float, Float>, pair<Float, Float>>& res) {
    Float x0 = -a*c/(a*a+b*b), y0 = -b*c/(a*a+b*b);
    if (c*c > r*r*(a*a+b*b)+EPS) {
        return false;
    } else if (abs (c*c - r*r*(a*a+b*b)) < EPS) {
        return false;
    }
    else {
        Float d = r*r - c*c/(a*a+b*b);
        Float mult = sqrt (d / (a*a+b*b));
        Float ax, ay, bx, by;
        ax = x0 + b * mult;
        bx = x0 - b * mult;
        ay = y0 - a * mult;
        by = y0 + a * mult;

        res = {{ax, ay}, {bx, by}};
        return true;
    }
}

bool circle_circle(int x0, int y0, int r0, int x1, int y1, int r1, pair<Float, Float>& res) {
    x1 -= x0;
    y1 -= y0;
    pair<pair<Float, Float>, pair<Float, Float>> points;
    bool ok = circle_line(r1, -2 * x1, -2 * y1, x1 * x1 + y1 * y1 + r0 * r0 - r1 * r1, points);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    vector<int> x;
    vector<int> y;
    vector<int> r;
    for (int i = 0; i < N; i++) {
        cin >> x[i] >> y[i] >> r[i];
    }

    vector<vector<pair<Float, int>>> event(N);
    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {

        }
    }

    Float total_length;
    for (int i = 0; i < N; i++) {
        if (event[i].empty()) {
            total_length += 2 * PI * r[i];
            continue;
        }

        sort(event[i].begin(), event[i].end());
        int active = 0;
        Float length = 0;
        Float last_angle = 0;
        for (auto [angle, type] : event[i]) {
            // -1 = open, +1 = close
            if (active == 0) {
                length += angle - last_angle;
            }
            active += -type;
            if (active == 0) {
                last_angle = angle;
            }
        }
        length += event[i].front().first;
        length += 2 * PI - event[i].back().first;
        total_length += length * r[i];
    }

    cout << fixed << setprecision(6) << total_length << '\n';

    return 0;
}