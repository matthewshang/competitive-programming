/*
ID: mshang41
LANG: C++11
TASK: combo
*/

#include "bits/stdc++.h"

using namespace std;

int n, c[3], m[3];

bool test_combo(int test[3], int combo[3]) {
    for (int i = 0; i < 3; i++) {
        if (abs(test[i] - combo[i]) > 2 &&
            abs(-test[i] + n + combo[i]) > 2 &&
            abs(test[i] + n - combo[i]) > 2) {
                return false;
        } 
    }
    return true;
}

int main() {
    ifstream in("combo.in");
    ofstream out("combo.out");
    in >> n >> c[0] >> c[1] >> c[2] >> m[0] >> m[1] >> m[2];

    int count = 0;
    int test[3];
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            for (int k = 1; k <= n; k++) {
                test[0] = i; test[1] = j; test[2] = k;
                if (test_combo(test, c) || test_combo(test, m)) {
                    cout << i << ", " << j << ", " << k << endl;
                    count++;
                }
            }
        }
    }
    cout << count << endl;
    out << count << endl;
    return 0;
}