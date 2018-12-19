/*
ID: mshang41
LANG: C++11
TASK: dualpal
*/

#include "bits/stdc++.h"

using namespace std;

string base(int n, int b) {
    string s;

    while (n > 0) {
        s += '0' + n % b;
        n /= b;
    }
    reverse(s.begin(), s.end());
    return s;
}

bool ispal(const string &s) {
    for (int i = 0; i < s.length() / 2; i++) {
        if (s[i] != s[s.length() - i - 1])
            return false;
    }
    return true;
}

int main() {
    ifstream input("dualpal.in");
    ofstream output("dualpal.out");
    int N, S;
    input >> N >> S;
    // int N = 3;
    // int S = 25;

    while (N > 0) {
        S++;
        int b = 2;
        int i = 0;
        while (i < 2 && b <= 10) {
            if (ispal(base(S, b))) {
                i++;
            }
            b++;
        }
        if (i == 2) {
            N--;
            output << S << endl;
        }
    }
    return 0;
}