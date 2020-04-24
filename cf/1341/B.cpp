#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using vi = vector<int>;
using vvi = vector<vector<int>>;
using vll = vector<long long>;
using pii = pair<int, int>;
using pll = pair<long long, long long>;
using vpi = vector<pair<int, int>>;

#define F first
#define S second
#define pb push_back
#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()

#define FOR(i, a, b) for (int i=(a); i <=(b); i++)
#define F0R(i, a) for (int i=0; i < (a); i++)
#define RFOR(i, a, b) for (int i = (a); i >= b; i--)

const char nl = '\n';
const ll MOD = 1e9 + 7;
const ll INF = 1e18;

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);

    int t; cin >> t;
    while (t--) {
        int n, k; cin >> n >> k;
        vi a(n); F0R (i, n) cin >> a[i];
        vector<bool> peak(n, false);
        FOR (i, 1, n - 2) {
            if (a[i] > a[i - 1] && a[i] > a[i + 1]) 
                peak[i] = true;
        }

        int ans = 0, cur = 0, idx = 0;
        FOR (i, 1, k - 2) {
            if (peak[i]) {
                cur++;
            }
        }
        ans = cur;
        FOR (i, k, n - 1) {
            cur -= peak[i - k + 1];
            cur += peak[i - 1];
            if (cur > ans) {
                ans = cur;
                idx = i - k + 1;
            }
        }
        cout << (ans + 1) << " " << (idx + 1) << endl;
    }

    return 0;
}