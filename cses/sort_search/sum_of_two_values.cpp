// Sum of Two Values

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

#define FOR(i, a, b) for (int i=(a); i <=(b); i++)
#define F0R(i, a) for (int i=0; i < (a); i++)
#define RFOR(i, a, b) for (int i = (a); i >= b; i--)

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    int n, x; cin >> n >> x;
    int a[n];
    map<int, int> pos;
    F0R (i, n) {
        cin >> a[i];
        pos[a[i]] = i;
    }

    F0R (i, n) {
        if (auto it = pos.find(x - a[i]); it != pos.end() && i != it->second) {
            cout << (i + 1) << " " << (it->second + 1) << endl;
            return 0;
        }
    }
    cout << "IMPOSSIBLE\n";
    return 0;
}
