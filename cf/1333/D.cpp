#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using vi = vector<int>;
using vvi = vector<vector<int>>;
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

    int n, k; cin >> n >> k;
    string s; cin >> s;
    
    int inv = 0, r = 0;
    F0R (i, n) {
        if (s[i] == 'R') r++;
        if (s[i] == 'L') inv += r;
    }
    if (k > inv) {
        cout << -1 << endl;
        return 0;
    }

    vvi pos;
    int inv2 = inv;
    while (inv2 > 0) {
        pos.emplace_back();
        F0R (i, n - 1) {
            if (s[i] == 'R' && s[i + 1] == 'L') {
                pos.back().pb(i);
                inv2--;
            }
        }
        for (int i : pos.back()) swap(s[i], s[i + 1]);
    }

    if (k < sz(pos)) {
        cout << -1 << endl;
        return 0;
    }

    vi pr(sz(pos), 1);
    int need = sz(pos);
    F0R (i, sz(pos)) {
        int aba = k - need;
        if (aba < sz(pos[i])) {
            pr[i] += aba;
            break;
        } else {
            need += sz(pos[i]) - 1;
            pr[i] = sz(pos[i]);
        }
    }
    F0R (i, sz(pos)) {
        F0R (j, pr[i] - 1) {
            cout << "1 " << (pos[i][j] + 1) << '\n';
        }
        cout << (sz(pos[i]) - pr[i] + 1) << " ";
        FOR (j, pr[i] - 1, sz(pos[i]) - 1) {
            cout << (pos[i][j] + 1) << " ";
        }
        cout << '\n';
    }

    return 0;
}