// Maximum Subarray Sum

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
    int a[n]; F0R (i, n) cin >> a[i];
    ll max_far = a[0], cur = a[0];
    FOR (i, 1, n) {
        cur = max((ll)a[i], cur + a[i]);
        max_far = max(max_far, cur);
    }
    cout << max_far << endl;
    return 0;
}
