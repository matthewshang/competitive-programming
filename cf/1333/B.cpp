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

    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vi a(n), b(n);
        F0R (i, n) cin >> a[i];
        F0R (i, n) cin >> b[i];

        int f1 = n + 1, f2 = n + 1;
        F0R (i, n) if (a[i] == 1) {
            f1 = i;
            break;
        }
        F0R (i, n) if (a[i] == -1) {
            f2 = i;
            break;
        }

        bool ok = true;
        RFOR (i, n - 1, 0) {
            if (i == f1 && b[i] > 1 || b[i] > a[i] && i < f1) {
                ok = false;
                break;
            }
            if (i == f2 && b[i] < -1 || b[i] < a[i] && i < f2) {
                ok = false;
                break;
            }
        }

        int za = 0, zb = 0;
        while (za < n && a[za] == 0) za++;
        while (zb < n && b[zb] == 0) zb++;
        if (ok) ok = za <= zb;
        if (za == zb && ok) {
            if (za < n && a[za] != b[zb]) ok = false;
        }
        cout << (ok ? "YES" : "NO") << endl;
    }

    return 0;
}