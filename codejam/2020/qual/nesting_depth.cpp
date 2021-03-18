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

void solve() {
    string s; cin >> s;
    int n = s.size();
    string ans = "";
    int last = 0;
    F0R (i, n) {
        int cur = s[i] - '0';
        if (cur > last) {
            F0R (j, cur - last) ans += '(';
        } else if (cur < last) {
            F0R (j, last - cur) ans += ')';
        }
        ans += s[i];
        last = cur;
    }
    if (last > 0) F0R (j, last) ans += ')';
    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    int t; cin >> t;
    FOR (i, 1, t) {
        cout << "Case #" << i << ": ";
        solve();
    }

    return 0;
}
