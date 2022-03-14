#include <bits/stdc++.h>
using namespace std;

/* Date: 2022-03-05
 * Source: PACNW 2022
 * Notes: Use linear system solver to get probability of ending at either end
 * of [-a,a] if starting at b. Bitmask DP.
 */

using vd = vector<double>;
using vi = vector<int>;
const double eps = 1e-12;
#define sz(x) (int(x.size()))
#define all(x) x.begin(),x.end()
#define rep(i, a, b) for (int i = (a); i < (b); i++)

// Source: KACTL
int solveLinear(vector<vd>& A, vd& b, vd& x) {
	int n = sz(A), m = sz(x), rank = 0, br, bc;
	if (n) assert(sz(A[0]) == m);
	vi col(m); iota(all(col), 0);

	rep(i,0,n) {
		double v, bv = 0;
		rep(r,i,n) rep(c,i,m)
			if ((v = fabs(A[r][c])) > bv)
				br = r, bc = c, bv = v;
		if (bv <= eps) {
			rep(j,i,n) if (fabs(b[j]) > eps) return -1;
			break;
		}
		swap(A[i], A[br]);
		swap(b[i], b[br]);
		swap(col[i], col[bc]);
		rep(j,0,n) swap(A[j][i], A[j][bc]);
		bv = 1/A[i][i];
		rep(j,i+1,n) {
			double fac = A[j][i] * bv;
			b[j] -= fac * b[i];
			rep(k,i+1,m) A[j][k] -= fac*A[i][k];
		}
		rank++;
	}

	x.assign(m, 0);
	for (int i = rank; i--;) {
		b[i] /= A[i][i];
		x[col[i]] = b[i];
		rep(j,0,i) b[j] -= A[j][i] * b[i];
	}
	return rank; // (multiple solutions if rank < m)
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<double> p(n);
    for (int i = 0; i < n; i++) {
        cin >> p[i];
    }
    vector<int> s(n);
    for (int i = 0; i < n; i++) {
        cin >> s[i];
    }

    // array<array<vector<double>, 300>, 20> memo{};
    // array<array<bool, 300>, 20> saved{};
    array<array<vector<double>, 300>, 20> memo;
    array<array<bool, 300>, 20> saved;
    for (int i = 0; i < 300; i++) {
        for (int j = 0; j < 20; j++) {
            saved[i][j] = false;
        }
    }

    auto prob = [&](int who, int thres, int start) -> double {
        if (saved[who][thres]) {
            return memo[who][thres][thres + start];
        }

        const int k = 2 * thres + 1;
        vector<vector<double>> A(k, vector<double>(k));
        for (int i = -thres + 1; i <= thres - 1; i++) {
            // (1 - p) * s[i-1] + p * s[i+1] - s[i] = 0
            if (i - 1 >= -thres) {
                A[thres + i][thres + i - 1] = 1 - p[who];
            }
            if (i + 1 <= thres) {
                A[thres + i][thres + i + 1] = p[who];
            }
            A[thres + i][thres + i] = -1;
        }
        vector<double> b(k);
        // s[thres] = 1, s[-thres] = 0
        A[thres + thres][thres + thres] = 1;
        b[thres + thres] = 1;
        A[thres - thres][thres - thres] = 1;
        memo[who][thres].resize(k);
        int res = solveLinear(A, b, memo[who][thres]);

        assert(res != -1);
        saved[who][thres] = true;
        return memo[who][thres][thres + start];
    };

    vector<vector<double>> dp(1 << n, vector<double>(n));
    for (int mask = 1; mask < (1 << n); mask++) {
        int on = 0;
        for (int i = 0; i < n; i++) {
            if (mask & (1 << i)) {
                on++;
            }
        }
        const int thres = s[on - 1];
        for (int cur = 0; cur < n; cur++) {
            if ((mask & (1 << cur)) == 0) continue;
            if (on == 1) {
                dp[mask][cur] = prob(cur, thres, 0);
                break;
            }
            
            const int old_thres = s[on - 2];
            const int old_mask = mask ^ (1 << cur);
            for (int last = 0; last < n; last++) {
                if ((mask & (1 << last)) == 0) continue;
                double last_p = dp[old_mask][last];
                dp[mask][cur] = max(dp[mask][cur], 
                        prob(cur, thres, old_thres) * last_p
                        + prob(cur, thres, -old_thres) * (1.0 - last_p));
            }
        }
    }

    double best = 0;
    for (int i = 0; i < n; i++) {
        best = max(best, dp[(1 << n) - 1][i]);
    }
    cout << fixed << setprecision(6) << best << "\n";

    return 0;
}