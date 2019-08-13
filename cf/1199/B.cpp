#include "bits/stdc++.h"

using namespace std;

using ll = long long;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    double h, l; cin >> h >> l;
    cout << setprecision(20) << ((h * h + l * l) / (2 * h) - h) << endl;

    return 0;
}
