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

const int MxN = 1e6;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    vector<int> si(MxN + 1, 0);
    for (int p = 2; p * p <= MxN; p++) {
        if (si[p]) continue;
        si[p] = p;
        for (int i = p * p; i <= MxN; i += p)
            if (!si[i]) si[i] = p;
    }
    FOR (i, 2, MxN) if (!si[i]) si[i] = i;

    int n; cin >> n;
    while (n--) {
        int x; cin >> x;
        int ans = 1;
        while (x > 1) {
            int e = 0, y = x;
            while (x % si[y] == 0) {
                e++;
                x /= si[y];
            }
            ans *= e + 1;
        }
        cout << ans << endl;
    }

    return 0;
}