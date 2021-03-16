#include "bits/stdc++.h"

using namespace std;

int main() {
    ios::sync_with_stdio(false); 
    cin.tie(nullptr);

    int T; cin >> T;
    for (int tc = 1; tc <= T; tc++) {
        long long L, R; cin >> L >> R;

        long long D = abs(L - R);
        long long lo = 0, hi = 2e9;
        while (lo < hi) {
            long long mid = lo + (hi - lo + 1) / 2;
            if (mid * mid + mid - 2 * D <= 0) {
                lo = mid;
            } else {
                hi = mid - 1;
            }
        }
        long long M = lo;

        if (L < R) {
            R -= (M * M + M) / 2;
        } else {
            L -= (M * M + M) / 2;
        }
        
        long long target1, target2;
        if (L < R) {
            target1 = R, target2 = L;
        } else {
            target1 = L, target2 = R;
        }

        long long ans = M;
        lo = 0, hi = 2e9;
        while (lo < hi) {
            long long mid = lo + (hi - lo + 1) / 2;
            if (mid * mid + mid * M <= target1) {
                lo = mid;
            } else {
                hi = mid - 1;
            }
        }
        ans = max(ans, M + 2 * lo - 1);
        long long left1 = target1 - (lo * lo + lo * M);

        lo = 0, hi = 2e9;
        while (lo < hi) {
            long long mid = lo + (hi - lo + 1) / 2;
            if (mid * mid + mid * M + mid <= target2) {
                lo = mid;
            } else {
                hi = mid - 1;
            }
        }
        ans = max(ans, M + 2 * lo);
        long long left2 = target2 - (lo * lo + lo * M + lo);

        if (L < R) swap(left1, left2);

        cout << "Case #" << tc << ": ";
        cout << ans << " " << left1 << " " << left2 << endl;
    }

    return 0;
}
