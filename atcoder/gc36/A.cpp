#include "bits/stdc++.h"

using namespace std;

using ll = long long;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    ll S; cin >> S;
    ll a = (ll)ceil(sqrt((double)S));
    ll b = a * a - S;
    cout << "0 0 " << a << " " << b << " 1 " << a << endl;
    return 0;
}
