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
    int n, L; cin >> n >> L;
    vi c(L);
    int extra = n;
    F0R (i, L) {
        cin >> c[i];
        extra -= c[i];
    }
    vector<bool> good(n);
    vi need(n, 1e9);
    bool possible = false;
    F0R (i, n) {
        double div = i * 100.0 / n;
        good[i] = (div - floor(div)) >= 0.5;
        if (good[i]) possible = true;
    }

    int mini = -1;
    int ans = 0;
    if (possible) {
        int last = -1;
        F0R (i, n) if (good[i]) {
            last = i;
            break;
        }
        mini = last;
        last += n;
        RFOR (i, n - 1, 0) {
            if (good[i]) {
                last = i;
                need[i] = 0;
            } else {
                need[i] = last - i;
            }
        }
    }

    auto inc = [&](int val) {
        ans += round(100.0 * (double)val / (double)n);
    };

    vpi ord;
    F0R (i, L) {
        if (need[c[i]] == 0) {
            inc(c[i]);
        } else if (need[c[i]] < mini) {
            ord.pb({ need[c[i]], i });
        } else {
            inc (c[i]);
        }
    }
    sort(all(ord));
    F0R (i, sz(ord)) {
        if (ord[i].F <= extra) {
            extra -= ord[i].F;
            inc(c[ord[i].S] + ord[i].F);
        } else {
            inc(c[ord[i].S]);
        }
    }
    if (possible) {
        ans += extra / mini * round(100.0 * (double)mini / (double)n);
        inc(extra % mini);
    } else {
        inc(extra);
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
