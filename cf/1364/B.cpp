#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using vi = vector<int>;
using vb = vector<bool>;
using vvi = vector<vector<int>>;
using vll = vector<long long>;
using vpi = vector<pair<int, int>>;
using pii = pair<int, int>;
using pll = pair<long long, long long>;

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

void solve() {
    int n; cin >> n;
    vi p(n); F0R (i, n) cin >> p[i];

    int M = 0;
    F0R (i, n - 1) M += abs(p[i] - p[i + 1]);
    vb need(n, true);
    FOR (i, 1, n - 2) {
        if (p[i - 1] < p[i] && p[i] < p[i + 1]) need[i] = false;
        if (p[i - 1] > p[i] && p[i] > p[i + 1]) need[i] = false;
    }
    int k = 0;
    F0R (i, n) if (need[i]) k++;
    cout << k << nl;
    F0R (i, n) if (need[i]) cout << p[i] << " ";
    cout << nl;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);

    int t; cin >> t;
    while (t--) solve();

    return 0;
}
