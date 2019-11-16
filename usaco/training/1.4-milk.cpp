/*
ID: mshang41
LANG: C++11
TASK: milk
*/

#include "bits/stdc++.h"

using namespace std;

int main() {
    ifstream in("milk.in");
    ofstream out("milk.out");
    int N, M;
    in >> N >> M;

    vector<pair<int, int>> farmers;
    for (int i = 0; i < M; i++) {
        int P, A;
        in >> P >> A;
        farmers.push_back(make_pair(P, A));
    }
    sort(farmers.begin(), farmers.end());

    int c = 0;
    for (pair<int, int> f : farmers) {
        cout << "ppu: " << f.first << ", units: " << f.second << endl;
        if (N >= f.second) {
            // Doesn't fill up units
            c += f.first * f.second;
            N -= f.second;
        } else {
            c += N * f.first;
            N -= N;
        }
        cout << "N: " << N << endl;
        if (N <= 0) break;
    }
    out << c << endl;
    return 0;
}