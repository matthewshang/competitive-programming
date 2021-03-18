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

template <typename T>
void ckmax(T& a, T b) { a = max(a, b); }

const char nl = '\n';
const ll MOD = 1e9 + 7;

void solve(int tt) {
    int n; cin >> n;
    vpi trees(n);
    F0R (i, n) cin >> trees[i].F >> trees[i].S;
    sort(all(trees));

    map<int, ll> max_here;
    F0R (i, n) {
        auto [pos, width] = trees[i];
        ll mid = max_here[pos - width] + width;
        ll right = max_here[pos] + width;
        ckmax(max_here[pos], mid);
        ckmax(max_here[pos + width], right);
    }

    ll longest = 0;
    for (auto [pos, length] : max_here) {
        ckmax(longest, length);
    }

    cout << "Case #" << tt << ": " << longest << nl;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    
    int T; cin >> T;
    FOR (tt, 1, T) {
        solve(tt);
    }

    return 0;
}
