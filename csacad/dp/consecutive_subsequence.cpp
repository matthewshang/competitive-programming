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

// Key: exploit consecutive values. Could have also used a plain array since a[i] < 10^6
int main() {
    int N; cin >> N;
    int a[N]; F0R (i, N) cin >> a[i];

    int dp[N][2];
    unordered_map<int, int> mp;
    int ans = 0;

    F0R (i, N) dp[i][0] = dp[i][1] = 0;
    F0R (i, N) {
        if (mp.find(a[i] - 1) != mp.end()) {
            int last = mp[a[i] - 1];
            dp[i][0] = dp[last][0] + 1;
            dp[i][1] = dp[last][1] + 1;
        } else {
            dp[i][0] = 1;
            dp[i][1] = 2;
        }

        if (mp.find(a[i] - 2) != mp.end()) {
            int last = mp[a[i] - 2];
            dp[i][1] = max(dp[i][1], dp[last][0] + 2);
        }

        mp[a[i]] = i;
        ans = max(ans, max(dp[i][0], dp[i][1]));
    }
    cout << ans << endl;
    return 0;
}
