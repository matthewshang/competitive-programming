/*
ID: mshang41
LANG: C++11
TASK: transform
*/

#include "bits/stdc++.h"

using namespace std;

struct Pat {
    int n;
    vector<bool> d;

    static Pat make(int n, ifstream &input) {
        Pat p(n);
        for (int r = 0; r < n; r++) {
            string line;
            input >> line;
            for (int c = 0; c < n; c++) {
                char l = line[c];
                p.set(r, c, l == '@');
            }
        }
        return p;
    }

    Pat(int _n) : n(_n) {
        for (int i = 0; i < n * n; i++) {
            d.push_back(false);
        }
    }

    Pat(const Pat &p) {
        n = p.n;
        d = p.d;
    }

    void set(int r, int c, bool v) { d[r * n + c] = v; }

    bool get(int r, int c) { return d[r * n + c]; }

    void rot90() {
        for (int d = 0; d < n / 2; d++) {
            int s = n - 2 * d;
            for (int i = 0; i < s - 1; i++) {
                bool tmp = get(d, i + d);
                set(d, i + d, get(s - i - 1 + d, d));
                set(s - i - 1 + d, d, get(s - 1 + d, s - i - 1 + d));
                set(s - 1 + d, s - i - 1 + d, get(i + d, s - 1 + d));
                set(i + d, s - 1 + d, tmp);
            }
        }
    }

    void refl() {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n / 2; j++) {
                bool tmp = get(i, j);
                set(i, j, get(i, n - j - 1));
                set(i, n - j - 1, tmp);
            }
        }
    }

    bool operator==(const Pat &p) { return p.d == d; }

    void print() {
        for (int r = 0; r < n; r++) {
            for (int c = 0; c < n; c++) {
                cout << get(r, c) ? '@' : '-';
            }
            cout << endl;
        }
        cout << endl;
    }
};

int test(Pat &p, Pat &goal) {
    Pat copy = p;
    copy.rot90();
    if (copy == goal) return 1;
    copy.rot90();
    if (copy == goal) return 2;
    copy.rot90();
    if (copy == goal) return 3;

    copy = p;
    copy.refl();
    copy.print();
    if (copy == goal) return 4;
    for (int i = 0; i < 3; i++) {
        copy.rot90();
        copy.print();
        if (copy == goal) return 5;
    }
    if (p == goal) return 6;

    return 7;
}

int main() {
    ifstream input("transform.in");
    int n;
    input >> n;

    Pat pat = Pat::make(n, input);
    Pat goal = Pat::make(n, input);
    int t = test(pat, goal);
    cout << t << endl;

    ofstream output("transform.out");
    output << t << endl;

    return 0;
}