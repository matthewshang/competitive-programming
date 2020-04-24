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
        vi p(n);
        F0R (i, n) {
            cin >> p[i];
            p[i]--;
        }
        vi pos(n);
        F0R (i, n) pos[p[i]] = i;

        bool ok = true;
        int m = n, i = 0;
        while (i < n) {
            int j = pos[i];
            // cout << "hi " << i << " " << j << endl;
            int mo = j;
            i++; j++;
            while (j < m) {
                if (p[j] != p[pos[i]]) {
                    ok = false;
                    break;
                }
                i++; j++;
            }
            m = mo;
            if (!ok) break;
        }

        cout << (ok ? "Yes" : "No") << endl;

        // bool ok = true;
        // map<int, set<int>> m;
        // vi next(n);
        // F0R (i, n) next[i] = i + 1;
        // next[n - 1] = -1;
        // F0R (i, n) m[1].insert(i);
        // F0R (i, n) {
        //     int num = m.rbegin()->first;
        //     auto& s = m.rbegin()->second;
        //     int j = pos[p[i]];
        //     if (auto it = s.find(j); it == s.end()) {
        //         ok = false;
        //         break;
        //     } else {
        //         s.erase(it);
        //         if (!sz(s)) {  
        //             m.erase(prev(m.end()));
        //         }

        //     }
        // }

    }

    return 0;
}