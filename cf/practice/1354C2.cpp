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
const double PI = acos(-1);

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);

    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        double A = PI * (2 * n - 2) / (2.0 * n);
        double C = 0.5 / cos(0.5 * A);
        int k = n / 2;
        double B = 0.5 * (k * PI - (k - 1) * (2 * PI - A) - 0.5 * PI);
        double theta = PI * k / n;
        double X = C * C * cos(theta);
        double S = sqrt(C * C + X) + sqrt(C * C - X);
        cout << fixed << setprecision(6) << S << endl;
    }
    return 0;
}
