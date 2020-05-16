#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using vi = vector<int>;
using vb = vector<bool>;
using vvi = vector<vector<int>>;
using vll = vector<long long>;
using vpi = vector<pair<int, int>>;
using pii = pair<int, int>;
using pll = pair<long long, long long>;

#define F first
#define S second
#define pb push_back
#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()

#define FOR(i, a, b) for (int i = (a); i <= (b); ++i)
#define F0R(i, a) for (int i = 0; i < (a); ++i)
#define RFOR(i, a, b) for (int i = (a); i >= (b); --i)

const char nl = '\n';
const ll MOD = 1e9 + 7;
const ll INF = 1e18;

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);

    int n; cin >> n;
    int A = 0, B = 0, C = 0;
    F0R (i, n) {
        int a, b, c; cin >> a >> b >> c;
        int nA = max(B + b, C + c);
        int nB = max(A + a, C + c);
        int nC = max(A + a, B + b);
        A = nA, B = nB, C = nC;
    }
    cout << max(A, max(B, C)) << endl;

    return 0;
}
