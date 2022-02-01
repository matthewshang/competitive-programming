#include "bits/stdc++.h"
using namespace std;

/* Date: 2022-01-29
 * Source: UW 2022
 * Summary: Count intersections on the segment from x0,y0 to x1,y1.
 */

// Source: KACTL
template <class T> int sgn(T x) { return (x > 0) - (x < 0); }
template<class T>
struct Point {
	typedef Point P;
	T x, y;
	explicit Point(T x=0, T y=0) : x(x), y(y) {}
	P operator+(P p) const { return P(x+p.x, y+p.y); }
	P operator-(P p) const { return P(x-p.x, y-p.y); }
	P operator*(T d) const { return P(x*d, y*d); }
	P operator/(T d) const { return P(x/d, y/d); }
	T cross(P p) const { return x*p.y - y*p.x; }
	T cross(P a, P b) const { return (a-*this).cross(b-*this); }
};

using pt = Point<float>;

// Source: KACTL
template<class P>
pair<int, P> lineInter(P s1, P e1, P s2, P e2) {
	auto d = (e1 - s1).cross(e2 - s2);
	if (d == 0) // if parallel
		return {-(s1.cross(e1, s2) == 0), P(0, 0)};
	auto p = s2.cross(e1, e2), q = s2.cross(e2, s1);
	return {1, (s1 * p + e1 * q) / d};
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    float x0, y0, x1, y1;
    cin >> x0 >> y0 >> x1 >> y1;
    int n;
    cin >> n;
    int crosses = 0;
    for (int i = 0; i < n; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        pt s0(x0, y0);
        pt s1(x1, y1);
        pt t0, t1;
        if (b == 0) {
            t0.x = t1.x = float(c) / float(a);
            t0.y = 0;
            t1.y = 1;
        } else {
            t0.x = 0;
            t0.y = float(c) / float(b);
            t1.x = 1;
            t1.y = float(c - a) / float(b);
        }

        auto [has, p] = lineInter(s0, s1, t0, t1);
        if (has && min(x0, x1) < p.x && p.x < max(x0, x1) && min(y0, y1) < p.y && p.y < max(y0, y1)) {
            crosses++;
        }
    }
    cout << crosses << '\n';

    return 0;
}