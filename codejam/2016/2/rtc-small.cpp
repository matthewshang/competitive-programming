#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using vi = vector<int>;
using vb = vector<bool>;
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

#define FOR(i, a, b) for (int i = (a); i <= (b); ++i)
#define F0R(i, a) for (int i = 0; i < (a); ++i)
#define RFOR(i, a, b) for (int i = (a); i >= (b); --i)

const char nl = '\n';
const ll MOD = 1e9 + 7;
const ll INF = 1e18;

void solve() {
    int N, K; cin >> N >> K;
    vector<double> p(N);
    F0R (i, N) cin >> p[i];
    double best = 0;
    F0R (i, (1 << N)) {
        if (__builtin_popcount(i) != K) continue;
        vector<double> q;
        F0R (j, N) {
            if (i & (1 << j)) {
                q.pb(p[j]);
            }
        }
        double val = 0;
        F0R (j, (1 << K)) {
            if (__builtin_popcount(j) != K / 2) continue;
            double val2 = 1;
            F0R (k, K) {
                if (j & (1 << k)) val2 *= q[k];
                else val2 *= (1.0 - q[k]);
            }
            val += val2;
        }
        best = max(best, val);
    }
    cout << best << endl;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);

    int T; cin >> T;
    FOR (t, 1, T) {
        cout << "Case #" << t << ": ";
        solve();
    }

    return 0;
}
