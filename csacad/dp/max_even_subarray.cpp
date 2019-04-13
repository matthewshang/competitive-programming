#include "bits/stdc++.h"

using namespace std;

#define fi first
#define se second
#define F0R(i, n) for (int i = 0; i < (n); ++i)
#define FOR(i, a, n) for (int i = (a); i < (n); ++i)
#define F0Rd(i, a) for (int i = (a); i >= 0; --i)

typedef pair<int, int> pii;
typedef vector<int> vi;
typedef long long LL;

namespace io {
    void pr(const vi &v) {
        F0R (i, v.size()) cout << v[i] << " ";
        cout << endl;
    }

    template <typename T> void pr(T *arr, int n) {
        F0R (i, n) cout << arr[i] << " ";
        cout << endl;
    }
}

int main() {
    int N; cin >> N;
    int a[N]; F0R (i, N) cin >> a[i];

    LL dp[N]; F0R (i, N) dp[i] = 0;
    LL ans = a[0] + a[1];
    dp[1] = ans;
    FOR (i, 2, N) {
        LL sum = a[i - 1] + a[i];
        dp[i] = max(sum, sum + dp[i - 2]);
        ans = max(ans, dp[i]);
    }
    cout << ans << endl;
    return 0;
}
