/*
ID: mshang41
LANG: C++11
TASK: wormhole
*/

#include "bits/stdc++.h"

using namespace std;

#define pb push_back
#define mp make_pair

typedef pair<int, int> pi;
typedef vector<pi> vp;

void print_vp(const vp &v) {
    for (const pi &p : v) {
        cout << p.first << ", " << p.second << endl;
    }
}

void update(pi *indices, int n) {
}

int main() {
    ifstream input("wormhole.in");
    ofstream output("wormhole.out");
    int n;
    input >> n;

    vp holes;
    for (int i = 0; i < n; i++) {
        int x, y;
        input >> x >> y;
        holes.pb(mp(x, y));
    }
    print_vp(holes);

    pi indices[n / 2];
    for (int i = 0; i < n / 2; i++) {
        indices[i].first = i * 2;
        indices[i].second = i * 2 + 1;
    }

    while (indices[0].first == 0) {
        cout << "Indices: " << endl;
        print_vp(vp(indices, indices + n / 2));
        update(indices, n);
    }
    return 0;
}