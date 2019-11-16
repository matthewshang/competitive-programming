/*
ID: mshang41
LANG: C++11
TASK: palsquare
*/

#include "bits/stdc++.h"

using namespace std;

string base(int n, int b) {
    int pow = b;
    while (pow * b <= n) {
        pow *= b;
    }

    string str;
    while (n > 0) {
        int d = n / pow;
        if (d > 9) {
            str += 'A' + d - 10;
        } else {
            if (!(d == 0 && str.length() == 0)) str += '0' + d;
        }
        n -= d * pow;
        pow /= b;
    }
    while (pow > 0) {
        str += '0';
        pow /= b;
    }
    return str;
}

bool palin(string &s) {
    for (int i = 0; i < s.length() / 2; i++) {
        if (s[i] != s[s.length() - i - 1]) return false;
    }
    return true;
}

int main() {
    ifstream input("palsquare.in");
    ofstream output("palsquare.out");
    int B;
    input >> B;

    // cout << base(5, 7) << endl;

    for (int n = 1; n <= 300; n++) {
        int sq = n * n;
        string s = base(sq, B);
        if (palin(s)) {
            // cout << n << " s: " << s << endl;
            output << base(n, B) << " " << s << endl;
        }
    }
    return 0;
}