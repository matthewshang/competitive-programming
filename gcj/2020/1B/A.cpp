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

void solve() {
    int x, y; cin >> x >> y;
    bool xp = x >= 0, yp = y >= 0;
    if (x < 0) x = -x;
    if (y < 0) y = -y;
    if ((x + y) % 2 == 0) {
        cout << "IMPOSSIBLE\n";
        return;
    }

    string ans = "";
    while (!(x == 0 && y == 0)) {
        if (x == 1 && y == 0) {
            ans += "E";
            break;
        } else if (x == -1 && y == 0) {
            ans += "W";
            break;
        } else if (y == 1 && x == 0) {
            ans += "N";
            break;
        } else if (y == -1 && x == 0) {
            ans += "S";
            break;
        }

        if (x % 2) {
            if (((x - 1) / 2) % 2 == (y / 2) % 2) {
                ans += "W";
                x = (x + 1) / 2;
            } else {
                ans += "E";
                x = (x - 1) / 2;
            }
            y /= 2;
        } else {
            if (((y - 1) / 2) % 2 == (x / 2) % 2) {
                ans += "S";
                y = (y + 1) / 2;
            } else {
                ans += "N";
                y = (y - 1) / 2;
            }
            x /= 2;
        }
        // cout << x << " " << y << endl;
    }
    F0R (i, sz(ans)) {
        if (!xp) {
            if (ans[i] == 'E') ans[i] = 'W';
            else if (ans[i] == 'W') ans[i] = 'E';
        }
        if (!yp) {
            if (ans[i] == 'N') ans[i] = 'S';
            else if (ans[i] == 'S') ans[i] = 'N';
        }
    }
    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);

    int t; cin >> t;
    FOR (i, 1, t) {
        cout << "Case #" << i << ": ";
        solve();
    }

    return 0;
}
