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
const int INF = 1e9;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    int n, x; cin >> n >> x;
    vector<int> c(n);
    F0R (i, n) cin >> c[i];
    vector<int> dp(x + 1, INF);
    dp[0] = 0;
    FOR (i, 1, x) {
        F0R (j, n) {
            if (i < c[j]) continue;
            dp[i] = min(dp[i], 1 + dp[i - c[j]]);
        }
    }
    cout << (dp[x] == INF ? -1 : dp[x]) << endl;
    return 0;
}