#include "bits/stdc++.h"
using namespace std;

/* Date: 2022-01-29
 * Source: UW 2022
 * Summary: Cheese with sparse matrix exponentiation.
 */

const int MOD = 1e9 + 7;

// Based on https://codeforces.com/blog/entry/85969
struct ModInt {
  int x;
  ModInt(int x = 0) : x(x + (x < 0) * MOD - (x >= MOD) * MOD) {}
  ModInt operator+(ModInt o) { return x + o.x; }
  ModInt operator-(ModInt o) { return x - o.x; }
  ModInt operator*(ModInt o) { return 1LL * x * o.x % MOD; }
  ModInt operator/(ModInt b) { return *this * b.inv(); }
  ModInt inv() { return pow(MOD - 2); }
  ModInt pow(long long e) {
    if (!e) return ModInt(1);
    ModInt r = pow(e / 2); r = r * r;
    return e % 2 ? *this * r : r;
  }
  bool operator==(ModInt o) { return x == o.x; }
};


vector<ModInt> BerlekampMassey(vector<ModInt> s) {
  int n = s.size();
  vector<ModInt> C(n), B(n);
  C[0] = B[0] = 1;

  auto b = C[0]; int L = 0;
  for (int i = 0, m = 1; i < n; ++i) {
    /// Calculate discrepancy
    auto d = s[i];
    for (int j = 1; j <= L; ++j)
      d = d + C[j] * s[i - j];
    if (d == 0) { ++m; continue; }
    /// C -= d / b * B * X^m
    auto T = C; auto coef = d / b;
    for (int j = m; j < n; ++j)
      C[j] = C[j] - coef * B[j - m];
    if (2 * L > i) { ++m; continue; }
    L = i + 1 - L; B = T; b = d; m = 1;
  }
  C.resize(L + 1); C.erase(C.begin());
  for (auto& x : C) x = x * (-1);
  return C;
}

using Poly = vector<ModInt>;

Poly LinearRec(Poly trans, int64_t k) {
  int n = trans.size(); // assert(n <= (int)first.size());
  Poly r(n + 1), b(r); r[0] = b[1] = 1;
  auto ans = b[0];

  auto combine = [&](Poly a, Poly b) { // a * b mod trans
    Poly res(n * 2 + 1);
    for (int i = 0; i <= n; ++i)
      for (int j = 0; j <= n; ++j)
        res[i + j] = res[i + j] + a[i] * b[j];
    for (int i = 2 * n; i > n; --i)
      for (int j = 0; j < n; ++j)
        res[i - 1 - j] = res[i - 1 - j] + res[i] * trans[j];
    res.resize(n + 1);
    return res;
  };
  // Consider caching the powers for multiple queries
  for (++k; k; k /= 2) {
    if (k % 2) r = combine(r, b);
    b = combine(b, b);
  }
  return r;
}

vector<ModInt> Power(int d, int64_t k, vector<ModInt> v) {
  vector<Poly> first(2 * d, Poly(d));
  first[0] = v;
  vector<ModInt> s(2 * d);
  s[0] = v[0];

  // Step 1 (optimizable to O(m * n))
  for (int i = 1; i < 2 * d; ++i) {
      for (int j = 0; j < d; j++) {
          if (j > 0) {
              first[i][j - 1] = first[i][j - 1] + first[i - 1][j];
          }
          if (j < d - 1) {
              first[i][j + 1] = first[i][j + 1] + first[i - 1][j];
          }
      }
      for (int j = 0; j < d; j++) {
          s[i] = s[i] + first[i][j];
      }
  }

  // Step 2 (O(n^2))
  auto trans = BerlekampMassey(s);
  int rec = trans.size();

  // Step 3 (O(n^2 log k))
  auto c = LinearRec(trans, k);

  // Step 4 (O(n^2))
  vector<ModInt> ans(d);
  for (int i = 0; i < d; ++i) 
    for (int j = 0; j < rec; ++j)
      ans[i] = ans[i] + c[j + 1] * first[j][i];

  return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int64_t n;
    cin >> n;
    int d;
    cin >> d;

    Poly v(2 * d + 1, 0);
    v[d] = 1;
    auto ans = Power(2 * d + 1, n, v);
    ModInt res = 0;
    for (int i = 0; i < 2 * d + 1; i++) {
        res = res + ans[i];
    }
    cout << res.x << '\n';

    return 0;
}