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
    int n; cin >> n;
    vector<array<int, 3>> e(2 * n); // 0: time, 1: type, 2: idx
    F0R (i, n) {
        cin >> e[2 * i][0] >> e[2 * i + 1][0];
        e[2 * i][1] = 1;
        e[2 * i][2] = i;
        e[2 * i + 1][1] = -1;
        e[2 * i + 1][2] = i;
    }
    sort(all(e));
    vector<char> ans(n);
    int C = -1, J = -1;
    F0R (i, 2 * n) {
        int t = e[i][0], ty = e[i][1], idx = e[i][2];
        if (ty == -1) {
            if (C == idx) {
                C = -1;
                ans[idx] = 'C';
             } else {
                J = -1;
                ans[idx] = 'J';
             }
        } else {
            if (C == -1) C = idx;
            else if (J == -1) J = idx;
            else {
                cout << "IMPOSSIBLE";
                return;
            }
        }
    }
    F0R (i, n) cout << ans[i];
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    int t; cin >> t;
    FOR (i, 1, t) {
        cout << "Case #" << i << ": ";
        solve();
        cout << endl;
    }

    return 0;
}
