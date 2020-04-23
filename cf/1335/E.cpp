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

void pr(int x) { cout << x; }
void pr(ll x) { cout << x; }
void pr(size_t x) { cout << x; }
void pr(const char* s) { cout << s; }
void pr(string& s) { cout << s; }
void pr(bool x) { cout << (x ? "true" : "false"); }
template <typename T1, typename T2>
void pr(const pair<T1, T2>& p) { pr("{ "); pr(p.first); pr(", "); pr(p.second); pr(" }"); }
template <typename T> 
void pr(T& v) { cout << "{"; bool f = true; for (const auto& x : v) cout << (!f ? ", " : ""), f = false, pr(x); cout << "}";}
void pd() { cout << "]" << endl; }
template <typename T, typename... U>
void pd(T first, U... rest) { pr(first); if (sizeof...(rest)) cout << ", "; pd(rest...);}
#ifdef TESTING
#define dbg(x...) cout << "[" << #x << "] = [", pd(x)
#else
#define dbg(...)
#endif

const char nl = '\n';
const ll MOD = 1e9 + 7;
const ll INF = 1e18;

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);

    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vi a(n);
        F0R (i, n) cin >> a[i];

        vvi rpos(201);
        RFOR (i, n - 1, 0) {
            rpos[a[i]].pb(i);
        }
        vector<int> count(201, 0);
        vpi want;
        vi size;
        F0R (i, n) {
            count[a[i]]++;
            if (count[a[i]] <= sz(rpos[a[i]])) {
                int idx = rpos[a[i]][count[a[i]] - 1];
                if (idx > i) {
                    want.pb({i + 1, idx});
                    size.pb(count[a[i]]);
                }
            }
        }
        if (!sz(want)) {
            cout << "1\n";
            continue;
        }
        // dbg(want);

        vvi pre(n + 1, vi(201));
        FOR (i, 1, 200) pre[0][i] = 0;
        F0R (i, n) FOR (j, 1, 200) pre[i + 1][j] = pre[i][j] + (a[i] == j);
        int ans = 0;
        F0R (i, sz(want)) {
            int mx = 0;
            FOR (j, 1, 200) mx = max(mx, pre[want[i].S][j] - pre[want[i].F][j]);
            ans = max(ans, 2 * size[i] + mx);
        }
        cout << ans << nl;
    }

    return 0;
}