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
    vi a(n); F0R (i, n) cin >> a[i];

    vi b(n, -1);
    set<int> av;
    F0R (i, a[n - 1]) av.insert(i);
    FOR (i, 1, n - 1) {
        if (a[i] != a[i - 1]) {
            b[i] = a[i - 1];
            av.erase(a[i - 1]);
        }
    }
    if (a[0] == 1) {
        b[0] = 0;
        av.erase(0);
    }

    F0R (i, n) {
        if (b[i] == -1) {
            if (sz(av)) {
                auto it = av.begin();
                b[i] = *it;
                av.erase(it);
            } else {
                b[i] = 1000000;
            }
        }
    }

    F0R (i, n) cout << b[i] << " ";
    cout << nl;

    return 0;
}
