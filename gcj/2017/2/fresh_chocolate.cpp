#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using vi = vector<int>;
using vb = vector<bool>;
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

#define FOR(i, a, b) for (int i = (a); i <= (b); ++i)
#define F0R(i, a) for (int i = 0; i < (a); ++i)
#define RFOR(i, a, b) for (int i = (a); i >= (b); --i)

const char nl = '\n';
const ll MOD = 1e9 + 7;
const ll INF = 1e18;

void solve() {
    int n, p; cin >> n >> p;
    vi count(p, 0);
    F0R (i, n) {
        int g; cin >> g;
        count[g % p]++;
    }

    int ans = 0;
    ans += count[0];
    if (p == 2) {
        ans += (1 + count[1]) / 2;
    } else if (p == 3) {
        int m = min(count[1], count[2]);
        ans += m;
        count[1] = max(0, count[1] - m);
        count[2] = max(0, count[2] - m);
        ans += count[1] / 3 + count[2] / 3;
        count[1] %= 3;
        count[2] %= 3;
        if (count[1] > 0 || count[2] > 0) 
            ans += 1;
    } else {
        // 2 2, 1 3, 1 1 2, 3 3 2, 1 1 1 1, 3 3 3 3
        ans += count[2] / 2;
        count[2] %= 2;
        int m = min(count[1], count[3]);
        ans += m;
        count[1] = max(0, count[1] - m);
        count[3] = max(0, count[3] - m);
        if (count[2] == 1) {
            if (count[1] >= 2) {
                ans += 1;
                count[1] -= 2;
                count[2] -= 1;
            } else if (count[3] >= 2) {
                ans += 1;
                count[3] -= 2;
                count[2] -= 1;
            }
        }
        ans += count[1] / 4 + count[3] / 4;
        count[1] %= 4;
        count[3] %= 4;
        if (count[1] > 0 || count[3] > 0 || count[2] > 0)
            ans += 1;
    }
    cout << ans << endl;

}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);

    int T; cin >> T;
    FOR (t, 1, T) {
        cout << "Case #" << t << ": ";
        solve();
    }

    return 0;
}
