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

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);

    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        int d = (int)floor(log2(n));
        int k = max(1 << (d - 1), (1 << d) - ((1 << (d + 1)) - 1 - n));

        cout << d << endl;

        vi b;
        while (d > 0) {
            int next = n - k;
            d--;
            int next_k = max(1 << (d - 1), (1 << d) - ((1 << (d + 1)) - 1 - next));
            b.pb(k - next_k);
            n = next;
            k = next_k;
        }

        while (sz(b)) {
            cout << b.back() << " ";
            b.pop_back();
        }
        cout << endl;
    }

    return 0;
}