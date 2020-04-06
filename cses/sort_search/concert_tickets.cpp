// Concert Tickets

#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using vi = vector<int>;
using pii = pair<int, int>;

#define f first
#define s second
#define pb push_back
#define mp make_pair
#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()

#define FOR(i, a, b) for (int i=(a); i <=(b); i++)
#define F0R(i, a) for (int i=0; i < (a); i++)
#define RFOR(i, a, b) for (int i = (a); i >= b; i--)

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    int n, m; cin >> n >> m;
    map<int, int> h;
    F0R (i, n) {
        int x; cin >> x;
        h[x]++;
    }

    F0R (i, m) {
        int t; cin >> t;
        if (!sz(h)) {
            cout << "-1\n";
            continue;
        }
        auto it = prev(h.upper_bound(t));
        if (it == h.end()) {
            cout << "-1\n";
        } else {
            cout << it->first << endl;
            it->second--;
            if (it->second == 0) {
                h.erase(it);
            }
        }
    }

    return 0;
}
