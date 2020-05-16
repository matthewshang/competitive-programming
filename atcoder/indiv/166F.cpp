#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using vi = vector<int>;
using vb = vector<bool>;
using vvi = vector<vector<int>>;
using vll = vector<long long>;
using pii = pair<int, int>;
using pll = pair<long long, long long>;
using vpi = vector<pair<int, int>>;

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

    int n, a, b, c; cin >> n >> a >> b >> c;
    vector<string> s(n);
    F0R (i, n) cin >> s[i];

    vi choice(n);
    F0R (i, n) {
        if (s[i] == "AB") {
            if (a > b) {
                choice[i] = 1;
                a--; b++;
            } else {
                choice[i] = 0;
                a++; b--;
            }
        } else if (s[i] == "BC") {
            if (b > c) {
                choice[i] = 2;
                b--; c++;
            } else {
                choice[i] = 1;
                b++; c--;
            }
        } else {
            if (a > c) {
                choice[i] = 2;
                a--; c++;
            } else {
                choice[i] = 0;
                a++; c--;
            }
        }
        if (i < n - 1) {
            if (s[i + 1] == "AB" && a == 0 && b == 0) {
                if (s[i] == "AC") {
                    choice[i] = 0;
                    swap(a, c);
                } else {
                    choice[i] = 1;
                    swap(b, c);
                }
            } else if (s[i + 1] == "BC" && b == 0 && c == 0) {
                if (s[i] == "AC") {
                    choice[i] = 2;
                    swap(a, c);
                } else {
                    choice[i] = 1;
                    swap(a, b);
                }
            } else if (s[i + 1] == "AC" && a == 0 && c == 0) {
                if (s[i] == "AB") {
                    choice[i] = 0;
                    swap(a, b);
                } else {
                    choice[i] = 2;
                    swap(b, c);
                }
            }
        }
        if ((s[i] == "AB" && a == 0 && b == 0) ||
            (s[i] == "BC" && b == 0 && c == 0) ||
            (s[i] == "AC" && a == 0 && c == 0)) {
                cout << "No\n";
                return 0;
        }
        cout << a << ", " << b << ", " << c << nl;
    }

    cout << "Yes\n";
    F0R (i, n) cout << (char)('A' + choice[i]) << nl;

    return 0;
}
