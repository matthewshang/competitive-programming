#include <bits/stdc++.h>
using namespace std;

template<typename T>
struct Point {
    T x, y;
    explicit Point(T x=0, T y=0) : x{x}, y{y} {}
    bool operator<(const Point& p) const { return make_pair(x, y) < make_pair(p.x, p.y); }
    bool operator==(const Point& p) const { return x == p.x && y == p.y; }
    Point operator+(const Point& p) const { return Point(x + p.x, y + p.y); }
    Point operator-(const Point& p) const { return Point(x - p.x, y - p.y); }
    Point operator*(T s) const { return Point(x * s, y * s); }
    Point operator/(T s) const { return Point(x / s, y / s); }
    T dot(const Point& p) const { return x * p.x + y * p.y; }
    T cross(const Point& p) const { return x * p.y - y * p.x; }
    T cross(const Point& a, const Point& b) const { return (a - *this).cross(b - *this); }
    T sq() const { return x * x + y * y; }
    double abs() const { return sqrt(static_cast<double>(sq())); }
    double angle() const { return atan2(y, x); }
};
template<typename T> Point<T> operator*(T s, const Point<T>& p) { return p * s; }
template<typename T> ostream& operator<<(ostream& os, const Point<T>& p) {
    return os << "(" << p.x << "," << p.y << ")";
}
template<typename T> istream& operator>>(istream& is, Point<T>& p) {
    return is >> p.x >> p.y;
}

using pt = Point<int64_t>;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        pt a, b, c;
        cin >> a >> b >> c;
        int64_t v = a.cross(b, c);
        if (v == 0) {
            cout << "TOUCH" << '\n';
        } else if (v < 0) {
            cout << "RIGHT" << '\n';
        } else {
            cout << "LEFT" << '\n';
        }
    }

    return 0;
}