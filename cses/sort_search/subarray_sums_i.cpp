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

    vl pre(n + 1);
    pre[0] = 0;
    F0R (i, n) pre[i + 1] = pre[i] + a[i];
    set<ll> s;
    F0R (i, n) s.insert(pre[i + 1]);
    int ans = 0;
    F0R (i, n) {
        if (s.find(x + pre[i]) != s.end()) ans++;
    }
    cout << ans << '\n';

    return 0;
}
