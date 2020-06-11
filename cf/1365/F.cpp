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
        vi a(n), b(n);
        F0R (i, n) cin >> a[i];
        F0R (i, n) cin >> b[i];

        map<int, int> count_a, count_b;
        F0R (i, n) {
            count_a[a[i]]++;
            count_b[b[i]]++;
        }

        bool ok = true;
        F0R (i, n) {
            if (count_a[a[i]] != count_b[a[i]])
                ok = false;
        }
        if (n % 2 && a[n / 2] != b[n / 2])
            ok = false;
        if (!ok) {
            cout << "No" << nl;
            continue;
        }

        multiset<pii> pairs;
        F0R (i, n / 2) {
            int x = a[i];
            int y = a[n - 1 - i];
            if (x > y) swap(x, y);
            pairs.insert({ x, y });
        }

        F0R (i, n / 2) {
            int x = b[i];
            int y = b[n - 1 - i];
            if (x > y) swap(x, y);
            auto it = pairs.find({ x, y });
            if (it == pairs.end()) {
                ok = false;
                break;
            } else {
                pairs.erase(it);
            }
        }

        cout << (ok ? "Yes" : "No") << nl;
    }

    return 0;
}
