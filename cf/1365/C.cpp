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

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);

    int n; cin >> n;
    vi a(n), b(n);
    F0R (i, n) cin >> a[i];
    F0R (i, n) cin >> b[i];

    vi pos_a(n), pos_b(n);
    F0R (i, n) {
        pos_a[a[i] - 1] = i;
        pos_b[b[i] - 1] = i;
    }

    map<int, int> count;
    F0R (i, n) {
        count[(pos_a[i] - pos_b[i] + n) % n]++;
    }

    int ans = 1;
    for (auto& it : count) {
        ans = max(ans, it.second);
    }
    cout << ans << nl;

    return 0;
}
