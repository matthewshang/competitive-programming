#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int64_t a, b, c, d; cin >> a >> b >> c >> d;
    double s = (a + b + c + d) / 2.0;
    double area = (s - a) * (s - b) * (s - c) * (s - d);
    area = sqrt(area);
    cout << setprecision(6) << fixed << area << '\n';

    return 0;
}
