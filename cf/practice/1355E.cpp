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
const ll INF = 1e18;

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);

    // f(t) = min cost to make all equal to t
    // L(t) = # < than t, G(t) = # > than t
    // if (A + R < M) f(t) = A * (L(t) * t - sum L(t)) + R * (G(t) * t - sum G(t))
    // else, do as many M as possible => 

    // 1) A everything to max
    // 2) R everything to min
    // 3) swap as many as possible
    // find t to minimize | (# less than t * t - sum of less than t) - (sum of greater than t - # greater than t * t) |
                    //  = | t * (n - # eq t) - (sum - # eq t * t) |
                    //  = | n * t - sum |
                    // '
    
    int N, A, R, M; cin >> N >> A >> R >> M;
    vll h(N);
    ll min_h = INF, max_h = 0;
    ll sum = 0;
    F0R (i, N) {
        cin >> h[i];
        min_h = min(min_h, h[i]);
        max_h = max(max_h, h[i]);
        sum += h[i];
    }
    sort(all(h));
    
    ll ans = INF;
    // everything to min/max
    ans = min(ans, (sum - min_h * N) * R);
    ans = min(ans, (max_h * N - sum) * A);

    // swaps
    ll t = sum / (ll)N;
    ll best_t = t;
    if (abs(N * (t + 1) - sum) < abs(N * t - sum)) {
        best_t = t + 1;
    }
    if (abs(N * (t - 1) - sum) < abs(N * best_t - sum)) {
        best_t = t - 1;
    }
    t = best_t;
    ll L = 0, G = 0;
    F0R (i, N) {
        if (h[i] < t)
            L += t - h[i];
        else if (h[i] > t)
            G += h[i] - t;
    }
    ll swap_cost = (ll)min(L, G) * min(A + R, M);
    if (L < G) {
        swap_cost += (G - L) * R;
    } else {
        swap_cost += (L - G) * A;
    }
    ans = min(ans, swap_cost);

    cout << ans << endl;

    return 0;
}
