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

    int n; cin >> n;
    vector<int> par(n + 1);
    vector<int> size(n + 1, 0);
    vector<vector<int>> adj(n + 1);
    FOR (i, 2, n) cin >> par[i];
    FOR (i, 1, n) adj[par[i]].push_back(i);

    function<int(int)> dfs = [&](int u) -> int {
        for (int x : adj[u]) size[u] += dfs(x);
        return 1 + size[u];
    };
    dfs(1);
    FOR (i, 1, n) cout << size[i] << " ";
    cout << endl;

    return 0;
}
