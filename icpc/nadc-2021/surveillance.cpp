#include <bits/stdc++.h>
using namespace std;

// Impossible geometry problem. Make an observation that the boundary of the
// region in each corner is a parabola. Then the idea is pretty simple.
// Through some math we can get the equation of the parabola and integrate
// it for the area, being careful to handle the orientation and translation
// of the room and the rightmost wall clipping the region.

// Find smallest root of ax^2+bx+c=0.
double quad(int64_t a, int64_t b, int64_t c) {
    double D = b * b - 4 * a * c;
    assert(D >= 0);
    return (-b - sqrt(D)) / (2.0 * a);
}

double solve(vector<int>& x, vector<int>& y) {
    int64_t a = -1 * *min_element(x.begin(), x.end());
    int64_t b = *max_element(y.begin(), y.end());
    int64_t c = *max_element(x.begin(), x.end());
    int64_t d = -1 * *min_element(y.begin(), y.end());

    double x0 = double(a * d) / b;
    double z1 = a;
    if (x0 > c) {
        z1 = quad(d, -2 * a * d, a * b * c);
    }
    double x1 = (2 * a - z1) * z1 * d / (a * b);

    // integrate y=k*sqrt(x) from x0-x1 to x0 where k = d/sqrt(x0)
    double rs = sqrt(x0 - x1);
    double re = sqrt(x0);
    double k = d / re;
    double A = k * 2 * (re * re * re - rs * rs * rs) / 3;
    return A;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> x(n);
    vector<int> y(n);
    for (int i = 0; i < n; i++) {
        cin >> x[i] >> y[i];
    }

    int max_x = *max_element(x.begin(), x.end());
    int min_x = *min_element(x.begin(), x.end());
    int max_y = *max_element(y.begin(), y.end());
    int min_y = *min_element(y.begin(), y.end());

    if (n == 4) {
        int A = (max_x - min_x) * (max_y - min_y);
        cout << fixed << setprecision(6) << A << '\n';
        return 0;
    }

    // Rotate the corners so that the inside corner is the first element.
    while (x[0] == max_x || x[0] == min_x || y[0] == max_y || y[0] == min_y) {
        rotate(x.begin(), x.begin() + 1, x.end());
        rotate(y.begin(), y.begin() + 1, y.end());
    }

    // Translate everything so the inside corner is (0,0).
    for (int i = 1; i < n; i++) {
        x[i] -= x[0];
        y[i] -= y[0];
    }
    x[0] = y[0] = 0;

    // Rotate so the corner faces the first quadrant.
    while (!(x[0] == x[1] && y[0] < y[1])) {
        for (int i = 0; i < n; i++) {
            y[i] = -y[i];
            swap(x[i], y[i]);
        }
    }

    double A = *min_element(x.begin(), x.end()) * *min_element(y.begin(), y.end());
    A += solve(x, y);
    // Flip everything along y=x and solve second corner.
    swap(x, y);
    A += solve(x, y);

    cout << fixed << setprecision(6) << A << '\n';

    return 0;
}
