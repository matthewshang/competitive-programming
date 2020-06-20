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
    
    vpi v;
    v.pb({ 0, 0 });
    v.pb({ 1, 0 });
    v.pb({ 0, 1 });
    v.pb({ 1, 1 });
    F0R (i, n) {
        v.pb({ 2 + i, 2 + i });
        v.pb({ 2 + i, 1 + i });
        v.pb({ 1 + i, 2 + i });
    }

    cout << sz(v) << nl;
    for (auto [x, y] : v) {
        cout << x << " " << y << nl;
    }

    return 0;
}
