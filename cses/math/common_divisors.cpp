#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using vi = vector<int>;
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

    int n; cin >> n;
    vector<int> x(n);
    F0R (i, n) cin >> x[i];
    int hi = 0;
    F0R (i, n) hi = max(hi, x[i]);
    vector<int> count(hi + 1, 0);
    F0R (i, n) count[x[i]]++;
    RFOR (i, hi, 1) {
        int j = i;
        int c = 0;
        while (j <= hi) {
            if (count[j] >= 2) {
                cout << j << endl;
                return 0;
            }
            if (count[j] == 1) c++;
            if (c >= 2) {
                cout << i << endl;
                return 0;
            }
            j += i;
        }
    }

    return 0;
}