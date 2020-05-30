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

int n;
int cur_size;
int c[1000010];

int query_count(int pos) {
    int ans = 0;
    for (pos += 1; pos > 0; pos &= pos - 1) ans += c[pos - 1];
    return ans;
}

void upd_count(int pos, int delta) {
    for (; pos < n + 1; pos |= pos + 1) c[pos] += delta;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);

    int q; cin >> n >> q;
    F0R (i, n) {
        int x; cin >> x;
        upd_count(x, 1);
    }
    cur_size = n;

    F0R (_q, q) {
        int k; cin >> k;
        if (k < 0) {
            int pos = -k;
            int lo = 1, hi = n;
            while (lo < hi) {
                int m = lo + (hi - lo) / 2;
                if (query_count(m) >= pos) {
                    hi = m;
                } else {
                    lo = m + 1;
                }
            }
            upd_count(lo, -1);
            cur_size--;
        } else {
            upd_count(k, 1);
            cur_size++;
        }
    }
    if (cur_size == 0) {
        cout << "0\n";
        return 0;
    }

    FOR (i, 1, n) {
        int val = query_count(i) - query_count(i - 1);
        if (val > 0) {
            cout << i << endl;
            break;
        }
    }

    return 0;
}
