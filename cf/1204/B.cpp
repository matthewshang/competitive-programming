#include "bits/stdc++.h"

using namespace std;

using ll = long long;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    ll n, l, r; cin >> n >> l >> r;
    ll a = (1LL << l) - 1 + n - l;
    ll b = (1LL << r) - 1 + (n - r) * (1LL << (r - 1));
    cout << a << " " << b << endl;

    return 0;
}
