/*
ID: mshang41
LANG: C++11
TASK: crypt1
*/

#include "bits/stdc++.h"

using namespace std;

#define ALL(v) (v).begin(), (v).end()

bool digits_in(int x, vector<int> &digits) {
    while (x > 0) {
        int d = x % 10;
        if (find(digits.begin(), digits.end(), d) == digits.end()) {
            return false;
        }
        x /= 10;
    }
    return true;
}

int test(int f, vector<int> &digits) {
    int count = 0;
    for (int d : digits) {
        int r = f * d;
        if (r > 999) break;
        if (!digits_in(r, digits)) continue;

        for (int e : digits) {
            int s = f * e;
            if (s > 999) break;
            if (!digits_in(s, digits)) continue;

            int p = s + 10 * r;
            if (r > 9999 || !digits_in(p, digits)) continue;

            cout << f << " * " << 10 * d + e << " = " << p << endl;
            count++;
        }
    }
    return count;
}

int main() {
    ifstream in("crypt1.in");
    ofstream out("crypt1.out");
    int n;
    vector<int> digits;

    in >> n;
    for (int i = 0; i < n; i++) {
        int d;
        in >> d;
        digits.push_back(d);
    }
    sort(ALL(digits));

    int work = 0;
    for (int i = 0; i < n * n * n; i++) {
        int a = digits[i / (n * n)];
        int b = digits[(i % (n * n)) / n];
        int c = digits[i % n];
        // cout << i / (n * n) << (i % (n * n)) / n << i % n << endl;
        // cout << a << b << c << endl;
        work += test(100 * a + 10 * b + c, digits);
    }
    cout << work << endl;
    out << work << endl;
    return 0;
}