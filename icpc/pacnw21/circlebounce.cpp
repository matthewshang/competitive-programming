#include <bits/stdc++.h>
using namespace std;

/* Date: 2022-03-05
 * Source: PACNW 2022
 * Notes: Can be proved through diagram inspection that the bounce angle is
 * always the same. Exponentiate rotation matrix.
 */

constexpr int MOD = 1e9 + 7;

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
};

using Mat = array<array<ModInt, 2>, 2>;

Mat matmul(Mat A, Mat B) {
    Mat R;
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            R[i][j] = 0;
            for (int k = 0; k < 2; k++) {
                R[i][j] = R[i][j] + A[i][k] * B[k][j];
            }
        }
    }
    return R;
}

Mat binpow(Mat M, int64_t n) {
    if (n == 0) {
        return {{{1, 0}, {0, 1}}};
    }
    if (n == 1) {
        return M;
    }
    Mat A = binpow(M, n / 2);
    Mat R = matmul(A, A);
    if (n % 2 == 1) {
        R = matmul(R, M);
    }
    return R;
}

int main() {
    ModInt a, b;
    cin >> a.x >> b.x;
    int64_t n;
    cin >> n;

    ModInt cosT = (a * a - b * b) / (a * a + b * b);
    ModInt sinT = (a * b * -2) / (a * a + b * b);

    Mat M{{{cosT, sinT * -1}, {sinT, cosT}}};
    Mat R = binpow(M, n + 1);
    ModInt x = R[0][0] * -1;
    cout << x.x << "\n";

    return 0;
}