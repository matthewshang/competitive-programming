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

    auto Query = [](vi& q) -> int {
        cout << "? " << sz(q);
        for (int x : q)
            cout << " " << x;
        cout << endl;
        int mx; cin >> mx;
        return mx;
    };

    auto Answer = [](vi& a) -> bool {
        cout << "!";
        for (int x : a)
            cout << " " << x;
        cout << endl;
        string res; cin >> res;
        return res == "Correct";
    };

    int t; cin >> t;
    while (t--) {
        int n, k; cin >> n >> k;
        vector<set<int>> S(k);
        F0R (i, k) {
            int c; cin >> c;
            F0R (j, c) {
                int x; cin >> x;
                S[i].insert(x);
            }
        }
        vi a(n);
        F0R (i, n)
            a[i] = i + 1;
        int mx = Query(a);

        int lo = 1, hi = n;
        while (lo < hi) {
            int m = lo + (hi - lo) / 2;
            a.clear();
            F0R (i, m)
                a.pb(i + 1);
            int mq = Query(a);
            if (mq == mx) {
                hi = m;
            } else {
                lo = m + 1;
            }
        }

        vi P(k);
        F0R (i, k) {
            bool has = S[i].count(lo) > 0;
            if (has) {
                vi q;
                F0R (j, n)
                    if (S[i].count(j + 1) == 0)  
                        q.pb(j + 1);
                P[i] = Query(q);
            } else {
                P[i] = mx;
            }
        }
        if (!Answer(P)) {
            return 0;
        }
    }

    return 0;
}
