#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using vi = vector<int>;
using pii = pair<int, int>;
using vpi = vector<pair<int, int>>;

#define f first
#define s second
#define pb push_back
#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()

#define FOR(i, a, b) for (int i=(a); i <=(b); i++)
#define F0R(i, a) for (int i=0; i < (a); i++)
#define RFOR(i, a, b) for (int i = (a); i >= b; i--)

const ll MOD = 1e9 + 7;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    int n; cin >> n;
    vector<ll> dp(n, 0);
    F0R (i, 6) dp[i] = 1;
    FOR (i, 1, n - 1) {
        FOR (j, 1, 6) {
            if (i - j < 0) break;
            dp[i] = (dp[i] + dp[i - j]) % MOD;
        }
    }
    cout << dp[n - 1] << endl;

    return 0;
}
