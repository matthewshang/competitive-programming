#include <bits/stdc++.h>
using namespace std;

struct pt {
    double x, y;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    pt as, ad, bs, bd;
    cin >> as.x >> as.y;
    cin >> ad.x >> ad.y;
    cin >> bs.x >> bs.y;
    cin >> bd.x >> bd.y;
    ad.x -= as.x;
    ad.y -= as.y;
    bd.x -= bs.x;
    bd.y -= bs.y;

    double dx = bs.x - as.x;
    double dy = bs.y - as.y;
    double det = bd.x * ad.y - bd.y * ad.x;
    if (det == 0) {
        cout << -1 << '\n';
        return 0;
    }

    double u = (dy * bd.x - dx * bd.y) / det;
    double v = (dy * ad.x - dx * ad.y) / det;
    if (u >= 0 && v >= 0) {
        int64_t x = floor(as.x + ad.x * u);
        int64_t y = floor(as.y + ad.y * u);
        cout << x << ' ' << y << '\n';
    } else {
        cout << -1 << '\n';
    }

    return 0;
}
