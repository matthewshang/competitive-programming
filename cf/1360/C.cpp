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

    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vi c(101, 0);
        F0R (i, n) {
            int a; cin >> a;
            c[a]++;
        }

        int e = 0, o = 0;
        FOR (i, 1, 100) {
            if (i % 2)
                o += c[i];
            else 
                e += c[i];
        }
        bool ok = true;
        if (e % 2 != o % 2) {
            ok = false;
        } else if (e % 2 == 1 && o % 2 == 1) {
            ok = false;
            FOR (i, 1, 99) {
                if (c[i] && c[i + 1])
                    ok = true;
            }
        }
        cout << (ok ? "YES" : "NO") << nl;

    }

    return 0;
}
