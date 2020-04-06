// Playlist

#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using vi = vector<int>;
using pii = pair<int, int>;
using vpi = vector<pair<int, int>>;

#define f first
#define s second
#define pb push_back
#define mp make_pair
#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()

#define FOR(i, a, b) for (int i=(a); i <(b); i++)
#define F0R(i, a) for (int i=0; i < (a); i++)
#define RFOR(i, a, b) for (int i = (a); i >= b; i--)

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    int n; cin >> n;
    int k[n];
    F0R (i, n) cin >> k[i];
    map<int, int> last;
    int ans = 0, idx = 0;
    F0R (i, n) {
        if (auto it = last.find(k[i]); it != last.end()) {
            idx = max(idx, it-> second + 1);
        }
        ans = max(ans, i - idx + 1);
        last[k[i]] = i;
    }
    cout << ans << endl;

    return 0;
}
