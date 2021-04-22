#include <bits/stdc++.h>
using namespace std;

struct pt {
    double x, y;
};

const double EPS = 1E-9;

pt add(pt a, pt b) {
    return pt{ a.x + b.x, a.y + b.y };
}

pt sub(pt a, pt b) {
    return pt{ a.x - b.x, a.y - b.y };
}

bool cw(pt a, pt b, pt c) {
    return a.x*(b.y-c.y)+b.x*(c.y-a.y)+c.x*(a.y-b.y) < 0;
}

struct line {
    double a, b, c;

    line() {}
    line(pt p, pt q)
    {
        a = p.y - q.y;
        b = q.x - p.x;
        c = -a * p.x - b * p.y;
        norm();
    }

    void norm()
    {
        double z = sqrt(a * a + b * b);
        if (abs(z) > EPS)
            a /= z, b /= z, c /= z;
    }

    double dist(pt p) const { return a * p.x + b * p.y + c; }
};

double det(double a, double b, double c, double d) {
    return a*d - b*c;
}

double dist(pt a) {
    return a.x * a.x + a.y * a.y;
}

double dot(pt a, pt b) {
    return a.x * b.x + a.y * b.y;
}

double theta(pt a, pt b, pt c) {
    pt ba = sub(a, b);
    pt bc = sub(c, b);
    return acos(dot(ba, bc) / sqrt(dist(ba)) / sqrt(dist(bc)));
}

bool intersect(line m, line n, pt& res) {
    double zn = det(m.a, m.b, n.a, n.b);
    if (abs(zn) < EPS)
        return false;
    res.x = -det(m.c, m.b, n.c, n.b) / zn;
    res.y = -det(m.a, m.c, n.a, n.c) / zn;
    return true;
}

const double PI = 3.14159265358979323846;
const double c60 = cos(PI / 3);
const double s60 = sin(PI / 3);

pt rot60(pt v) {
    return pt{ v.x * c60 - v.y * s60, v.x * s60 + v.y * c60 };
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    pt a, b, c;
    cin >> a.x >> a.y >> b.x >> b.y >> c.x >> c.y;
    if (!cw(a, b, c)) {
        swap(b, c);
    }

    if (theta(c, a, b) >= 2 * PI / 3) {
        cout << fixed << setprecision(4) << a.x << ' ' << a.y << '\n';
        return 0;
    }
    if (theta(a, b, c) >= 2 * PI / 3) {
        cout << fixed << setprecision(4) << b.x << ' ' << b.y << '\n';
        return 0;
    }
    if (theta(b, c, a) >= 2 * PI / 3) {
        cout << fixed << setprecision(4) << c.x << ' ' << c.y << '\n';
        return 0;
    }

    pt d = add(a, rot60(sub(b, a)));
    pt e = add(b, rot60(sub(c, b)));

    pt fermat;
    intersect(line(d, c), line(e, a), fermat);
    cout << fixed << setprecision(4) << fermat.x << ' ' << fermat.y << '\n';

    return 0;
}
