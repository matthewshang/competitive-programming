#include <bits/stdc++.h>
using namespace std;

using C = complex<double>;
using vi = vector<int>;
using vd = vector<double>;

#define rep(i, a, b) for (int i = (a); i < int(b); i++)
void fft(vector<C>& a) {
	int n = a.size(), L = 31 - __builtin_clz(n);
	static vector<complex<long double>> R(2, 1);
	static vector<C> rt(2, 1);  // (^ 10% faster if double)
	for (static int k = 2; k < n; k *= 2) {
		R.resize(n); rt.resize(n);
		auto x = polar(1.0L, acos(-1.0L) / k);
		rep(i,k,2*k) rt[i] = R[i] = i&1 ? R[i/2] * x : R[i/2];
	}
	vi rev(n);
	rep(i,0,n) rev[i] = (rev[i / 2] | (i & 1) << L) / 2;
	rep(i,0,n) if (i < rev[i]) swap(a[i], a[rev[i]]);
	for (int k = 1; k < n; k *= 2)
		for (int i = 0; i < n; i += 2 * k) rep(j,0,k) {
			C z = rt[j+k] * a[i+j+k]; // (25% faster if hand-rolled)  /// include-line
			a[i + j + k] = a[i + j] - z;
			a[i + j] += z;
		}
}
vi conv(const vd& a, const vd& b) {
	if (a.empty() || b.empty()) return {};
	vi res(a.size() + b.size() - 1);
	int L = 32 - __builtin_clz(res.size()), n = 1 << L;
	vector<C> in(n), out(n);
	copy(a.begin(), a.end(), begin(in));
	rep(i,0,b.size()) in[i].imag(b[i]);
	fft(in);
	for (C& x : in) x *= x;
	rep(i,0,n) out[i] = in[-i & (n - 1)] - conj(in[i]);
	fft(out);
	rep(i,0,res.size()) res[i] = round(imag(out[i]) / (4 * n));
	return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string A, B;
    cin >> A >> B;
    if (A == "0" || B == "0") {
        cout << 0 << '\n';
        return 0;
    }

    auto convert = [&](const string& N) -> vd {
        vd n;
        for (char d : N) {
            n.push_back(d - '0');
        }
        return n;
    };
    vd a = convert(A);
    vd b = convert(B);

    vi c = conv(a, b);
    reverse(c.begin(), c.end());
    for (int i = 0; i < int(c.size()) - 1; i++) {
        c[i + 1] += c[i] / 10;
        c[i] %= 10;
    }
    while (c.back() >= 10) {
        int next = c.back() / 10;
        c.back() %= 10;
        c.push_back(next);
    }

    string C;
    for (int i = c.size() - 1; i >= 0; i--) {
        C += c[i] + '0';
    }
    cout << C << '\n';

    return 0;
}