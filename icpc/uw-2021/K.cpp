#include "bits/stdc++.h"
using namespace std;

using ull = unsigned long long;
using ll = long long;

// source: KACTL
ull modmul(ull a, ull b, ull M) {
	ll ret = a * b - M * ull(1.L / M * a * b);
	return ret + M * (ret < 0) - M * (ret >= (ll)M);
}

ull modpow(ull b, ull e, ull mod) {
	ull ans = 1;
	for (; e; b = modmul(b, b, mod), e /= 2)
		if (e & 1) ans = modmul(ans, b, mod);
	return ans;
}

bool isPrime(ull n) {
	if (n < 2 || n % 6 % 4 != 1) return (n | 1) == 3;
	ull A[] = {2, 325, 9375, 28178, 450775, 9780504, 1795265022},
	    s = __builtin_ctzll(n-1), d = n >> s;
	for (ull a : A) {   // ^ count trailing zeroes
		ull p = modpow(a%n, d, n), i = s;
		while (p != 1 && p != n - 1 && a % n && i--)
			p = modmul(p, p, n);
		if (p != n-1 && i != s) return 0;
	}
	return 1;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    ull y; cin >> y;
    if (isPrime(y)) {
        cout << "NO" << '\n';
        return 0;
    }

    constexpr int N = 100000;
    for (int k = 2; k <= floor(log2(y)); k++) {
        ull target = (ull)floor(pow((double)y, 1.0 / k));
        vector<ull> ps;
        ull start;
        if (target > N + 1) {
            start = target - N;
        } else {
            start = 2;
        }
        for (ull cand = start; cand <= target + N; cand++) {
            if (isPrime(cand)) {
                ps.push_back(cand);
            }
        }

        assert((int)ps.size() >= k);
        ull prod = 1;
        for (int i = 0; i < k; i++) {
            prod *= ps[i];
        }

        for (int i = 0; i < (int)ps.size() - k + 1; i++) {
            if (prod == y) {
                cout << "YES" << '\n';
                for (int j = i; j < i + k; j++) {
                    cout << ps[j] << ' ';
                }
                cout << '\n';
                exit(0);
            }
            prod /= ps[i];
            prod *= ps[i + k];
            if (prod > y) {
                break;
            }
        }
    }
    cout << "NO" << '\n';

    return 0;
}
