#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using vi = vector<int>;
using vvi = vector<vector<int>>;
using vl = vector<long long>;
using pii = pair<int, int>;
using vpi = vector<pair<int, int>>;

#define f first
#define s second
#define pb push_back
#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()

#define FOR(i, a, b) for (int i=(a); i <=(b); i++)
#define F0R(i, a) for (int i=0; i < (a); i++)
#define RFOR(i, a, b) for (int i = (a); i >= b; i--)

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    int n, x; cin >> n >> x;
    vi a(n);
    F0R (i, n) cin >> a[i];
    map<int, int> pos;
    F0R (i, n) pos[a[i]] = i;
    FOR (i, 1, n - 1) {
        F0R (j, i) {
            int now = a[i] + a[j];
            auto it = pos.find(x - now);
            if (it != pos.end() && it->second != i && it->second != j) {
                cout << (i + 1) << " " << (j + 1) << " " << (it->second + 1) << '\n';
                return 0;
            }
        }
    }
    cout << "IMPOSSIBLE\n";

    return 0;
}
