#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using vi = vector<int>;
using vvi = vector<vector<int>>;
using vll = vector<long long>;
using pii = pair<int, int>;
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

void solve() {
    int n; cin >> n;
    vector<string> p(n);
    F0R (i, n) cin >> p[i];

    string begin = "", mid = "", end = "";
    for (string& pat : p) {
        int i = 0;
        while (pat[i] != '*') i++;
        string s = pat.substr(0, i);
        bool ok = true;
        F0R (j, min(sz(s), sz(begin))) {
            if (begin[j] != s[j]) {
                ok = false;
                break;
            }
        }
        if (!ok) {
            cout << "*\n";
            return;
        }
        if (sz(s) > sz(begin)) begin = s;

        int j = sz(pat) - 1;
        while (pat[j] != '*') j--;

        s = pat.substr(j + 1, sz(pat) - j - 1);
        reverse(all(s));
        ok = true;
        F0R (j, min(sz(s), sz(end))) {
            if (end[j] != s[j]) {
                ok = false;
                break;
            }
        }
        if (!ok) {
            cout << "*\n";
            return;
        }
        if (sz(s) > sz(end)) end = s;

        FOR (k, i + 1, j - 1) {
            if (pat[k] != '*') mid += pat[k];
        }
    }
    reverse(all(end));
    cout << begin + mid + end << nl;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);

    int t; cin >> t;
    FOR (i, 1, t) {
        cout << "Case #" << i << ": ";
        solve();
    }

    return 0;
}