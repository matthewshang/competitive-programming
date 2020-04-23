#include "bits/stdc++.h"
using namespace std;

int main() {
    vector<int> v = {1, 2, 3, 4};
    for (int x : v) {
        // cout << "testing " << test << endl;
        // cout << "    __builtin_popcount = " << __builtin_popcount(test) << endl;
        // cout << "    __lg = " << __lg(test) << endl;
        int y = x - (__lg(x) + 1);
        cout << "testing x = " << x << endl;
        cout << "    __lg(x) = " << __lg(x) << endl;
        cout << "    y = x - __lg(x) - 1 = " << y << endl;
        cout << "    __lg(y) = " << __lg(y) << endl;
        cout << "    __builtin_popcount(y) = " << __builtin_popcount(y) << endl;
        cout << "    y + __lg(y) + 1 - __builtin_popcount(y) = " << (y + __lg(y) + 1 - __builtin_popcount(y)) << endl;
    }
}