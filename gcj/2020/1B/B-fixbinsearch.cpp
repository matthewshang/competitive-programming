#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using vi = vector<int>;
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

#define FOR(i, a, b) for (int i=(a); i <=(b); i++)
#define F0R(i, a) for (int i=0; i < (a); i++)
#define RFOR(i, a, b) for (int i = (a); i >= b; i--)

const char nl = '\n';
const ll MOD = 1e9 + 7;
const ll INF = 1e18;

// 0 = miss, 1 = hit, 2 = center
int query(ll x, ll y) {
    cout << x << " " << y << endl;
    string res; cin >> res;
    if (res == "CENTER") return 2;
    else if (res == "HIT") return 1;
    else return 0;
}

const int STEP = 10;
const ll N = 2e9;
const ll M = 1e9;

ll A, B;

bool solve() {
    ll x = -1, y = -1;
    FOR (i, -STEP / 2, STEP / 2) {
        FOR (j, -STEP / 2, STEP / 2) {
            ll x_ = (ll)floor(i * ((double)N / (double)(STEP + 1)));
            ll y_ = (ll)floor(j * ((double)N / (double)(STEP + 1)));
            int res = query(x_, y_);
            if (res == 2) {
                return true;
            } else if (res == 1) {
                x = x_;
                y = y_;
                break;
            }
        }
        if (x != -1) break;
    }
    assert(x != -1);

    ll last = 3e9;
    ll lo = x, hi = M;
    while (lo < hi) {
        ll mid = lo + (hi - lo + 1) / 2;
        int res = query(mid, y);
        if (res == 2) {
            return true;
        } else if (res == 1) {
            lo = mid;
        } else {
            hi = mid - 1;
        }
    }
    ll R = lo;
    
    lo = -M;
    hi = x;
    while (lo < hi) {
        ll mid = lo + (hi - lo) / 2;
        int res = query(mid, y);
        if (res == 2) {
            return true;
        } else if (res == 1) {
            hi = mid;
        } else {
            lo = mid + 1;
        }
    }
    ll L = hi;

    lo = y;
    hi = M;
    while (lo < hi) {
        ll mid = lo + (hi - lo + 1) / 2;
        int res = query(x, mid);
        if (res == 2) {
            return true;
        } else if (res == 1) {
            lo = mid;
        } else {
            hi = mid - 1;
        }
    }
    ll U = lo;

    lo = -M;
    hi = y;
    while (lo < hi) {
        ll mid = lo + (hi - lo) / 2;
        int res = query(x, mid);
        if (res == 2) {
            return true;
        } else if (res == 1) {
            hi = mid;
        } else {
            lo = mid + 1;
        }
    }
    ll D = hi;
    
    return query((L + R) / 2, (U + D) / 2) == 2;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);

    int t; cin >> t;
    cin >> A >> B;
    FOR (i, 1, t) {
        if (!solve()) {
            return 0;
        }
    }

    return 0;
}
