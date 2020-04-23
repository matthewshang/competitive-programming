#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using vi = vector<int>;
using vvi = vector<vector<int>>;
using vl = vector<long long>;
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

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    int n, x; cin >> n >> x;
    vi a(n);
    F0R (i, n) cin >> a[i];

    // map<ll, int> count;
    // ll ans = 0, pre = 0;
    // F0R (i, n) {
    //     pre += a[i];
    //     if (pre == x) ans++;
    //     if (auto it = count.find(pre - x); it != count.end()) ans += it->second;
    //     count[pre]++;
    // }
    // cout << ans << '\n';

    vl pre(n + 1);
    pre[0] = 0;
    F0R (i, n) pre[i + 1] = pre[i] + a[i];
    map<ll, int> count;
    F0R (i, n) count[pre[i + 1]]++;
    ll ans = 0;
    F0R (i, n) {
        // if (pre[i + 1] == x) ans++;
        ans += count[x + pre[i]];
        if (count[pre[i + 1]] > 0) count[pre[i + 1]]--;
        // cout << i << ": " << ans << endl;
    }
    cout << ans << '\n';

    return 0;
}
