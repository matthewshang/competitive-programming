#include <bits/stdc++.h>
using namespace std;

// Open kactl.

using ll = long long;
using ull = unsigned long long;
ull sumsq(ull to) { return to / 2 * ((to-1) | 1); }
/// ^ written in a weird way to deal with overflows correctly

ull divsum(ull to, ull c, ull k, ull m) {
	ull res = k / m * sumsq(to) + c / m * to;
	k %= m; c %= m;
	if (!k) return res;
	ull to2 = (to * k + c) / m;
	return res + (to - 1) * to2 - divsum(to2, m-1 - c, m, k);
}

ll modsum(ull to, ll c, ll k, ll m) {
	c = ((c % m) + m) % m;
	k = ((k % m) + m) % m;
	return to * c + k * sumsq(to) - m * divsum(to, c, k, m);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int W;
    cin >> W;
    while (W--) {
        int p, q, n;
        cin >> p >> q >> n;
        cout << modsum(n + 1, 0, p, q) << '\n';
    }

    return 0;
}