// pt start
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
// pt end

// isect start
template<typename T> int sgn(const T& x) { 
    return (T{0} < x) - (x < T{0});
}

bool on_segment(pt a, pt b, pt p) {
    return a.cross(b, p) == 0 && (a - p).dot(b - p) <= 0;
}

bool proper_inter(pt a, pt b, pt c, pt d, pt& out) {
    double oa = c.cross(d, a),
           ob = c.cross(d, b),
           oc = a.cross(b, c),
           od = a.cross(b, d);
    if (oa * ob < 0 && oc * od < 0) {
        out = (a * ob - b * oa) / (ob - oa);
        return true;
    }
    return false;
}

set<pt> seg_inter(pt a, pt b, pt c, pt d) {
    pt out;
    if (proper_inter(a, b, c, d, out)) return {out};
    set<pt> s;
    if (on_segment(c, d, a)) s.insert(a);
    if (on_segment(c, d, b)) s.insert(b);
    if (on_segment(a, b, c)) s.insert(c);
    if (on_segment(a, b, d)) s.insert(d);
    return s;
}
// isect end

// polygon start
bool crosses_ray(pt a, pt b, pt p) {
    return ((b.y >= p.y) - (a.y >= p.y)) * p.cross(a, b) > 0;
}

bool on_segment(pt a, pt b, pt p) {
    return a.cross(b, p) == 0 && (a - p).dot(b - p) <= 0;
}

// returns -1 for out, 0 for boundary, 1 for in
int in_polygon(const vector<pt>& p, pt a) {
    int crossings = 0;
    for (int i = 0, n = p.size(); i < n; i++) {
        if (on_segment(p[i], p[(i + 1) % n], a)) {
            return 0;
        }
        crossings += crosses_ray(p[i], p[(i + 1) % n], a);
    }
    return crossings % 2 ? 1 : -1;
}
// polygon end
