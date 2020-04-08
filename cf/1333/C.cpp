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

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    int n; cin >> n;
    vi a(n);
    F0R (i, n) cin >> a[i];

    vector<ll> pre(n + 1);
    pre[0] = 0;
    F0R (i, n) pre[i + 1] = pre[i] + a[i];
    ll ans = 0;
    int st = 0;
    map<ll, int> idx;
    idx[0] = 1;
    FOR (i, 1, n) {
        auto it = idx.find(pre[i]);
        if (it != idx.end()) {
            int j = it->second;
            st = max(st, j);
        }
        ans += (ll)(i - st);
        idx[pre[i]] = i + 1;
    }
    cout << ans << endl;

    return 0;
}