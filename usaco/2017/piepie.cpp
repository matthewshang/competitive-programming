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

void set_io(string s) {
    freopen((s + ".in").c_str(), "r", stdin);
    #ifndef TESTING
    freopen((s + ".out").c_str(), "w", stdout);
    #endif
}

const int INF = 1e9;

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    set_io("piepie");

    int n, d; cin >> n >> d;
    vpi B(n), E(n);
    F0R (i, n) cin >> B[i].F >> B[i].S;
    F0R (i, n) cin >> E[i].F >> E[i].S;

    vpi B_sort(n), E_sort(n);
    F0R (i, n) {
        B_sort[i].F = B[i].S;
        B_sort[i].S = i;
        E_sort[i].F = E[i].F;
        E_sort[i].S = i;
    }
    sort(all(B_sort));
    sort(all(E_sort));

    queue<int> q;
    vi dist(2 * n, INF);
    F0R (i, n) {
        if (B[i].S == 0) {
            q.push(i);
            dist[i] = 1;
        }
        if (E[i].F == 0) {
            q.push(n + i);
            dist[n + i] = 1;
        }
    }

    vb vis(2 * n, false);
    while (sz(q)) {
        int x = q.front(); q.pop();
        if (vis[x]) continue;

        vis[x] = true;
        if (x < n) {
            pii look = {B[x].F, 2e9};
            int lo = upper_bound(E_sort.begin(), E_sort.end(), look) - E_sort.begin();
            if (lo == 0) continue;
            lo--;

            while (lo >= 0 && B[x].F - E_sort[lo].F <= d) {
                int u = n + E_sort[lo].S;
                if (!vis[u] && dist[u] > dist[x] + 1) {
                    dist[u] = dist[x] + 1;
                    q.push(u);
                }
                lo--;
            }
        } else {
            x -= n;
            pii look = {E[x].S, 2e9};
            int lo = upper_bound(B_sort.begin(), B_sort.end(), look) - B_sort.begin();
            if (lo == 0) continue;
            lo--;

            while (lo >= 0 && E[x].S - B_sort[lo].F <= d) {
                int u = B_sort[lo].S;
                if (!vis[u] && dist[u] > dist[n + x] + 1) {
                    dist[u] = dist[n + x] + 1;
                    q.push(u);
                }
                lo--;
            }
        }
    }

    F0R (i, n) {
        cout << (dist[i] == INF ? -1 : dist[i]) << nl;
    }

    return 0;
}
