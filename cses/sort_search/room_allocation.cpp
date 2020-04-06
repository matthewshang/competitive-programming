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

#define FOR(i, a, b) for (int i=(a); i <(b); i++)
#define F0R(i, a) for (int i=0; i < (a); i++)
#define RFOR(i, a, b) for (int i = (a); i >= b; i--)

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    int n; cin >> n;
    vector<pair<pii, int>> e(2 * n);
    vector<int> room(n);
    F0R (i, n) {
        int a, b; cin >> a >> b;
        e[2 * i] = {{a, -1}, i};
        e[2 * i + 1] = {{b, 1}, i};
    }
    sort(all(e));

    set<int> av;
    int k = 0;
    F0R (i, 2 * n) {
        int t = e[i].f.f, ty = e[i].f.s, idx = e[i].s;
        if (ty == -1) {
            if (av.empty()) {
                k++;
                room[idx] = k;
            } else {
                room[idx] = *av.begin();
                av.erase(av.begin());
            }
        } else {
            av.insert(room[idx]);
        }
    }

    cout << k << endl;
    F0R (i, n) cout << room[i] << " ";
    cout << endl;

    return 0;
}
